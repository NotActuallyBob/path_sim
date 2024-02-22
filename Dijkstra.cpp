//
// Created by Mikael on 22/02/2024.
//

#include "Dijkstra.h"
#include "PriorityQueue.h"
#include <map>

Dijkstra::Dijkstra(Map &map)
    : map(map), pq(){
    distance = std::map<unsigned int, unsigned int>();
    prev = std::map<unsigned int, int>();

    pVertexStart = nullptr;
    pVertexEnd = nullptr;
    isCalculated = false;
    isSolving = false;
}

void Dijkstra::MarkPath() {
    if(!isCalculated) {
        return;
    }

    map.Clear();

    Vertex* iterate = pVertexEnd;
    while(iterate != pVertexStart) {
        iterate->ColorPath();
        iterate = map.GetById(prev[iterate->GetId()]);
    }
}

void Dijkstra::SetStart(Vertex *start) {
    if(pVertexStart != nullptr && !pVertexStart->IsWall()) {
        pVertexStart->Color(sf::Color::White);
    }
    pVertexStart = start;
    pVertexStart->Color(sf::Color::Green);
}

void Dijkstra::SetEnd(Vertex *end) {
    if(pVertexEnd != nullptr && !pVertexEnd->IsWall()) {
        pVertexEnd->Color(sf::Color::White);
    }
    pVertexEnd = end;
    pVertexEnd->Color(sf::Color::Red);
}

void Dijkstra::InitCalculation() {
    if(pVertexStart == nullptr || pVertexEnd == nullptr || isCalculated) {
        return;
    }

    std::vector<Vertex *> allVertices = map.GetVertices();

    distance[pVertexStart->GetId()] = 0;
    for(auto vertex : allVertices) {
        if(vertex->IsWall()) {
            continue;
        }
        if(vertex != pVertexStart) {
            distance[vertex->GetId()] = INT32_MAX;
            prev[vertex->GetId()] = -1;
        }
        pq.AddVertex(distance[vertex->GetId()], vertex);
    }
    isSolving = true;
    searchedRadius = 1;
}

void Dijkstra::IterateCalculation() {
    Vertex* minVertex = pq.GetTop();
    pq.RemoveVertex(minVertex);
    minVertex->Color(sf::Color::Cyan);
    for(auto it : map.GetNeighbors(minVertex)) {
        unsigned int alt = distance[minVertex->GetId()] + minVertex->GetDistance(*it);
        if(alt < distance[it->GetId()]) {
            distance[it->GetId()] = alt;
            prev[it->GetId()] = minVertex->GetId();
            pq.RemoveVertex(it);
            pq.AddVertex(alt, it);
        }
    }

    if(pq.IsEmpty()){
        isCalculated = true;
        isSolving = false;
        searchedRadius = 0;
    } else {
        if(pq.GetTop()->GetDistance(*pVertexStart) < searchedRadius) {
            IterateCalculation();
        } else {
            searchedRadius++;
        }
    }
}

void Dijkstra::Reset() {
    pVertexStart = nullptr;
    pVertexEnd = nullptr;
    map.Clear();
    isCalculated = false;
    isSolving = false;
    searchedRadius = 0;
}

bool Dijkstra::IsSolving() const {
    return isSolving;
}

bool Dijkstra::IsCalculated() const {
    return isCalculated;
}

void Dijkstra::SetNotCalculated() {
    isCalculated = false;
    searchedRadius = 0;
}
