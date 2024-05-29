#include <tf_bmp>

int main()
{
    using namespace tf::BMP;

    static_assert(std::is_same<PixelArray<BPP::_1bit>::pixel_t, uint8_t>());
    static_assert(std::is_same<PixelArray<BPP::_2bits>::pixel_t, uint8_t>());
    static_assert(std::is_same<PixelArray<BPP::_4bits>::pixel_t, uint8_t>());
    static_assert(std::is_same<PixelArray<BPP::_8bits>::pixel_t, uint8_t>());
    static_assert(std::is_same<PixelArray<BPP::_16bits>::pixel_t, uint16_t>());
    static_assert(std::is_same<PixelArray<BPP::_24bits>::pixel_t, uint32_t>());
    static_assert(std::is_same<PixelArray<BPP::_32bits>::pixel_t, uint32_t>());

    return 0;
}
