#include <tf_bmp>
#include <cassert>

int main()
{
    using namespace tf::BMP;

    auto pa = PixelArray<BPP::_24bits>{
        3, 5,
        {
            0x00'00'00, 0xCA'FE'00, 0x00'FF'00,
            0xFF'00'FF, 0xFF'FF'FF, 0xCA'FE'00,
            0xAB'CD'EF, 0xCA'FE'00, 0xCA'FE'00,
            0xFF'00'FF, 0x00'FF'00, 0xCA'FE'00,
            0xFF'00'00, 0xCA'FE'00, 0xCC'CC'CC,
        }
    };
    pa[1, 1] = 0x00'00'FF;
    auto res = tf::BMP::save(pa, "out.bmp");
    assert(res.has_value());
}
