#include <iostream>
#include "VNG.h"

class VNGTests : public testing::Test
{
public:
    RGBApixel GetRedPixel(){ return { 0, 0, 255 }; }
    RGBApixel GetGreenPixel(){ return { 0, 255, 0 }; }
    RGBApixel GetBluePixel(){ return { 255, 0, 0 }; }

    BMP GetPicture32()
    {
        BMP picture;
        picture.SetSize( 3, 2 ); // w h

        picture.SetPixel( 0, 0, GetRedPixel() );
        picture.SetPixel( 0, 1, GetGreenPixel() );

        picture.SetPixel( 1, 0, GetGreenPixel() );
        picture.SetPixel( 1, 1, GetBluePixel() );

        picture.SetPixel( 2, 0, GetRedPixel() );
        picture.SetPixel( 2, 1, GetGreenPixel() );

        return picture;
    }

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

//        picture.WriteToFile("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Tests/TestData/blue.bmp");

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

//        picture.WriteToFile("/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Tests/TestData/green.bmp");

        return picture;
    }

protected:
    static const std::string input_directory;
    static const std::string output_directory;
};

const std::string VNGTests::input_directory = "/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Tests/TestData/";
const std::string VNGTests::output_directory = "/home/egor/Repositories/ImageProcessing/VariableNumberOfGradients/Tests/Output/";

TEST_F( VNGTests, RedPictureTest )
{
    VNG vng( input_directory + "red.bmp" );
    vng.Process();
    vng.Write( output_directory + "output_red.bmp" );
}

TEST_F( VNGTests, GreenPictureTest )
{
    VNG vng( input_directory + "green.bmp" );
    vng.Process();
    vng.Write( output_directory + "output_green.bmp" );
}

TEST_F( VNGTests, BluePictureTest )
{
    VNG vng( input_directory + "blue.bmp" );
    vng.Process();
    vng.Write( output_directory + "output_blue.bmp" );
}

TEST_F( VNGTests, Picture32Test )
{
    GetPicture32().WriteToFile( input_directory + "output_32.bmp" );
    std::cout << "h = " << GetPicture32().TellHeight() << " w = " << GetPicture32().TellWidth() << std::endl;

    auto pixel = GetPicture32().GetPixel( 2, 0 );
    std::cout << " (1, 2) = " << (int)pixel.Red << " " << (int)pixel.Green << " " << (int)pixel.Blue << std::endl;
//    VNG vng( input_directory + "blue.bmp" );
//    vng.Process();
//    vng.Write( output_directory + "output_blue.bmp" );
}