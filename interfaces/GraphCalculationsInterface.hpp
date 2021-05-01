//
// Created by Andrei Cristea on 2021. 04. 26..
//

#ifndef LIS_GRAPHCALCULATIONSINTERFACE_HPP
#define LIS_GRAPHCALCULATIONSINTERFACE_HPP
#include <vector>
#include "GraphInterface.hpp"
#include "../enums/ShortestPathFunctionEnum.h"

class GraphCalculationsInterface: public GraphInterface
{
public:
    virtual int longestIncreasingSubsequenceLength() const = 0;
    virtual std::vector<int> shortestPathArray(int& initial, int& last) const = 0;
    virtual int shortestPathLength(int& initial, int& last) const = 0;
    virtual ~GraphCalculationsInterface() {};
};


#endif //LIS_GRAPHCALCULATIONSINTERFACE_HPP
