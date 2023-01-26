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
    // OK lets blend these layers
    // Lets priorize higher values, 
    // So I what I mean by that is if
    // the value is higher in then we 
    // keep the value. 

    // Example:
    // we have 254 and 134
    // SO we keep 254, and average 
    // the lower value so.. 
    // (254 + 134) / 2 = 194
    // this should leave us with 194
    // then if the next value is 89
    // (194 + 89) / 2 = 141 
    // OR if we have another value like 204
    // then (194 + 204) / 2 = 199
    // SO now 194 = 199
    // then the mappu would look like
    // 254 199 205
    // This should give us the slopes we want. 
    

}

void World::smoothen() {
    //This Generates the perlin Noise map.. 
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE-1; y++) {
            const uint32_t &p1 = world_map[x][y];
            const uint32_t &p2 = world_map[x][y+1];
            const uint32_t CALC = ((p1 + p2) / 2);

            
            if(p1 > p2) {
                //OK then p2 gets changed 
                world_map[x][y+1] = CALC;
            } else {
                world_map[x][y] = CALC;
            }
        }
    }
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
    outs << RESET;
    return outs; 
}