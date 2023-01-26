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
// This should give us the slopes we want for flat terrain..

void World::smoothen_high() {
    //This Generates the perlin Noise map.. 
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE-1; y++) {
            uint32_t &d1 = world_map[x][y];
            uint32_t &d2 = world_map[x][y+1];
            const uint32_t CALC = ((d1 + d2) / 2);
                //OK then p2 gets changed 
            if(d1 > d2) world_map[x][y+1] = CALC;
            else world_map[x][y] = CALC;

            const uint32_t CALC2 = ((d1 + d2) / 2);
            if(d1 > d2) world_map[x][y+1] = CALC2;
            else world_map[x][y] = CALC2;
        }
    }
}
void World::smoothen_low() {
    //This Generates the perlin Noise map.. 
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE-1; y++) {
            uint32_t &d1 = world_map[x][y];
            uint32_t &d2 = world_map[x][y+1];
            const uint32_t CALC = ((d1 + d2) / 2);
                //OK then p2 gets changed 
            if(d1 < d2) world_map[x][y+1] = CALC;
            else world_map[x][y] = CALC;

            const uint32_t CALC2 = ((d1 + d2) / 2);
            if(d1 < d2) world_map[x][y+1] = CALC2;
            else world_map[x][y] = CALC2;
        }
    }
}

//I don't know what this does, but it looks cool..
void World::amplifiy() {
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE-1; y++) {
            const uint32_t &p1 = world_map[x][y];
            const uint32_t &p2 = world_map[x][y+1];
            const double ty = double((p1+1) / (p2+1));
            world_map[x][y] = std::lerp(p1,p2,ty);
            if (world_map[x][y] > MAX_ELEVATION) {
                world_map[x][y] = MAX_ELEVATION;
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


void World::print_color() {
    const float snow_layer = 0.95f * MAX_ELEVATION;
    const float mountain_layer = 0.7f * MAX_ELEVATION;
    const float foothills_layer = 0.4f * MAX_ELEVATION;
    const float plains_layer = 0.1f * MAX_ELEVATION;

    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE; y++) {
            uint32_t current_elevation = world_map[x][y];
            if(current_elevation > snow_layer) setbgcolor(255, 255, 255);
            else if(current_elevation > mountain_layer) setbgcolor(105,105,105);
            else if(current_elevation < foothills_layer) setbgcolor(128, 128, 0);
            else setbgcolor(64, 128, 0);
            std::cout << "  " << RESET;
        }
        std::cout << '\n' << RESET;
    }
    std::cout << RESET;
}