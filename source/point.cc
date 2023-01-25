#include "headers/point.hpp"


Point::Point() : Point(0,0) {}

Point::Point(const int64_t& init_x, const int64_t& init_y) {
    this->_x = init_x;
    this->_y = init_y;
}

std::istream& operator>>(std::istream& ins, Point& rhs) {
    ins >> rhs._x;
    ins >> rhs._y;
    return ins;
}

std::ostream& operator<<(std::ostream& outs, const Point& rhs){
    outs << "(" << rhs._x << "," << rhs._y << ")";
    return outs;
}