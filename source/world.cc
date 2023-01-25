#include "headers/world.hpp"

World::World(const size_t& seed, const uint16_t& map_size, const uint16_t& max_elevation) : MAP_SIZE(map_size), MAX_ELEVATION(max_elevation) { 
    world_map.resize(MAP_SIZE, std::vector<uint32_t>(MAP_SIZE));
    Noise dis(seed);

    //This Generates the perlin Noise map.. 
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE; y++) {
            double temp = dis.perlin(Point(x,y)) * MAX_ELEVATION;
            if(temp < 0) {
                temp = 0;
            } else if (temp > MAX_ELEVATION) {
                temp = MAX_ELEVATION;
            }
            world_map[x][y] = temp;
        }
    }
    std::cout << "Mappu generated.. \n";

}

//Default prints without color.. 
std::ostream& operator<<(std::ostream& outs, const World& rhs) {
    for(size_t x = 0; x < rhs.MAP_SIZE; x++) {
        for(size_t y = 0; y < rhs.MAP_SIZE; y++) {
            setbgcolor(rhs.world_map[x][y], rhs.world_map[x][y],rhs.world_map[x][y]);
            outs << "  " << RESET;
        }
        outs << '\n' << RESET;
    }
    return outs; 
}