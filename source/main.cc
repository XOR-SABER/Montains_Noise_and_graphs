#include "headers/world.hpp"


int main() {
    World worl(0, 50,255);
    std::cout << "Before: Smoothing \n" << worl << std::endl;
    worl.smoothen();
    std::cout << "After: Smoothing \n" << worl << std::endl;
    
    
    return 0;
}