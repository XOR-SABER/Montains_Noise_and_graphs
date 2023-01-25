#ifndef _ALEX_VECTOR2D
#define _ALEX_VECTOR2D
#include <cmath>

class Vector2D {
    private:
        double _x, _y; 
    public:
        Vector2D() : Vector2D(0,0) {}

        Vector2D(const double &new_x, const double &new_y) {
            this->_x = new_x;
            this->_y = new_y;
        }
        inline constexpr double x() const noexcept {
            return this->_x;
        }
        inline constexpr double y() const noexcept {
            return this->_y;
        }

        inline constexpr void set_x(const double& new_x) noexcept{
            this->_x = new_x;
        }
        inline constexpr void set_y(const double& new_y) noexcept{
            this->_y = new_y;
        }
        inline constexpr void Normalize() {
            const double l = length(); 
            _x /= l;
            _y /= l;
        }
        inline constexpr double length() const {
            return std::sqrt((_x * _x) + (_y * _y));
        }
        inline constexpr double angle(const Vector2D& rhs) const {
            return atan2(cross_product(rhs), dot_product(rhs));
        }
        inline constexpr double dot_product(const Vector2D& rhs)const {
            return (_x * rhs._x) + (_y *rhs._y);
        }
        inline constexpr double cross_product(const Vector2D& rhs) const {
            return (_x * rhs._x) - (_y *rhs._y);
        }
        inline Vector2D operator+(const Vector2D &rhs) const {
            return Vector2D(_x + rhs._x, _y + rhs._y);
        }
        inline Vector2D operator-(const Vector2D &rhs) const {
            return Vector2D(_x - rhs._x, _y - rhs._y);
        }
        inline Vector2D operator*(const double &scalar) const {
            return Vector2D(_x * scalar, _y * scalar);
        }
        inline Vector2D operator/(const double &scalar) const {
            return Vector2D(_x / scalar, _y / scalar);
        }
};

#endif 
//ALEX VECTOR2D