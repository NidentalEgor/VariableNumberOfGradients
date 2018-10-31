//
// Created by egor on 28.10.18.
//

#include <algorithm>
#include <assert.h>
#include "../Inc/VNG.h"
#include "../Inc/Macroses.inl"

void VNG::Process() {
    for ( size_t i = 2; i < picture.TellHeight() - 2; ++i ) {
        for ( size_t j = 2; j < picture.TellWidth() - 2; ++j ) {

//            Log(
//                __FILENAME__,
//                __LINE__,
//                std::string( "i = " ) + std::to_string( i ) + std::string( " j = " ) + std::to_string( j ) );

            if ( i % 2 == 0 )
            {
                j % 2 == 0 ? ProcessRedPixel( i, j ) : ProcessGreenPixel( i, j );
            }
            else
            {
                j % 2 == 0 ? ProcessGreenPixel( i, j ) : ProcessBluePixel( i, j );
            }
        }
    }
}

void VNG::Write( const std::string& file_path )
{
    result_picture.WriteToFile( file_path );
}

inline uint16_t CalculateGradient(
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

uint16_t CalculateGradientGreenNotStr(
        const uint8_t par1,
        const uint8_t par2,
        const uint8_t par3,
        const uint8_t par4,
        const uint8_t par5,
        const uint8_t par6,
        const uint8_t par7,
        const uint8_t par8 )
{
    return abs( par1 - par2 ) +
            abs( par3 - par4 ) +
            abs( par5 - par6 ) +
            abs( par7 - par8 );
}

void VNG::ProcessPixel( const size_t i, const size_t j, const PixelColor pixel_color )
{
    std::array<uint8_t, 8> gradients;

    //Log( "Before gradients calculating" );

    if ( pixel_color == PixelColor::Red )
    {
        // gradientN
        gradients[0] = CalculateGradient( G8, G18, R3, R13, B7, B17, B9, B19, G2, G12, G4, G14 );
        // gradientE
        gradients[1] = CalculateGradient( G14, G12, R15, R13, B9, B7, B19, B17, G10, G8, G20, G18 );
        // gradientS
        gradients[2] = CalculateGradient( G18, G8, R23, R13, B19, B9, B17, B7, G24, G14, G22, G12 );
        // gradientW
        gradients[3] = CalculateGradient( G12, G14, R11, R13, B17, B19, B7, B9, G16, G18, G6, G8 );
        // gradientNE
        gradients[4] = CalculateGradient( B9, B17, R5, R13, G8, G12, G14, G18, G4, G8, G10, G14 );
        // gradientSE
        gradients[5] = CalculateGradient( B19, B7, R25, R13, G12, G18, G18, G12, G20, G14, G24, G18 );
        // gradientNW
        gradients[6] = CalculateGradient( B7, B19, R1, R13, G12, G18, G8, G14, G6, G12, G2, G8 );
        // gradientSW
        gradients[7] = CalculateGradient( B17, B9, R21, R13, G18, G14, G12, G10, G22, G18, G16, G12 );
    }
    else if ( pixel_color == PixelColor::Blue )
    {
        // gradientN
        gradients[0] = CalculateGradient( G8, G18, B3, B13, R7, R17, R9, R19, G2, G12, G4, G14 );
        // gradientE
        gradients[1] = CalculateGradient( G14, G12, B15, B13, R9, R7, R19, R17, G10, G8, G20, G18 );
        // gradientS
        gradients[2] = CalculateGradient( G18, G8, B23, B13, R19, R9, R17, R7, G24, G14, G22, G12 );
        // gradientW
        gradients[3] = CalculateGradient( G12, G14, B11, B13, R17, R19, R7, R9, G16, G18, G6, G8 );
        // gradientNE
        gradients[4] = CalculateGradient( R9, R17, B5, B13, G8, G12, G14, G18, G4, G8, G10, G14 );
        // gradientSE
        gradients[5] = CalculateGradient( R19, R7, B25, B13, G12, G18, G18, G12, G20, G14, G24, G18 );
        // gradientNW
        gradients[6] = CalculateGradient( R7, R19, B1, B13, G12, G18, G8, G14, G6, G12, G2, G8 );
        // gradientSW
        gradients[7] = CalculateGradient( R17, R9, B21, B13, G18, G14, G12, G10, G22, G18, G16, G12 );
    }
    else // PixelColor::Green
    {
        // gradientN
        gradients[0] = CalculateGradient( R8, R18, G3, G13, G7, G17, G9, G19, B2, B12, B4, B14 );
        // gradientE
        gradients[1] = CalculateGradient( B14, B12, G15, G13, G9, G7, G19, G17, R10, R8, R20, R18 );
        // gradientS
        gradients[2] = CalculateGradient( R18, R8, G23, G13, G17, G7, G19, G9, B22, B12, B24, B14 );
        // gradientW
        gradients[3] = CalculateGradient( B12, B14, G11, G13, G7, G9, G17, G19, R6, R8, R16, R18 );
        // gradientNE
        gradients[4] = CalculateGradientGreenNotStr( G9, G17, G5, G13, B4, B12, R10, R18 );
        // gradientSE
        gradients[5] = CalculateGradientGreenNotStr( G19, G7, G25, G13, B24, B12, R20, R8 );
        // gradientNW
        gradients[6] = CalculateGradientGreenNotStr( G7, G19, G1, G13, B2, B14, R6, R18 );
        // gradientSW
        gradients[7] = CalculateGradientGreenNotStr( G17, G9, G21, G13, B22, B14, R16, R8 );
    }


    //Log( "After gradients calculating" );

    const auto min_and_max = std::minmax_element( gradients.begin(), gradients.end() );
    const auto& min = *min_and_max.first;
    const auto& max = *min_and_max.second;

    const uint8_t threshold = static_cast<uint8_t >( 1.5 * min + 0.5 * ( max - min ) );

    //Log( "Before sums calculating" );

    //Log( std::string( "i = " ) + std::to_string( i ) + std::string( " j = " ) + std::to_string( j ) );

    const auto sums = CalculateSums(
        i,
        j,
        gradients,
        threshold,
        pixel_color );

    //Log( "After sums calculating" );

    Pixel result;
    if( pixel_color == PixelColor::Red )
    {
        result.Red = R13; // R13
        result.Green = R13 + ( sums.Green - sums.Red ) / 4;
        result.Blue = R13 + ( sums.Blue - sums.Red ) / 4;
    }
    else if( pixel_color == PixelColor::Green )
    {
        result.Red = G13 + ( sums.Red - sums.Green ) / 4;
        result.Green = G13; // G13
        result.Blue = G13 + ( sums.Blue - sums.Green ) / 4;
    }
    else // PixelColor::Blue
    {
        result.Red = B13 + ( sums.Red - sums.Blue ) / 4;
        result.Green = B13 + ( sums.Green - sums.Blue ) / 4;
        result.Blue = B13; // B13
    }

    RGBApixel pixel;
    pixel.Red = result.Red;
    pixel.Green = result.Green;
    pixel.Blue = result.Blue;

    result_picture.SetPixel( /*i, j,*/j, i, pixel );
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
    Sums result;
    for ( size_t index = static_cast<size_t >( PointsOfCompass::PointsOfCompass_First );
            index != static_cast<size_t>( PointsOfCompass::PointsOfCompass_Count );
            ++index )
    {
        if ( gradients[index] > threshold )
        {
            result += CalculateSums(
                i,
                j,
                static_cast<PointsOfCompass>( index ),
                pixel_color );
        }
    }

    return result;
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
    if ( pixel_color == PixelColor::Red )
    {
        switch ( points_of_compass )
        {
            case PointsOfCompass::North:
            {
                result.Red = Average2( R7, R9 );
                result.Green = G8;
                result.Blue = Average2( B3, B13 );
            } break;

            case PointsOfCompass::East:
            {
                result.Red = Average2( R9,  R19 );
                result.Green = G14;
                result.Blue = Average2( B13, B15 );
            } break;

            case PointsOfCompass::South:
            {
                result.Red = Average2( R17, R19 );
                result.Green = G18;
                result.Blue = Average2( B13, B23 );
            } break;

            case PointsOfCompass::West:
            {
                result.Red = Average2( R7, R17 );
                result.Green = G12;
                result.Blue = Average2( B11, B13 );
            } break;

            case PointsOfCompass::NorthEast:
            {
                result.Red = R9;
                result.Green = Average4( G4, G8, G10, G14 );
                result.Blue = Average2( B13, B5 );
            } break;

            case PointsOfCompass::SouthEast:
            {
                result.Red = R19;
                result.Green = Average4( G14, G18, G20, G24 );
                result.Blue = Average2( B13, B25 );
            } break;

            case PointsOfCompass::SouthWest:
            {
                result.Red = R17;
                result.Green = Average4( G12, G16, G18, G22 );
                result.Blue = Average2( B13, B21 );
            } break;

            case PointsOfCompass::NorthWest:
            {
                result.Red = R7;
                result.Green = Average4( G2, G6, G8, G12 );
                result.Blue = Average2( B13, B1 );
            } break;

            default: assert( false );
        }
    }
    else if ( pixel_color == PixelColor::Blue )
    {
        switch ( points_of_compass )
        {
            case PointsOfCompass::North:
            {
                result.Red = Average2( R3, R13 );
                result.Green = G8;
                result.Blue = Average2( B7, B9 );
            } break;

            case PointsOfCompass::East:
            {
                result.Red = Average2( R13,  R15 );
                result.Green = G14;
                result.Blue = Average2( B9, B19 );
            } break;

            case PointsOfCompass::South:
            {
                result.Red = Average2( R13, R23 );
                result.Green = G18;
                result.Blue = Average2( B17, B19 );
            } break;

            case PointsOfCompass::West:
            {
                result.Red = Average2( R11, R13 );
                result.Green = G12;
                result.Blue = Average2( B7, B17 );
            } break;

            case PointsOfCompass::NorthEast:
            {
                result.Red = Average2( R13, R5 );
                result.Green = Average4( G4, G8, G10, G14 );
                result.Blue = B9;
            } break;

            case PointsOfCompass::SouthEast:
            {
                result.Red = Average2( R13, R25 );
                result.Green = Average4( G14, G18, G20, G24 );
                result.Blue = B19;
            } break;

            case PointsOfCompass::SouthWest:
            {
                result.Red = Average2( R13, R21 );
                result.Green = Average4( G12, G16, G18, G22 );
                result.Blue = B17;
            } break;

            case PointsOfCompass::NorthWest:
            {
                result.Red = Average2( R13, R1 );
                result.Green = Average4( G2, G6, G8, G12 );
                result.Blue = B7;
            } break;

            default: assert( false );
        }
    }
    else // central pixel is green
    {
        switch ( points_of_compass )
        {
            case PointsOfCompass::North:
            {
                result.Red = R8;
                result.Green = Average2( G3, G13 );
                result.Blue = Average4( B2, B4, B12, B14 );
            } break;

            case PointsOfCompass::East:
            {
                result.Red = Average4( R8, R10, R18, R20 );
                result.Green =Average2( G13, G15 );
                result.Blue = B14;
            } break;

            case PointsOfCompass::South:
            {
                result.Red = R18;
                result.Green = Average2( G13, G23 );
                result.Blue = Average4( B12, B14, B22, B24 );
            } break;

            case PointsOfCompass::West:
            {
                result.Red = Average4( R6, R8, R16, R18 );
                result.Green = Average2( G11, G13 );
                result.Blue = B12;
            } break;

            case PointsOfCompass::NorthEast:
            {
                result.Red = Average2( R8, R10 );
                result.Green = G9;
                result.Blue = Average2( B4, B14 );
            } break;

            case PointsOfCompass::SouthEast:
            {
                result.Red = Average2( R18, R20 );
                result.Green = G19;
                result.Blue = Average2( B14, B24 );
            } break;

            case PointsOfCompass::SouthWest:
            {
                result.Red = Average2( R16, R18 );
                result.Green = G17;
                result.Blue = Average2( B12, B22 );
            } break;

            case PointsOfCompass::NorthWest:
            {
                result.Red = Average2( R6, R8 );
                result.Green = G7;
                result.Blue = Average2( B2, B12 );
            } break;

            default: assert( false );
        }
    }

    return result;
}
