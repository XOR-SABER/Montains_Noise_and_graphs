#include "headers/noise.hpp"
#include "headers/colors.h"

int main() {
    std::cout << "Hello World" << std::endl;
    Point A(10,10); 
    Point B(3,3);
    std::cout << "A: " << A << " is " << A.distance_from_orgin() << " from the orgin\n";
    //Code here:
    const int MAP_SIZE = 25;
    int mappu[MAP_SIZE][MAP_SIZE]; 

    
    Noise dis(time(NULL));

    const int MAX_ELEVATION = 255;
    const int MULTIPLIER = 500; 

    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE; y++) {
            double temp = dis.perlin(Point(x,y)) * MAX_ELEVATION;
            if(temp < 0) {
                temp = 0;
            } else if (temp > MAX_ELEVATION) {
                temp = MAX_ELEVATION;
            }
            mappu[x][y] = temp;
        }
    }

    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE; y++) {
            setbgcolor(mappu[x][y],mappu[x][y],mappu[x][y]);
            std::cout << "  " << RESET;
        }
        std::cout << std::endl;
    }
    for(size_t x = 0; x < MAP_SIZE; x++) {
        for(size_t y = 0; y < MAP_SIZE; y++) {
            std::cout << mappu[x][y] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}