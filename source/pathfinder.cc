#include "headers/pathfinder.hpp"

std::vector<Point> Pathfinder::A_star(const World &map, const Point& start, const Point& end) {
    auto manhattan = [](const Point &p1, const Point &p2){
        return (abs(p1.x() - p2.x()) + abs(p1.y() - p2.y()));
    };
    const uint16_t MAP_SIZE = map.get_size(); 
    const Tile FIRST_TILE = map.world_map[start.x()][start.y()];
    const Tile END_TILE = map.world_map[end.x()][end.y()];

    std::vector<Point> prev;
    std::unordered_set<Tile, Tile()> visited; 
    std::priority_queue<std::pair<int32_t, Tile>> pq;

    // Set the first tile distance
    

    // Insert the first tile in the queue
    pq.push({manhattan(FIRST_TILE.get_point(), END_TILE.get_point()), map.world_map[start.x()][start.y()]});

    //Start the Dijkstras
    while (!pq.empty()) {
        // Pop the top of the queue
        Tile current_tile = pq.top().second;
        pq.pop();

        //Just check if we at the end already
        if(Point(current_tile.get_point()) == Point(END_TILE.get_point())) break;

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if(dx == 0 && dy == 0) continue;
                // Get the current point
                Point current_point(current_tile.x() + dx, current_tile.y() + dy);
                // Is it even on the map?
                if(!map.vaild_point(current_point)) continue;

                // Get the cost
                uint32_t cost = map.get_tile(current_point).weight();
                cost += current_point.distance_to(end);
                std::pair<int32_t, Tile> tmp = {cost, map.get_tile(current_point)};
                
            }
        }


    }
}