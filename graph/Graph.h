//
// Created by Andrei Cristea on 2021. 04. 25..
//

#ifndef LIS_GRAPH_H
#define LIS_GRAPH_H


#include "../interfaces/GraphInterface.hpp"
#include "../enums/GraphTypeEnum.h"
#include "../graph-representation/AdjancencyMatrixGraph.h"
#include <type_traits>
#include "iostream"

class Graph
{
private:
    GraphInterface *_graph;
    Graph(const Graph& graph);
    Graph operator=(const Graph& graph);

public:
    Graph(GraphTypeEnum e)
    {
        switch (e)
        {
            case GraphTypeEnum::ARRAY_BASED:
                _graph = new AdjancencyMatrixGraph();
                break;
            default:
                break;
        }
    }
    ~Graph()
    {
        delete _graph;
    }

    void add(int elem)
    {
        _graph->add(elem);
    };
    void connect(int verticeOne, int verticeTwo, int weight = 1)
    {
        _graph->connect(verticeOne, verticeTwo, weight);
    };
    void unConnect(int verticeOne, int verticeTwo)
    {
        _graph->unConnect(verticeOne, verticeTwo);
    }
    void print() const
    {
        _graph->print();
    };

    void empty()
    {
        _graph->empty();
    }

    template<typename T>
    T shortestPath(int vertex, int last)
    {
        GraphCalculationsInterface* gr;
        gr = dynamic_cast<GraphCalculationsInterface*>(_graph);
        if constexpr(std::is_integral<T>::value)
        {
            int n = gr->shortestPathLength(vertex, last);
            return n;
        }
        else {
            return gr->shortestPathArray(vertex, last);
        }
    }
};


#endif //LIS_GRAPH_H
