//
// Created by Mikael on 22/02/2024.
//

#ifndef PATH_SIM_DIJKSTRA_H
#define PATH_SIM_DIJKSTRA_H


#include <map>
#include "Map.h"
#include "PriorityQueue.h"

class Dijkstra {
public:
    Dijkstra(Map& map);
    void MarkPath();
    void InitCalculation();
    void IterateCalculation();
    void SetStart(Vertex* start);
    void SetEnd(Vertex* end);
    void Reset();
    void SetNotCalculated();
    bool IsSolving() const;
    bool IsCalculated() const;
private:
    Map map;
    Vertex* pVertexStart;
    Vertex* pVertexEnd;
    bool isCalculated;
    bool isSolving;

    PriorityQueue pq;
    unsigned int searchedRadius;
    std::map<unsigned int, unsigned int> distance;
    std::map<unsigned int, int> prev;
};


#endif //PATH_SIM_DIJKSTRA_H
