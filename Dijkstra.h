//
// Created by Mikael on 22/02/2024.
//

#ifndef PATH_SIM_DIJKSTRA_H
#define PATH_SIM_DIJKSTRA_H


#include <map>
#include "Map.h"

class Dijkstra {
public:
    Dijkstra(Map& map);
    void MarkPath();
    void CalculatePath();
    void SetStart(Vertex* start);
    void SetEnd(Vertex* end);
private:
    Map map;
    Vertex* pVertexStart;
    Vertex* pVertexEnd;
    bool isCalculated;

    std::map<unsigned int, unsigned int> distance;
    std::map<unsigned int, int> prev;
};


#endif //PATH_SIM_DIJKSTRA_H
