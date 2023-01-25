#ifndef _ALEX_NOISE
#define _ALEX_NOISE

#include <algorithm>
#include <cstdint>
#include <vector>
#include <random>
#include <cmath>

#include "point.hpp"
#include "vector2d.hpp"

class Noise{
    private: 
        std::vector<double> seeds; 
        std::vector<Vector2D> randomized_field;  
        int seed; 
        double perlin(const double&, const double&) const;
    public:
        // The Default constructor is more of a default testing seed.. 
        Noise();
        // The non-default constructor is the one that should be actually used. 
        Noise(const uint32_t& intial_seed);
        //This is used for the perlin algo to fade
        constexpr double fade(const double &) const noexcept; 
        //

        double perlin(const Point &) const; 
};


#endif 
//ALEX NOISE