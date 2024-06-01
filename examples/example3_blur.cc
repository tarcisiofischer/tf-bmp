#include <tf_bmp>
#include <cassert>
#include <iostream>

int main()
{
    using namespace tf::BMP;
    using PixelArray24b = PixelArray<BPP::_24bits>;

    auto pa = []() {
        auto res = tf::BMP::load("../images/coffee.bmp");
        assert(res.has_value());
        assert(std::holds_alternative<PixelArray24b>(res.value()));
        return std::get<PixelArray24b>(res.value());
    }();

    auto blurred_pa = PixelArray<BPP::_24bits>{pa.width(), pa.height()};

    const auto pa_cview = PixelArray24b::ExtendedView{pa};
    for (int32_t l = 0; l < static_cast<int32_t>(pa.height()); ++l) {
        for (int32_t c = 0; c < static_cast<int32_t>(pa.width()); ++c) {
            uint32_t r = 0;
            uint32_t g = 0;
            uint32_t b = 0;
            for (int32_t x = -1; x <= 1; x++) {
                for (int32_t y = -1; y <= 1; y++) {
                    r += (pa_cview[l + x, c + y] & 0xFF'00'00) >> 16;
                    g += (pa_cview[l + x, c + y] & 0x00'FF'00) >> 8;
                    b += (pa_cview[l + x, c + y] & 0x00'00'FF) >> 0;
                }
            }
            r /= 9;
            g /= 9;
            b /= 9;
            blurred_pa[l, c] = (r << 16) | (g << 8) | (b << 0);
        }
    }

    {
        auto res = tf::BMP::save(blurred_pa, "coffee_blur.bmp");
        if (!res.has_value()) {
            switch (res.error()) {
                case tf::BMP::save_error::file_already_exists:
                    std::cout << "The file already exists on disk.\n";
                    return -1;
            }
        }
        assert(res.has_value());
    }

    return 0;
}
