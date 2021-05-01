//
// Created by Andrei Cristea on 2021. 04. 25..
//

#include "AdjancencyMatrixGraph.h"
#include "../expeptions/GraphExceptions.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <climits>


AdjancencyMatrixGraph::AdjancencyMatrixGraph(const std::vector<int> &graph)
{
    _graphArray = graph;
    for (int i = 0; i < graph.size(); i++)
    {
        std::vector<int> gr;
        for (int j = 0; j < graph.size(); j++)
        {
            gr.push_back(0);
        }
        _adjacencyMatrix.push_back(gr);
    }
}

void AdjancencyMatrixGraph::add(int elem)
{
    _graphArray.push_back(elem);
    std::vector<int> temp;
    if (_adjacencyMatrix.empty())
    {
        _adjacencyMatrix.push_back({0});
    }
    else
    {
        for (int i = 0; i < _adjacencyMatrix.size(); i++) {
            temp.push_back(0);
        }
        _adjacencyMatrix.push_back(temp);
        for (auto & i : _adjacencyMatrix) {
            i.push_back(0);
        }
    }

}

int AdjancencyMatrixGraph::getGraphIndex(int item, bool strict = true) const
{
    auto it = std::find(_graphArray.begin(), _graphArray.end(), item);
    if (it != _graphArray.end())
    {
        int index = std::distance(_graphArray.begin(), it);
        return index;
    }
    if (strict)
    {
        throw AdjancencyMatrixGraphExceptions::NOT_IN_ARRAY;
    }
    else
    {
        return -1;
    }
}

void AdjancencyMatrixGraph::connect(int edgeOne, int edgeTwo, int weight)
{
    try {
        const int edgeOnePosition = getGraphIndex(edgeOne);
        const int edgeTwoPosition = getGraphIndex(edgeTwo);

        if (_adjacencyMatrix[edgeOnePosition][edgeTwoPosition] == 0)
        {
            _adjacencyMatrix[edgeOnePosition][edgeTwoPosition] = weight;
        }
        else
        {
            throw HasAlreadyConnectionException();
        }
    }
    catch (AdjancencyMatrixGraphExceptions e)
    {
        if (e == AdjancencyMatrixGraphExceptions::NOT_IN_ARRAY)
        {
            throw WrongConnectionParameterException(edgeOne, edgeTwo);
        }
    }
}

void AdjancencyMatrixGraph::unConnect(int edgeOne, int edgeTwo)
{
    try
    {
        const int edgeOnePosition = getGraphIndex(edgeOne);
        const int edgeTwoPosition = getGraphIndex(edgeTwo);
        _adjacencyMatrix[edgeOnePosition][edgeTwoPosition] = 0;
    }
    catch (AdjancencyMatrixGraphExceptions e)
    {
        if (e == AdjancencyMatrixGraphExceptions::NOT_IN_ARRAY)
        {
            throw  WrongConnectionParameterException(edgeOne, edgeTwo);
        }
    }
}

void AdjancencyMatrixGraph::empty()
{
    _graphArray.clear();
    _adjacencyMatrix.clear();
}

void AdjancencyMatrixGraph::print() const
{
    using std::cout;
    using std::endl;

    if (_adjacencyMatrix.empty())
    {
        cout << "{}" << endl;
    }
    else
    {
        cout << "{" << endl;
        for (const auto & i : _adjacencyMatrix)
        {
            for (auto item : i)
            {
                cout << " " << item << " ";
            }
            cout << endl;
        }
        cout << "}" << endl;
    }
}

int AdjancencyMatrixGraph::longestIncreasingSubsequenceLength() const
{
    std::vector<int> lengths;
//    for (auto )
}


std::map<int, std::pair<int, int>> AdjancencyMatrixGraph::dijksrta(int& initial) const
{
    std::map<int, std::pair<int, int>> visited;
    std::map<int, std::pair<int, int>> unvisited;
    std::vector<int> h;
    for (int i = 0; i < _graphArray.size(); i++)
    {
        std::pair<int, int> temp;
        if (initial == _graphArray[i])
        {
            temp.first = 0;
        }
        else
        {
            temp.first = INT_MAX;
        }
        temp.second = INT_MIN;
        unvisited.insert(std::pair<int, std::pair<int, int>>(_graphArray[i], temp));
    }

    while (!unvisited.empty())
    {
        std::pair<int, std::pair<int, int>> currentNode;
        bool changed = false;
        int lowest = INT_MAX;
        for (auto it = unvisited.begin(); it != unvisited.end(); it++)
        {
            if (it->second.first < lowest)
            {
                changed = true;
                int number = it->first;
                std::pair<int, int> temp = unvisited.at(number);
                currentNode.first = number;
                currentNode.second = temp;
                break;
            }
        }

        if (!changed)
        {
            currentNode = *(unvisited.begin());
        }

        for (auto it = unvisited.begin(); it != unvisited.end(); it++)
        {
            int currentIndex = getGraphIndex(currentNode.first, false);
            int neighbourIndex = getGraphIndex(it->first);
            if (currentIndex == -1)
            {
                break;
            }
            if (
                    _adjacencyMatrix[currentIndex][neighbourIndex] > 0 &&
                    _adjacencyMatrix[currentIndex][neighbourIndex] < it->second.first
                    )
            {
                it->second.first = _adjacencyMatrix[currentIndex][neighbourIndex];
                it->second.second = currentNode.first;
            }
        }
        visited.insert(currentNode);
        unvisited.erase(currentNode.first);
    }

    return visited;
}

int AdjancencyMatrixGraph::shortestPathLength(int &initial, int &last) const
{
    int cnt = 0;
    bool foundInit = false;
    std::map<int, std::pair<int, int>> dj(dijksrta(initial));
    for (auto it = dj.begin(); it != dj.end() && it->first != last; it++) {
        if (it->first == initial)
        {
            foundInit = true;
        }
        if (foundInit)
        {
            cnt++;
        }
        if (it->first == last) {
            break;
        }
    }
    return cnt;
}

std::vector<int> AdjancencyMatrixGraph::shortestPathArray(int &initial, int &last) const
{
    std::vector<int> vertices;
    bool foundInit = false;
    std::map<int, std::pair<int, int>> dj = dijksrta(initial);
    for (auto it = dj.begin(); it != dj.end(); it++)
    {
        if (it->first == initial)
        {
            foundInit = true;
        }

        if (foundInit)
        {
            vertices.push_back(it->first);
        }

        if (it->first == last)
        {
            break;
        }
    }

    return vertices;
}