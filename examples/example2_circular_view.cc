#include <tf_bmp>
#include <cassert>

int main()
{
    using namespace tf::BMP;
    using PixelArray24b = PixelArray<BPP::_24bits>;

    auto pa = PixelArray24b{
        2, 3,
        {
            0x00'00'00, 0x00'00'01,
            0x00'01'00, 0x00'01'01,
            0x00'02'00, 0x00'02'01,
        }
    };

    auto view = PixelArray24b::CircularView{pa};

    assert((view[0, 0] == 0x00'00'00));
    assert((view[1, 0] == 0x00'01'00));
    assert((view[-1, 0] == 0x00'02'00));
    assert((view[0, 1] == 0x00'00'01));
    assert((view[0, -1] == 0x00'00'01));
    assert((view[0, 2] == 0x00'00'00));
    assert((view[0, 4] == 0x00'00'00));
    assert((view[0, 7] == 0x00'00'01));
    assert((view[3, 0] == 0x00'00'00));
    assert((view[6, 0] == 0x00'00'00));
    assert((view[8, 0] == 0x00'02'00));
    assert((view[7, -5] == 0x00'01'01));

    return 0;
}
