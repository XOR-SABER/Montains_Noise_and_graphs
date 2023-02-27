#include "headers/noise.hpp"

Noise::Noise() : Noise(0) {}

Noise::Noise(const uint32_t& intial_seed) {
    seed = intial_seed;
    std::mt19937 rng(seed); 

    // Generate the intial seeds.. 
    std::uniform_int_distribution<int> i_dist(0,255);
    seeds.resize(256);
    // use lamada's when they least suspect it..
    auto fill_with_randoms = [=]() mutable{return i_dist(rng);};
    std::generate(seeds.begin(), seeds.end(), fill_with_randoms);
    
    // Generate the other seeds..
    std::uniform_real_distribution<double> d_dist(-4, 4);
    randomized_field.resize(256);
    // >:)
    auto populate_field = [=]() mutable{return Vector2D(d_dist(rng), d_dist(rng));};
    std::generate(randomized_field.begin(), randomized_field.end(), populate_field);
}

constexpr double Noise::fade(const double &t) const noexcept{
    return (t * t * t * (t * (t * 6 - 15) + 10));
}

double Noise::perlin(const double& x, const double& y) const {
    const int32_t dx = (int32_t)x & 255;
    const int32_t dy = (int32_t)y & 255;

    // Curious, bitwise AND can be used in place of modulo? 
    // Apparently it's only with powers of two? 

    // Getting the gradients from the four corners.. 
    const int32_t g1 = seeds[(seeds[dx] + dy)];
    const int32_t g2 = seeds[(seeds[dx + 1] + dy)];
    const int32_t g3 = seeds[(seeds[dx] + dy + 1)];
    const int32_t g4 = seeds[(seeds[dx + 1] + dy + 1)];

    //We need the fractional parts.. 
    // so am just gonna add a random float each time this is called.. 
    const double xf = x - (int)x;
    const double yf = y - (int)y;

    // This requires the 2D vector class.. soooo.. 
    // Done, but this does the randomization of the vectors to get the value from perlin.. 
    const double d1 = randomized_field[g1].dot_product(Vector2D(xf, yf));
    const double d2 = randomized_field[g2].dot_product(Vector2D(xf - 1, yf));
    const double d3 = randomized_field[g3].dot_product(Vector2D(xf, yf -1));
    const double d4 = randomized_field[g4].dot_product(Vector2D(xf - 1, yf - 1));

    // Fade is used which is apart of the orginal code.. 
    // I used this: https://rtouti.github.io/graphics/perlin-noise-algorithm
    const double u = fade(xf);
    const double v = fade(yf);

    const double nx1 = std::lerp(d1, d2, u);
    const double nx2 = std::lerp(d3, d4, u);

    return ((std::lerp(nx1, nx2, v) + 1) / 2);
}

double Noise::perlin(const Point &p) const {
    std::mt19937 rng(seed);
    std::uniform_real_distribution<double> d_dist(-0.49, 1);
    return perlin(p.x() + d_dist(rng), p.y() + d_dist(rng));
}  