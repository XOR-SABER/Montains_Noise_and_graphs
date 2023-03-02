#ifndef _ALEX_WORLD_
#define _AlEX_WORLD_ 

#include "noise.hpp"
#include "tile.hpp"
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
    const uint16_t MAX_ELEVATION = 255;
    double avg_height = 0; 
    std::string world_type;
protected:
    void generate_world(); 
    void smoothen_low();
    void smoothen_high();
    void amplifiy();
public:
    std::vector<std::vector<Tile>> world_map; 
    World();
    World(const size_t&, const uint16_t&);
    World(const World&);
    void sharpen(const uint32_t& scale);
    void print_color();
    inline uint16_t get_size() const noexcept {
        return MAP_SIZE;
    }
    inline Tile get_tile(const Point &p) const noexcept {
        return world_map[p.x()][p.y()];
    }
    inline constexpr bool vaild_point(const Point &p) const noexcept {
        return (!(p.x() < 0 || p.x() >= MAP_SIZE || p.y() < 0 || p.y() >= MAP_SIZE));
    }
    friend std::ostream& operator<<(std::ostream& outs, const World& rhs);
};


#endif