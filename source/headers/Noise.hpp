#ifndef _ALEX_NOISE
#define _ALEX_NOISE

#include <cstdint>
#include <algorithm>
#include <vector>
#include <cmath>

class Noise{
    private: 
        std::vector<double> seeds; 
    public:
        Noise() : Noise(0,100) {}
        Noise(const uint32_t& intial_seed, size_t seed_size) {
            srand(intial_seed);
            seeds.reserve(seed_size);
            //use lamada's when they least suspect it..
            auto gen = [](){return rand() % 100;};
            std::generate(seeds.begin(), seeds.end(), gen);
        }
        std::vector<size_t> PerlinNoise1D(const size_t& size, const size_t& number_octaves){
            std::vector<size_t> retval(size);
            for(size_t i = 0; i < size; i++) {
                double fNoise = 0.0f;
                for(size_t o = 0; o < number_octaves; o++) {
                    int nPitch = size >> o;
                    int nSample1 = (i / nPitch) * nPitch;
                    int nSample2;
                    //https://www.youtube.com/watch?v=6-0UaeJBumA&t=679s
                }
            }
        }
};


#endif 
//ALEX NOISE