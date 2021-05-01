//
// Created by Andrei Cristea on 2021. 04. 25..
//

#ifndef LIS_ADJANCENCYMATRIXGRAPH_H
#define LIS_ADJANCENCYMATRIXGRAPH_H


#include "../interfaces/GraphInterface.hpp"
#include "../interfaces/GraphCalculationsInterface.hpp"
#include <vector>
#include <map>

class AdjancencyMatrixGraph: public GraphCalculationsInterface
{
public:
    AdjancencyMatrixGraph(): GraphCalculationsInterface()
    {
        _graphArray.clear();
    };
    AdjancencyMatrixGraph(const std::vector<int>& graph) ;
    void add(int elem) override;
    void connect(int edgeOne, int edgeTwo, int weight) override;
    void unConnect(int edgeOne, int edgeTwo) override;
    void empty() override;
    void print() const override;

    int longestIncreasingSubsequenceLength() const override;
    std::vector<int> shortestPathArray(int& initial, int& last) const override;
    int shortestPathLength(int& initial, int& last) const override;
private:
    enum AdjancencyMatrixGraphExceptions {NOT_IN_ARRAY};
    std::vector<int> _graphArray;
    std::vector<std::vector<int>> _adjacencyMatrix;
    int getGraphIndex(int item, bool strict) const;
    std::map<int, std::pair<int, int>> dijksrta(int& initial) const;
};


#endif //LIS_ADJANCENCYMATRIXGRAPH_H
