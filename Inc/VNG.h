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
//using Sums = std::tuple<uint8_t, uint8_t, uint8_t>;
struct Sums
{
    Sums() : Red(0), Green(0), Blue(0) {}

    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
};


class VNG {
public:
    VNG( const std::string file_path )
    {
        picture.ReadFromFile( file_path );
        for (int i = 0; i < 10; ++i) {
            std::cout <<
                (unsigned)picture.GetPixel( 0, i ).Red << " " <<
                (unsigned)picture.GetPixel( 0, i ).Green << " " <<
                (unsigned)picture.GetPixel( 0, i ).Blue << std::endl;
        }
    }

    void Process();
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
    std::vector<std::vector<uint8_t>> picture1;
    size_t height;
    size_t width;
    BMP picture;
};


#endif //VARIABLENUMBEROFGRADIENTS_VNG_H
