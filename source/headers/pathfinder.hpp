#ifndef _ALEX_PATHFINDER
#define _ALEX_PATHFINDER

#include <queue>
#include <unordered_set>

#include "world.hpp"


class Pathfinder {
    public: 
        static std::vector<Point> Dijkstras(const World&, const Point&, const Point&);
        static std::vector<Point> A_star(const World&, const Point&, const Point&);
};


#endif // DEBUG