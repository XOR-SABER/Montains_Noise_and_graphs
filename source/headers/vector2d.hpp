#ifndef _ALEX_VECTOR2D
#define _ALEX_VECTOR2D

#include <cmath>

class Vector2D {
    private:
        double _x, _y; 
    public:
        // Constructors:
        // Default constructors
        Vector2D();
        // Non-default constructors
        Vector2D(const double &, const double &);
        //Getters and setters
        constexpr double x() const;
        constexpr double y() const; 
        constexpr void set_x(const double&);
        constexpr void set_y(const double&);
        constexpr void Normalize();
        constexpr double length() const;
        constexpr double angle(const Vector2D&) const;
        constexpr double dot_product(const Vector2D&)const; 
        constexpr double cross_product(const Vector2D&) const;
        Vector2D operator+(const Vector2D&) const;
        Vector2D operator-(const Vector2D&) const;
        Vector2D operator*(const double&) const;
        Vector2D operator/(const double&) const;
};

#endif 
//ALEX VECTOR2D