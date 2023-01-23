#ifndef _ALEX_POINT
#define _ALEX_POINT

#include <cstdint>
#include <iostream>
#include <cmath>

class Point{
private:
    int64_t x; 
    int64_t y;
public:
    Point();
    Point(const int64_t& init_x, const int64_t& init_y);
    inline constexpr double distance_from_orgin() const {
        return distance_to(0,0);
    }
    inline constexpr double distance_to(const Point& rhs) const{
        return distance_to(rhs.x,rhs.y);
    }
    inline constexpr double distance_to(const int64_t& rx, const int64_t& ry) const {
        return hypot(rx - this->x, ry - this->y);
    }
    friend std::istream& operator>>(std::istream& ins, Point& rhs);
    friend std::ostream& operator<<(std::ostream& outs, const Point& rhs);
        
};

#endif // DEBUG