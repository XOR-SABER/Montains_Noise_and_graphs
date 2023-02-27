#include "headers/world.hpp"

World::World(const size_t& seed, const uint16_t& map_size) : MAP_SIZE(map_size) { 
    world_map.resize(MAP_SIZE, std::vector<Tile>(MAP_SIZE));
    Noise dis(seed);

    //This Generates the perlin Noise map.. 
    size_t sum_of_heights = 0; 
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE; y++) {
            double temp = dis.perlin(Point(x,y)) * MAX_ELEVATION;
            if(temp < 0) {
                temp = 0;
            } else if (temp > MAX_ELEVATION) {
                temp = MAX_ELEVATION;
            }
            world_map[x][y] = Tile(x, y, temp);
            sum_of_heights += temp;
        }
    }
    avg_height = double(sum_of_heights / (MAP_SIZE*MAP_SIZE));
    std::cout << "Average Elevation at gen time: " << avg_height << std::endl;
    generate_world();
}

void World::generate_world() {
    enum worlds {
        PLAINS = 117,
        VOLCANIC = 118,
        FOREST = 120, 
        MOUNTAINS = 126,
        PEAKS = 129, 
        GLACIER = 130, 
    };

    if(avg_height <= 117) {
        world_type = "Plains";
        smoothen_low();
        smoothen_low();
        return; 
    } else if (avg_height <= FOREST) {
        world_type = "Forest";
        smoothen_low();
        smoothen_high();
        return;
    } else if (avg_height <= MOUNTAINS) {
        world_type = "Mountains";
        amplifiy();
        smoothen_high();
        return;
    } else if (avg_height <= PEAKS) {
        world_type = "Peaks";
        amplifiy();
        amplifiy();
        smoothen_high();
        return;
    } else {
        world_type = "Glacier";
        amplifiy();
        amplifiy();
        smoothen_high();
        smoothen_high();
        return;
    }



}


void World::smoothen_high() {
    //This Generates the perlin Noise map.. 
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE-1; y++) {
            uint32_t d1 = world_map[x][y].weight();
            uint32_t d2 = world_map[x][y+1].weight();
            const uint32_t CALC = ((d1 + d2) / 2);
                //OK then p2 gets changed 
            if(d1 > d2) world_map[x][y+1].set_weight(CALC);
            else world_map[x][y].set_weight(CALC);

            const uint32_t CALC2 = ((d1 + d2) / 2);
            if(d1 > d2) world_map[x][y+1].set_weight(CALC2);
            else world_map[x][y].set_weight(CALC2);
        }
    }
}
void World::smoothen_low() {
    //This Generates the perlin Noise map.. 
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE-1; y++) {
            uint32_t d1 = world_map[x][y].weight();
            uint32_t d2 = world_map[x][y+1].weight();
            const uint32_t CALC = ((d1 + d2) / 2);
                //OK then p2 gets changed 
            if(d1 > d2) world_map[x][y+1].set_weight(CALC);
            else world_map[x][y].set_weight(CALC);

            const uint32_t CALC2 = ((d1 + d2) / 2);
            if(d1 > d2) world_map[x][y+1].set_weight(CALC2);
            else world_map[x][y].set_weight(CALC2);
        }
    }
}

//I don't know what this does, but it looks cool..
void World::amplifiy() {
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE-1; y++) {
            uint32_t d1 = world_map[x][y].weight();
            uint32_t d2 = world_map[x][y+1].weight();
            const double ty = double((d1+1) / (d2+1));
            world_map[x][y].set_weight(std::lerp(d1,d2,ty));
            if (world_map[x][y].weight() > MAX_ELEVATION) {
                world_map[x][y].set_weight(MAX_ELEVATION);
            }
        }
    }
}


//Default prints without color.. 
std::ostream& operator<<(std::ostream& outs, const World& rhs) {
    for(size_t x = 0; x < rhs.MAP_SIZE; x++) {
        for(size_t y = 0; y < rhs.MAP_SIZE; y++) {
            const uint32_t tmp = rhs.world_map[x][y].weight();
            setbgcolor(tmp, tmp, tmp);
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
    
    size_t sum_of_heights = 0; 
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE; y++) {
            const uint32_t current_elevation = world_map[x][y].weight();
            if(current_elevation > snow_layer) setbgcolor(255, 255, 255);
            else if(current_elevation > mountain_layer) setbgcolor(105,105,105);
            else if(current_elevation < foothills_layer) setbgcolor(128, 128, 0);
            else setbgcolor(64, 128, 0);
            std::cout << "  " << RESET;
            sum_of_heights += current_elevation;
        }
        std::cout << '\n' << RESET;
    }
    avg_height = sum_of_heights / (MAP_SIZE*MAP_SIZE);
    std::cout << RESET;
    std::cout << "Average Elevation after processing: " << avg_height << std::endl;
    std::cout << "World type: " << world_type << std::endl;
}