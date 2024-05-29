TF-BMP
===

Pixel array and BMP file handling library in C++23.

```cpp
#include <tf_bmp>

int main()
{
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
    
    // Change a single pixel
    pa[1, 1] = 0x00'00'FF;

    // Save the result in a 24bit BMP file
    (void) tf::BMP::save(pa, "out.bmp");
}
```

**TODO List**

- Finish 1bit, 4bits, 8bits, 16bits and 32bits pixel BMP support
- Load BMP files
- 
