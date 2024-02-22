cmake_minimum_required(VERSION 3.27)
project(path_sim)

set(CMAKE_CXX_STANDARD 17)

add_executable(path_sim main.cpp
        Game.cpp
        Game.h
        Window.cpp
        Window.h
        Vertex.cpp
        Vertex.h
        Map.cpp
        Map.h
        Dijkstra.cpp
        Dijkstra.h
        PriorityQueue.cpp
        PriorityQueue.h
        Input.h
        Input.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/repos/lib/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/repos/lib/SFML-2.6.1/include)


target_link_libraries(path_sim sfml-system sfml-window sfml-graphics sfml-audio)
