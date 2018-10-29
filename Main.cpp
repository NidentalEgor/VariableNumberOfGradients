#include <iostream>
#include "Inc/VNG.h"

int main()
{
    VNG vng("/home/egor/Repositories/BayerAlgorithm/RGB_CFA.bmp");
    vng.Process();
    return 0;
}