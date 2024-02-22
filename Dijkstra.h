//
// Created by Mikael on 22/02/2024.
//

#ifndef PATH_SIM_DIJKSTRA_H
#define PATH_SIM_DIJKSTRA_H


#include "Map.h"

class Dijkstra {
public:
    Dijkstra(Map& map);
    void MarkPath();
    void SetStart(Vertex* start);
    void SetEnd(Vertex* end);
private:
    Map map;
    Vertex* pVertexStart;
    Vertex* pVertexEnd;
};


#endif //PATH_SIM_DIJKSTRA_H
