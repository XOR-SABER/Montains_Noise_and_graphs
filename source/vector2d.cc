#include "headers/vector2d.hpp"

Vector2D::Vector2D() : Vector2D(0,0) {}
Vector2D::Vector2D(const double &new_x, const double &new_y) {
    this->_x = new_x;
    this->_y = new_y;
}
constexpr double Vector2D::x() const noexcept{
    return this->_x;
}
constexpr double Vector2D::y() const noexcept{
    return this->_y;
}
constexpr void Vector2D::set_x(const double& new_x) noexcept{
    this->_x = new_x;
}
constexpr void Vector2D::set_y(const double& new_y) noexcept{
    this->_y = new_y;
}
constexpr void Vector2D::Normalize() {
    const double l = length(); 
    _x /= l;
    _y /= l;
}
constexpr double Vector2D::length() const {
    return std::sqrt((_x * _x) + (_y * _y));
}
constexpr double Vector2D::angle(const Vector2D& rhs) const {
    return atan2(cross_product(rhs), dot_product(rhs));
}
constexpr double Vector2D::dot_product(const Vector2D& rhs)const {
    return (_x * rhs._x) + (_y *rhs._y);
}
constexpr double Vector2D::cross_product(const Vector2D& rhs) const {
    return (_x * rhs._x) - (_y *rhs._y);
}
Vector2D Vector2D::operator+(const Vector2D &rhs) const {
    return Vector2D(_x + rhs._x, _y + rhs._y);
}
Vector2D Vector2D::operator-(const Vector2D &rhs) const {
    return Vector2D(_x - rhs._x, _y - rhs._y);
}
Vector2D Vector2D::operator*(const double &scalar) const {
    return Vector2D(_x * scalar, _y * scalar);
}
Vector2D Vector2D::operator/(const double &scalar) const {
    return Vector2D(_x / scalar, _y / scalar);
}