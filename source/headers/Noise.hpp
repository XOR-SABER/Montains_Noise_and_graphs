#ifndef _ALEX_NOISE
#define _ALEX_NOISE

#include <algorithm>
#include <cstdint>
#include <vector>
#include <cmath>

#include "point.hpp"

class Noise{
    private: 
        std::vector<double> seeds; 
        std::vector<Point> 
    public:
        // The Default constructor is more of a default testing seed.. 
        Noise();
        // The non-default constructor is the one that should be actually used. 
        Noise(const uint32_t& intial_seed);
        constexpr double fade(const double &t) const; 
        constexpr double mix(const double &a, const double &b, const double &c) const; 
        double perlin(const int64_t& rx, const int64_t& ry) const;
        double perlin(const Point &p) const; 
};


#endif 
//ALEX NOISE