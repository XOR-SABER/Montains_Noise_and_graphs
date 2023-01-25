#include "headers/noise.hpp"

Noise::Noise() : Noise(0) {}

Noise::Noise(const uint32_t& intial_seed) {
    srand(intial_seed);
    seeds.reserve(256);
    //use lamada's when they least suspect it..
    auto fill_with_randoms = [](){return rand() % 1000;};
    std::generate(seeds.begin(), seeds.end(), fill_with_randoms);
}
constexpr double Noise::fade(const double &t) const noexcept{
    return (t * t * t * (t * (t * 6 - 15) + 10));
}

constexpr double Noise::mix(const double &a, const double &b, const double &c) const noexcept{
    return ((1- t) * a) + (t * b);
}

double Noise::perlin(const int64_t& rx, const int64_t& ry) const {
    return perlin(Point{rx,ry});
}

double Noise::perlin(const Point &p) const {
    const int32_t dx = (int32_t)x & 255;
    const int32_t dy = (int32_t)y & 255;

    // Curious, bitwise AND can be used in place of modulo? 
    // Apparently it's only with powers of two? 

    // Getting the gradients from the four corners.. 
    const int32_t g1 = seeds[(seeds[dx] + dy) & 255];
    const int32_t g2 = seeds[(seeds[dx + 1] + dy) & 255]];
    const int32_t g3 = seeds[(seeds[dx] + dy + 1) & 255];
    const int32_t g4 = seeds[(seeds[dx + 1] + dy + 1) & 255];

    // This requires the 2D vector class.. soooo.. 
    // const double d1 = 
    // const double d2 = 
    // const double d3 = 
    // const double d4 =

    // Todo:  
    return 0.0f; 
}  