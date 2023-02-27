#ifndef _ALEX_TILE
#define _ALEX_TILE

#include "point.hpp"

class Tile : public Point{
    protected:
        uint32_t _weight;
        inline Point get_point() const noexcept{
            return(Point(this->x(), this->y()));
        }
    public:
        Tile() = default;
        Tile(const int64_t& init_x, const int64_t& init_y, const uint32_t& tile_weight) 
            : Point(init_x, init_y), _weight(tile_weight) {

        }
        inline constexpr uint32_t weight() const noexcept {
            return _weight;
        }
        inline void set_weight(const uint32_t &new_weight) noexcept {
            _weight = new_weight;
        }
        inline Tile& operator=(const Tile &t) noexcept {
            _x = t._x;
            _y = t._y;
            _weight = t._weight;
            return *this;
        }
};

#endif // _ALEX_TILE