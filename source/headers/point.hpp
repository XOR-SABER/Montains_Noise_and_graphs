#ifndef _ALEX_POINT
#define _ALEX_POINT

#include <cstdint>
#include <iostream>
#include <cmath>

class Point{
    protected:
        int64_t _x; 
        int64_t _y;
    public:
        Point() : Point(0,0) {}
        Point(const int64_t& init_x, const int64_t& init_y) {
            this->_x = init_x;
            this->_y = init_y;
        }
        inline constexpr int64_t x() const noexcept {
            return _x;
        }
        inline constexpr int64_t y() const noexcept {
            return _y;
        }
        inline void set_y(const int64_t& new_y) noexcept {
            _y = new_y;
        }    
        inline void set_x(const int64_t& new_x) noexcept {
            _x = new_x;
        }
        inline constexpr double distance_from_orgin() const noexcept {
            return distance_to(0,0);
        }
        inline constexpr double distance_to(const Point& rhs) const noexcept {
            return distance_to(rhs._x,rhs._y);
        }
        inline constexpr double distance_to(const int64_t& rx, const int64_t& ry) const noexcept {
            return hypot(rx - this->_x, ry - this->_y);
        }
        inline friend std::istream& operator>>(std::istream& ins, Point& rhs) noexcept {
            ins >> rhs._x;
            ins >> rhs._y;
            return ins;
        }
        inline friend std::ostream& operator<<(std::ostream& outs, const Point& rhs) noexcept {
            outs << "(" << rhs._x << "," << rhs._y << ")";
            return outs;
        }
        virtual constexpr inline size_t operator()(const Point& p) const noexcept {
            return (std::hash<int64_t>()(_x) ^ std::hash<int64_t>()(_y));
        }
        inline constexpr bool operator==(const Point& p) const noexcept {
            return ((this->_x == p._x) && (this->_y == p._y));
        }
            
};

#endif // DEBUG