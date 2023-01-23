#include "headers/point.hpp"


Point::Point() : Point(0,0) {}

Point::Point(const int64_t& init_x, const int64_t& init_y) {
    this->x = init_x;
    this->y = init_y;
}

std::istream& operator>>(std::istream& ins, Point& rhs) {
    ins >> rhs.x;
    ins >> rhs.y;
    return ins;
}
std::ostream& operator<<(std::ostream& outs, const Point& rhs){
    outs << "(" << rhs.x << "," << rhs.y << ")";
    return outs;
}