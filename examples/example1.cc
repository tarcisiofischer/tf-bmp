#include <tf_bmp>
#include <cassert>

template<typename ExceptType>
bool throws(auto callable)
{
    try {
        (void) callable();
        return false;
    } catch (ExceptType const&) {
        return true;
    } catch (...) {
        return false;
    }
}

int main()
{
    using namespace tf::BMP;
    using PixelArray24b = PixelArray<BPP::_24bits>;

    auto pa = PixelArray24b{
        3, 5,
        {
            0x00'00'00, 0xCA'FE'00, 0x00'FF'00,
            0xFF'00'FF, 0xFF'FF'FF, 0xCA'FE'00,
            0xAB'CD'EF, 0xCA'FE'00, 0xCA'FE'00,
            0xFF'00'FF, 0x00'FF'00, 0xCA'FE'00,
            0xFF'00'00, 0xCA'FE'00, 0xCC'CC'CC,
        }
    };

    assert((pa[1, 1] == 0xFF'FF'FF));
    pa[1, 1] = 0x0F'F0'0F;
    assert((pa[1, 1] == 0x0F'F0'0F));

    assert(throws<std::out_of_range>([&]() { (void) pa[0, -1]; }));
    assert(throws<std::out_of_range>([&]() { (void) pa[-1, 0]; }));
    assert(throws<std::out_of_range>([&]() { (void) pa[5, 0]; }));
    assert(throws<std::out_of_range>([&]() { (void) pa[0, 3]; }));

    auto tmpFile = std::filesystem::temp_directory_path() / "out.bmp";
    if (std::filesystem::exists(tmpFile)) {
        std::filesystem::remove(tmpFile);
    }
    auto res = tf::BMP::save(pa, tmpFile);
    assert(res.has_value());
    res = tf::BMP::save(pa, tmpFile);
    assert(res.error() == tf::BMP::save_error::file_already_exists);

    return 0;
}
