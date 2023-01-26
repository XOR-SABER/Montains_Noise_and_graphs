#ifndef _ALEX_WORLD_
#define _AlEX_WORLD_ 

#include "noise.hpp"
#include "colors.h"
// Might change that to OPENGL in the future.. Let me see if I can? 
// I decided to split it into other projects. 
// JS implmentation: for revamped website
// C++ / Raylib: for flexing  
// C++ / Colors.h: for 

// I really need to get a linux machine to develop on. 


class World {
private:
    const uint16_t MAP_SIZE;
    const uint16_t MAX_ELEVATION;
    std::vector<std::vector<uint32_t>> world_map; 
public:
    World();
    World(const size_t&, const uint16_t&, const uint16_t&);
    World(const World&);
    void smoothen_low();
    void smoothen_high();
    void amplifiy();
    void sharpen(const uint32_t& scale);
    void print_color();
    friend std::ostream& operator<<(std::ostream& outs, const World& rhs);
};


#endif