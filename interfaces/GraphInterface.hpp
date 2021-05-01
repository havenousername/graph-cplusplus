//
// Created by Andrei Cristea on 2021. 04. 25..
//

#ifndef LIS_GRAPHINTERFACE_HPP
#define LIS_GRAPHINTERFACE_HPP

class GraphInterface
{
public:
    virtual void add(int elem) = 0;
    virtual void connect(int edgeOne, int edgeTwo, int weight) = 0;
    virtual void unConnect(int edgeOne, int edgeTwo) = 0;
    virtual void empty() = 0;
    virtual void print() const = 0;
    virtual ~GraphInterface() {}
};


#endif //LIS_GRAPHINTERFACE_HPP
