#include <iostream>
#include "Inc/VNG.h"

int main()
{
    VNG vng("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Data/Input/RGB_CFA.bmp");
    vng.Process();
    vng.Write("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Data/Output/test.bmp");
    return 0;
}