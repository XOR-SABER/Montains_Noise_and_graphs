#ifndef _ALEX_POINT
#define _ALEX_POINT

#include <cstdint>
#include <iostream>
#include <cmath>

class Point{
private:
    int64_t _x; 
    int64_t _y;
public:
    Point();
    Point(const int64_t& init_x, const int64_t& init_y);
    inline constexpr int64_t x() const noexcept {
        return _x;
    }
    inline constexpr int64_t y() const noexcept {
        return _y;
    }
    inline constexpr double distance_from_orgin() const noexcept{
        return distance_to(0,0);
    }
    inline constexpr double distance_to(const Point& rhs) const noexcept{
        return distance_to(rhs._x,rhs._y);
    }
    inline constexpr double distance_to(const int64_t& rx, const int64_t& ry) const noexcept{
        return hypot(rx - this->_x, ry - this->_y);
    }
    friend std::istream& operator>>(std::istream& ins, Point& rhs);
    friend std::ostream& operator<<(std::ostream& outs, const Point& rhs);
        
};

#endif // DEBUG