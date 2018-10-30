#include <iostream>
#include "VNG.h"

class VNGTests : public testing::Test
{
public:
    RGBApixel GetRedPixel(){ return { 0, 0, 255 }; }
    RGBApixel GetGreenPixel(){ return { 0, 255, 0 }; }
    RGBApixel GetBluePixel(){ return { 255, 0, 0 }; }

    BMP GetPictureWithCentralRed()
    {
        BMP picture;
        picture.SetSize( 5, 5 );

        picture.SetPixel( 0, 0, GetRedPixel() );
        picture.SetPixel( 0, 1, GetGreenPixel() );
        picture.SetPixel( 0, 2, GetRedPixel() );
        picture.SetPixel( 0, 3, GetGreenPixel() );
        picture.SetPixel( 0, 4, GetRedPixel() );

        picture.SetPixel( 1, 0, GetGreenPixel() );
        picture.SetPixel( 1, 1, GetBluePixel() );
        picture.SetPixel( 1, 2, GetGreenPixel() );
        picture.SetPixel( 1, 3, GetBluePixel() );
        picture.SetPixel( 1, 4, GetGreenPixel() );

        picture.SetPixel( 2, 0, GetRedPixel() );
        picture.SetPixel( 2, 1, GetGreenPixel() );
        picture.SetPixel( 2, 2, GetRedPixel() );
        picture.SetPixel( 2, 3, GetGreenPixel() );
        picture.SetPixel( 2, 4, GetRedPixel() );

        picture.SetPixel( 3, 0, GetGreenPixel() );
        picture.SetPixel( 3, 1, GetBluePixel() );
        picture.SetPixel( 3, 2, GetGreenPixel() );
        picture.SetPixel( 3, 3, GetBluePixel() );
        picture.SetPixel( 3, 4, GetGreenPixel() );

        picture.SetPixel( 4, 0, GetRedPixel() );
        picture.SetPixel( 4, 1, GetGreenPixel() );
        picture.SetPixel( 4, 2, GetRedPixel() );
        picture.SetPixel( 4, 3, GetGreenPixel() );
        picture.SetPixel( 4, 4, GetRedPixel() );

        picture.WriteToFile("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Tests/red.bmp");

        return picture;
    }

    BMP GetPictureWithCentralBlue()
    {
        BMP picture;
        picture.SetSize( 5, 5 );

        picture.SetPixel( 0, 0, GetBluePixel() );
        picture.SetPixel( 0, 1, GetGreenPixel() );
        picture.SetPixel( 0, 2, GetBluePixel() );
        picture.SetPixel( 0, 3, GetGreenPixel() );
        picture.SetPixel( 0, 4, GetBluePixel() );

        picture.SetPixel( 1, 0, GetGreenPixel() );
        picture.SetPixel( 1, 1, GetRedPixel() );
        picture.SetPixel( 1, 2, GetGreenPixel() );
        picture.SetPixel( 1, 3, GetRedPixel() );
        picture.SetPixel( 1, 4, GetGreenPixel() );

        picture.SetPixel( 2, 0, GetBluePixel() );
        picture.SetPixel( 2, 1, GetGreenPixel() );
        picture.SetPixel( 2, 2, GetBluePixel() );
        picture.SetPixel( 2, 3, GetGreenPixel() );
        picture.SetPixel( 2, 4, GetBluePixel() );

        picture.SetPixel( 3, 0, GetGreenPixel() );
        picture.SetPixel( 3, 1, GetRedPixel() );
        picture.SetPixel( 3, 2, GetGreenPixel() );
        picture.SetPixel( 3, 3, GetRedPixel() );
        picture.SetPixel( 3, 4, GetGreenPixel() );

        picture.SetPixel( 4, 0, GetBluePixel() );
        picture.SetPixel( 4, 1, GetGreenPixel() );
        picture.SetPixel( 4, 2, GetBluePixel() );
        picture.SetPixel( 4, 3, GetGreenPixel() );
        picture.SetPixel( 4, 4, GetBluePixel() );

        picture.WriteToFile("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Tests/blue.bmp");

        return picture;
    }

    BMP GetPictureWithCentralGreen()
    {
        BMP picture;
        picture.SetSize( 5, 5 );

        picture.SetPixel( 0, 0, GetGreenPixel() );
        picture.SetPixel( 0, 1, GetBluePixel() );
        picture.SetPixel( 0, 2, GetGreenPixel() );
        picture.SetPixel( 0, 3, GetBluePixel() );
        picture.SetPixel( 0, 4, GetGreenPixel() );

        picture.SetPixel( 1, 0, GetRedPixel() );
        picture.SetPixel( 1, 1, GetGreenPixel() );
        picture.SetPixel( 1, 2, GetRedPixel() );
        picture.SetPixel( 1, 3, GetGreenPixel() );
        picture.SetPixel( 1, 4, GetRedPixel() );

        picture.SetPixel( 2, 0, GetGreenPixel() );
        picture.SetPixel( 2, 1, GetBluePixel() );
        picture.SetPixel( 2, 2, GetGreenPixel() );
        picture.SetPixel( 2, 3, GetBluePixel() );
        picture.SetPixel( 2, 4, GetGreenPixel() );

        picture.SetPixel( 3, 0, GetRedPixel() );
        picture.SetPixel( 3, 1, GetGreenPixel() );
        picture.SetPixel( 3, 2, GetRedPixel() );
        picture.SetPixel( 3, 3, GetGreenPixel() );
        picture.SetPixel( 3, 4, GetRedPixel() );

        picture.SetPixel( 4, 0, GetGreenPixel() );
        picture.SetPixel( 4, 1, GetBluePixel() );
        picture.SetPixel( 4, 2, GetGreenPixel() );
        picture.SetPixel( 4, 3, GetBluePixel() );
        picture.SetPixel( 4, 4, GetGreenPixel() );

        picture.WriteToFile("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Tests/green.bmp");

        return picture;
    }
};

TEST_F( VNGTests, SimpleAddVisitTest )
{

    GetPictureWithCentralRed();
    GetPictureWithCentralGreen();
    GetPictureWithCentralBlue();

    VNG vng("/home/egor/Repositories/BayerAlgorithm/RGB_CFA.bmp");
//    vng.Process();
    ASSERT_EQ(
        true,
        true );
}