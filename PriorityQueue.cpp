//
// Created by Mikael on 22/02/2024.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    vertices = std::map<Vertex*, unsigned int>();
}

void PriorityQueue::AddVertex(unsigned int priority, Vertex *vertex) {
    auto it = vertices.find(vertex);
    if(it == vertices.end()) {
        vertices[vertex] = priority;
    } else {
        return;
    }
}

void PriorityQueue::RemoveVertex(Vertex *vertex) {
    auto it = vertices.find(vertex);
    if(it == vertices.end()) {
        return;
    } else {
        vertices.erase(it);
    }
}

Vertex *PriorityQueue::GetTop() {
    Vertex* minVertex = nullptr;
    unsigned int minValue = INT32_MAX;

    for (const auto& pair : vertices) {
        if (pair.second < minValue) {
            minValue = pair.second;
            minVertex = pair.first;
        }
    }

    return minVertex;
}

bool PriorityQueue::IsEmpty() {
    return vertices.empty();
}

