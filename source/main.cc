#include "headers/world.hpp"
#include <string>


int main(int argc, char** argv) {
    if(argc == 1) return 1;
    
    size_t seed = std::hash<std::string>{}(argv[1]);
    World worl(seed, 50);
    worl.print_color();
    
    
    return 0;
}