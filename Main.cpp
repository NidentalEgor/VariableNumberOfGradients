#include <iostream>
#include "Inc/VNG.h"

int main()
{
    VNG vng("/home/egor/Repositories/ImageProcessing/RGB_CFA.bmp");
    vng.Process();
    vng.Write("/home/egor/Repositories/ImageProcessing/test.bmp");
    return 0;
}