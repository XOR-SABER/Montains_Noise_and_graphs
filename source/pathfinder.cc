#include "headers/pathfinder.hpp"


std::vector<Point> Pathfinder::Dijkstras(const World &map, const Point& start, const Point& end) {
    const uint16_t MAP_SIZE = map.get_size(); 
    const Tile FIRST_TILE = map.world_map[start.x()][start.y()];
    const Tile END_TILE = map.world_map[end.x()][end.y()];
    // This holds the distances of each point
    std::vector<std::vector<int32_t>> dist(MAP_SIZE, std::vector<int32_t>(MAP_SIZE, INT32_MAX));
    std::vector<Tile> path(MAP_SIZE); 
    std::priority_queue<Tile> pq;

    // Set the first tile distance
    dist[start.x()][start.y()] = 0;

    // Insert the first tile in the queue
    pq.push(map.world_map[start.x()][start.y()]);

    //Start the Dijkstras
    while (!pq.empty()) {
        // Pop the top of the queue
        Tile current_tile = pq.top();
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


            }
        }


    }
    

    


}
std::vector<Point> Pathfinder::A_star(const World &map, const Point& start, const Point& end) {

}