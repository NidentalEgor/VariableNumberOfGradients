//
// Created by egor on 28.10.18.
//

#ifndef VARIABLENUMBEROFGRADIENTS_VNG_H
#define VARIABLENUMBEROFGRADIENTS_VNG_H


#include <iostream>
#include <limits>
#include <vector>
#include <array>
#include <tuple>

#include "Logger.h"
#include "../Lib/EasyBMP/EasyBMP.h"

enum class PixelColor
{
    Red = 0,
    Green,
    Blue
};

enum class PointsOfCompass
{
    PointsOfCompass_First = 0,
    North = 0,
    East,
    South,
    West,
    NorthEast,
    SouthEast,
    NorthWest,
    SouthWest,

    PointsOfCompass_Count
};

using Gradients = std::array<uint8_t, static_cast<long unsigned int>( PointsOfCompass::PointsOfCompass_Count )>;

struct Sums
{
    Sums() : Red( 0 ), Green( 0 ), Blue( 0 ) {}

    Sums &operator += ( const Sums& other )
    {
        Red += other.Red;
        Green += other.Green;
        Blue += other.Blue;

        return *this;
    }

    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
};

using Pixel = Sums;

class VNG : public Traceble {
public:
    VNG( const std::string file_path )
    {
        picture.ReadFromFile( file_path );

        Log( std::string( "width = " ) + std::to_string( picture.TellWidth() ) + " height = " + std::to_string( picture.TellHeight() ) );

        result_picture.SetSize( picture.TellWidth(), picture.TellHeight() );
    }

    void Process();
    void Write( const std::string& file_path );
    void ProcessRedPixel( const size_t i, const size_t j );
    void ProcessGreenPixel( const size_t i, const size_t j );
    void ProcessBluePixel( const size_t i, const size_t j );
    Sums CalculateSums(
        const size_t i,
        const size_t j,
        const Gradients gradients,
        const uint8_t threshold,
        const PixelColor pixel_color );
    Sums CalculateSums(
        const size_t i,
        const size_t j,
        const PointsOfCompass points_of_compass,
        const PixelColor pixel_color );
    void ProcessPixel(
        const size_t i,
        const size_t j,
        const PixelColor pixel_color );

private:
    BMP picture;
    BMP result_picture;
};


#endif //VARIABLENUMBEROFGRADIENTS_VNG_H
