//
// Created by egor on 28.10.18.
//

#include <algorithm>
#include <assert.h>
#include "../Inc/VNG.h"

#define A1 picture1[i - 2][j - 2]
#define A2 picture1[i - 2][j - 1]
#define A3 picture1[i - 2][j]
#define A4 picture1[i - 2][j + 1]
#define A5 picture1[i - 2][j + 2]
#define A6 picture1[i - 1][j - 2]
#define A7 picture1[i - 1][j - 1]
#define A8 picture1[i - 1][j]
#define A9 picture1[i - 1][j + 1]
#define A10 picture1[i - 1][j + 2]
#define A11 picture1[i][j - 2]
#define A12 picture1[i][j - 1]
#define A13 picture1[i][j]
#define A14 picture1[i][j + 1]
#define A15 picture1[i][j + 2]
#define A16 picture1[i + 1][j - 2]
#define A17 picture1[i+ 1][j - 1]
#define A18 picture1[i+ 1][j]
#define A19 picture1[i+ 1][j + 1]
#define A20 picture1[i+ 1][j + 2]
#define A21 picture1[i + 2][j - 2]
#define A22 picture1[i + 2][j - 1]
#define A23 picture1[i + 2][j]
#define A24 picture1[i + 2][j + 1]
#define A25 picture1[i + 2][j + 2]

#include "../Inc/Macroses.inl"

//#define R1 picture.GetPixel.GetPixel( i - 2, j - 2 ).Red
//#define R2 picture.GetPixel(i - 2, j - 1).Red
//#define R3 picture.GetPixel( i - 2, j ).Red
//#define R4 picture.GetPixel( i - 2, j + 1 ).Red
//#define R5 picture.GetPixel( i - 2, j + 2 ).Red
//#define R6 picture.GetPixel( i - 1, j - 2 ).Red
//#define R7 picture.GetPixel( i - 1, j - 1 ).Red
//#define R8 picture.GetPixel( i - 1, j ).Red
//#define R9 picture.GetPixel( i - 1, j + 1 ).Red
//#define R10 picture.GetPixel( i - 1, j + 2 ).Red
//#define R11 picture.GetPixel( i, j - 2 ).Red
//#define R12 picture.GetPixel( i, j - 1 ).Red
//#define R13 picture.GetPixel( i, j ).Red
//#define R14 picture.GetPixel( i, j + 1 ).Red
//#define R15 picture.GetPixel( i, j + 2 ).Red
//#define R16 picture.GetPixel( i + 1, j - 2 ).Red
//#define R17 picture.GetPixel( i+ 1, j - 1 ).Red
//#define R18 picture.GetPixel( i+ 1, j ).Red
//#define R19 picture.GetPixel( i+ 1, j + 1 ).Red
//#define R20 picture.GetPixel( i+ 1, j + 2 ).Red
//#define R21 picture.GetPixel( i + 2, j - 2 ).Red
//#define R22 picture.GetPixel( i + 2, j - 1 ).Red
//#define R23 picture.GetPixel( i + 2, j ).Red
//#define R24 picture.GetPixel( i + 2, j + 1 ).Red
//#define R25 picture.GetPixel( i + 2, j + 2 ).Red



void VNG::Process() {
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            if ( i % 2 == 1 )
            {
                j % 2 == 0 ? ProcessRedPixel( i, j ) : ProcessGreenPixel( i, j );
            }
            else
            {
                j % 2 == 1 ? ProcessGreenPixel( i, j ) : ProcessBluePixel( i, j );
            }
        }
    }
}

inline uint8_t CalculateGradient(
    const uint8_t par1,
    const uint8_t par2,
    const uint8_t par3,
    const uint8_t par4,
    const uint8_t par5,
    const uint8_t par6,
    const uint8_t par7,
    const uint8_t par8,
    const uint8_t par9,
    const uint8_t par10,
    const uint8_t par11,
    const uint8_t par12 )
{
    return abs( par1 - par2 ) +
           abs( par3 - par4 ) +
           abs( par5 - par6 ) / 2 +
           abs( par7 - par8 ) / 2 +
           abs( par9 - par10 ) / 2 +
           abs( par11 - par12 ) / 2;
}



void VNG::ProcessPixel( const size_t i, const size_t j, const PixelColor pixel_color )
{
    uint8_t& R1 = picture1[i - 2][j - 2];
    uint8_t& G2 = picture1[i - 2][j - 1];
    uint8_t& R3 = picture1[i - 2][j];
    uint8_t& G4 = picture1[i - 2][j + 1];
    uint8_t& R5 = picture1[i - 2][j + 2];
    uint8_t& G6 = picture1[i - 1][j - 2];
    uint8_t& B7 = picture1[i - 1][j - 1];
    uint8_t& G8 = picture1[i - 1][j];
    uint8_t& B9 = picture1[i - 1][j + 1];
    uint8_t& G10 = picture1[i - 1][j + 2];
    uint8_t& R11 = picture1[i][j - 2];
    uint8_t& G12 = picture1[i][j - 1];
    uint8_t& R13 = picture1[i][j];
    uint8_t& G14 = picture1[i][j + 1];
    uint8_t& R15 = picture1[i][j + 2];
    uint8_t& G16 = picture1[i + 1][j - 2];
    uint8_t& B17 = picture1[i+ 1][j - 1];
    uint8_t& G18 = picture1[i+ 1][j];
    uint8_t& B19 = picture1[i+ 1][j + 1];
    uint8_t& G20 = picture1[i+ 1][j + 2];
    uint8_t& R21 = picture1[i + 2][j - 2];
    uint8_t& G22 = picture1[i + 2][j - 1];
    uint8_t& R23 = picture1[i + 2][j];
    uint8_t& G24 = picture1[i + 2][j + 1];
    uint8_t& R25 = picture1[i + 2][j + 2];

    std::array<uint8_t, 8> gradients;

    uint8_t& gradientN = gradients[0];
    uint8_t& gradientE = gradients[1];
    uint8_t& gradientS = gradients[2];
    uint8_t& gradientW = gradients[3];
    uint8_t& gradientNE = gradients[4];
    uint8_t& gradientSE = gradients[5];
    uint8_t& gradientNW = gradients[6];
    uint8_t& gradientSW = gradients[7];

    gradientN = CalculateGradient( G8, G18, R3, R13, B7, B17, B9, B19, G2, G12, G4, G14 );
    gradientE = CalculateGradient( G14, G12, R15, R13, B9, B7, B19, B17, G10, G8, G20, G18 );
    gradientS = CalculateGradient( G18, G8, R23, R13, B19, B9, B17, B7, G24, G14, G22, G12 );
    gradientW = CalculateGradient( G12, G14, R11, R13, B17, B19, B7, B9, G16, G18, G6, G8 );
    gradientNE = CalculateGradient( B9, B17, R5, R13, G8, G12, G14, G18, G4, G8, G10, G14 );
    gradientSE = CalculateGradient( B19, B7, R25, R13, G12, G18, G18, G12, G20, G14, G24, G18 );
    gradientNW = CalculateGradient( B7, B19, R1, R13, G12, G18, G8, G14, G6, G12, G2, G8 );
    gradientSW = CalculateGradient( B17, B9, R21, R13, G18, G14, G12, G10, G22, G18, G16, G12 );

    const auto min_and_max = std::minmax_element( gradients.begin(), gradients.end() );
    const auto& min = *min_and_max.first;
    const auto& max = *min_and_max.second;

    const uint8_t threshold = static_cast<uint8_t >( 1.5 * min + 0.5 * ( max - min ) );

    const auto sums = CalculateSums(
        i,
        j,
        gradients,
        threshold,
        pixel_color );

    Sums result;
    if( pixel_color == PixelColor::Red )
    {
        result.Red = A13; // R13
        result.Green = A13 + ( sums.Green - sums.Red ) / 4;
        result.Blue = A13 + ( sums.Blue - sums.Red ) / 4;
    }
    else if( pixel_color == PixelColor::Green )
    {
        result.Red = A13 + ( sums.Red - sums.Green ) / 4;
        result.Green = A13; // G13
        result.Blue = A13 + ( sums.Blue - sums.Green ) / 4;
    }
    else // PixelColor::Blue
    {
        result.Red = A13 + ( sums.Red - sums.Blue ) / 4;
        result.Green = A13 + ( sums.Green - sums.Blue ) / 4;
        result.Blue = A13; // B13
    }
}

void VNG::ProcessRedPixel(const size_t i, const size_t j)
{
    ProcessPixel( i, j, PixelColor::Red );
}

void VNG::ProcessGreenPixel(const size_t i, const size_t j)
{
    ProcessPixel( i, j, PixelColor::Green );
}

void VNG::ProcessBluePixel(const size_t i, const size_t j)
{
    ProcessPixel( i, j, PixelColor::Blue );
}

Sums VNG::CalculateSums(
    const size_t i,
    const size_t j,
    const Gradients gradients,
    const uint8_t threshold,
    const PixelColor pixel_color)
{
    for ( size_t index = static_cast<size_t >( PointsOfCompass::PointsOfCompass_First );
            index != static_cast<size_t>( PointsOfCompass::PointsOfCompass_Count );
            ++index )
    {
        if ( gradients[index] > threshold )
        {
            return CalculateSums(
                i,
                j,
                static_cast<PointsOfCompass>( index ),
                pixel_color );
        }
    }

}

inline uint8_t Average4(
    uint8_t first,
    uint8_t second,
    uint8_t third,
    uint8_t fourth)
{
    uint16_t result = ( first + second + third + fourth ) / 4;
    return static_cast<uint8_t>( result );
}

inline uint8_t Average2(
    uint8_t first,
    uint8_t second)
{
    uint16_t result = ( first + second ) / 2;
    return static_cast<uint8_t>( result );
}

Sums VNG::CalculateSums(
    const size_t i,
    const size_t j,
    const PointsOfCompass points_of_compass,
    const PixelColor pixel_color)
{
    Sums result;
    uint8_t first_color = 0;
    uint8_t second_color = 0;
    uint8_t third_color = 0;
    if ( pixel_color == PixelColor::Red ||
        pixel_color == PixelColor::Blue)
    {
        switch ( points_of_compass )
        {
            case PointsOfCompass::North:
            {
                first_color = A8;
                second_color = Average2( A7, A9 );
                third_color = Average2( A3, A13 );
            } break;

            case PointsOfCompass::East:
            {
                first_color = A14;
                second_color = Average2( A9,  A19 );
                third_color = Average2( A13, A15 );
            } break;

            case PointsOfCompass::South:
            {
                first_color = A18;
                second_color = Average2( A17, A19 );
                third_color = Average2( A13, A23 );
            } break;

            case PointsOfCompass::West:
            {
                first_color = A12;
                second_color = Average2( A7, A17 );
                third_color = Average2( A11, A13 );
            } break;

            case PointsOfCompass::NorthEast:
            {
                first_color = Average4( A4, A8, A10, A14 );
                second_color = A9;
                third_color = Average2( A13, A5 );
            } break;

            case PointsOfCompass::SouthEast:
            {
                first_color = Average4( A14, A18, A20, A24 );
                second_color = A19;
                third_color = Average2( A13, A25 );
            } break;

            case PointsOfCompass::NorthWest:
            {
                first_color = Average4( A12, A16, A18, A22 );
                second_color = A17;
                third_color = Average2( A13, A21 );
            } break;

            case PointsOfCompass::SouthWest:
            {
                first_color = Average4( A2, A6, A8, A12 );
                second_color = A7;
                third_color = Average2( A13, A1 );
            } break;

            default: assert( false );
        }

        if ( pixel_color == PixelColor::Red )
        {
            result.Red = third_color;
            result.Green = first_color;
            result.Blue = second_color;
        }
        else // central pixel is blue
        {
            result.Red = second_color;
            result.Green = first_color;
            result.Blue = third_color;
        }
    }
    else // central pixel is green
    {
        switch ( points_of_compass )
        {
            case PointsOfCompass::North:
            {
                result.Red = A8;
                result.Green = Average2( A3, A13 );
                result.Blue = Average4( A2, A4, A12, A14 );
            } break;

            case PointsOfCompass::East:
            {
                result.Red = Average4( A8, A10, A18, A20 );
                result.Green =Average2( A13, A15 );
                result.Blue = A14;
            } break;

            case PointsOfCompass::South:
            {
                result.Red = A18;
                result.Green = Average2( A13, A23 );
                result.Blue = Average4( A12, A14, A22, A24 );
            } break;

            case PointsOfCompass::West:
            {
                result.Red = Average4( A6, A8, A16, A18 );
                result.Green = Average2( A11, A13 );
                result.Blue = A12;
            } break;

            case PointsOfCompass::NorthEast:
            {
                result.Red = Average2( A8, A10 );
                result.Green = A9;
                result.Blue = Average2( A4, A14 );
            } break;

            case PointsOfCompass::SouthEast:
            {
                result.Red = Average2( A18, A20 );
                result.Green = A19;
                result.Blue = Average2( A14, A24 );
            } break;

            case PointsOfCompass::NorthWest:
            {
                result.Red = Average2( A16, A18 );
                result.Green = A17;
                result.Blue = Average2( A12, A22 );
            } break;

            case PointsOfCompass::SouthWest:
            {
                result.Red = Average2( A6, A8 );
                result.Green = A7;
                result.Blue = Average2( A2, A12 );
            } break;

            default: assert( false );
        }
    }

    return result;
}
