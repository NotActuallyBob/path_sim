//
// Created by Mikael on 22/02/2024.
//

#ifndef PATH_SIM_PRIORITYQUEUE_H
#define PATH_SIM_PRIORITYQUEUE_H


#include <map>
#include "Vertex.h"

class PriorityQueue {
public:
    PriorityQueue();
    void AddVertex(unsigned int priority, Vertex* vertex);
    void RemoveVertex(Vertex* vertex);
    Vertex* GetTop();
    bool IsEmpty();
private:
    std::map<Vertex*, unsigned int> vertices;
};


#endif //PATH_SIM_PRIORITYQUEUE_H
