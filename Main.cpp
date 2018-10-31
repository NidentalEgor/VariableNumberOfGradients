#include <chrono>
#include <iostream>
#include "Inc/VNG.h"

int main()
{
    // Linux
	//VNG vng("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Data/Input/RGB_CFA.bmp");
	VNG vng( "D://Projects//VariableNumberOfGradients//RGB_CFA.bmp" );

	const auto before = std::chrono::high_resolution_clock::now();
    vng.Process();
	const auto after = std::chrono::high_resolution_clock::now();

	const auto interval = std::chrono::duration<double>( after - before );
	typedef std::chrono::milliseconds ms;
	ms d = std::chrono::duration_cast<ms>( interval );
	std::cout << d.count() << std::endl;

    // Linux
	//vng.Write("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Data/Output/test.bmp");
    return 0;
}