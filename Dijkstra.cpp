//
// Created by Mikael on 22/02/2024.
//

#include "Dijkstra.h"
#include "PriorityQueue.h"
#include <map>

Dijkstra::Dijkstra(Map &map)
    : map(map){
    pVertexStart = nullptr;
    pVertexEnd = nullptr;
}

void Dijkstra::MarkPath() {
    if(pVertexStart == nullptr || pVertexEnd == nullptr) {
        return;
    }

    PriorityQueue pq = PriorityQueue();
    std::map<unsigned int, unsigned int> distance;
    std::map<unsigned int, int> prev;

    std::vector<Vertex *> allVertices = map.GetVertices();

    distance[pVertexStart->GetId()] = 0;
    for(auto vertex : allVertices) {
        if(vertex != pVertexStart) {
            distance[vertex->GetId()] = INT32_MAX;
            prev[vertex->GetId()] = -1;
        }
        pq.AddVertex(distance[vertex->GetId()], vertex);
    }

    while(!pq.IsEmpty()) {
        Vertex* minVertex = pq.GetTop();
        pq.RemoveVertex(minVertex);
        for(auto it : map.GetNeighbors(minVertex)) {
            unsigned int alt = distance[minVertex->GetId()] + minVertex->GetDistance(*it);
            if(alt < distance[it->GetId()]) {
                distance[it->GetId()] = alt;
                prev[it->GetId()] = minVertex->GetId();
                pq.RemoveVertex(it);
                pq.AddVertex(alt, it);
            }
        }
    }

    Vertex* iterate = pVertexEnd;
    while(iterate != pVertexStart) {
        iterate->Color(sf::Color::Yellow);
        iterate = map.GetById(prev[iterate->GetId()]);
    }
}

void Dijkstra::SetStart(Vertex *start) {
    pVertexStart = start;
    pVertexStart->Color(sf::Color::Green);
}

void Dijkstra::SetEnd(Vertex *end) {
    pVertexEnd = end;
    pVertexEnd->Color(sf::Color::Red);
}