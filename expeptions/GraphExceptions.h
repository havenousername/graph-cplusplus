//
// Created by Andrei Cristea on 2021. 04. 26..
//

#ifndef LIS_GRAPHEXCEPTIONS_H
#define LIS_GRAPHEXCEPTIONS_H
#include <exception>
#include <string>
#include <sstream>
#include <iostream>

class HasAlreadyConnectionException : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return "These elements are already connected with each other";
    }
};


class WrongConnectionParameterException: public std::exception
{
private:
    int _first;
    int _second;
public:
    WrongConnectionParameterException(int first, int second = NULL): std::exception()
    {

        _first = first;
        _second = second;
    }
    const char * what() const noexcept override
    {
        const std::string params = _second == NULL ? std::to_string(_first) : std::to_string(_first) + ", " + std::to_string(_second);
        const std::string text = "One of edges or both " + params + " is/are not included into graph";
        char* msg = new char[text.size() + 1];
        std::copy(text.begin(), text.end(), msg);
        msg[text.size()] = '\0';
        return msg;
    }
};

#endif //LIS_GRAPHEXCEPTIONS_H
