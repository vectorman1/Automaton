//
// Created by boris on 6/7/2020.
//

#ifndef PROJECT2020_STATE_H
#define PROJECT2020_STATE_H

#include <string>
#include <iostream>
#include <utility>

class State
{
private:
    std::string stateName;

public:
    friend std::ostream & operator << (std::ostream &out, const State &state);
    friend std::istream & operator >> (std::istream &in,  State &state);
    friend bool operator==(const State& left, const State& right);

    State(){this->stateName = "EmptyState";}
    explicit State(std::string stateName){this->stateName = std::move(stateName);}
    std::string getStateName(){return this->stateName;}
    void setStateName(std::string name){ this->stateName = std::move(name);}

};

std::istream & operator >> (std::istream &in,  State &state){
    in >> state.stateName;
    return in;
}

std::ostream & operator << (std::ostream &out, const State &state){
    std::cout<<state.stateName;
    return out;
}

bool operator==(const State& left, const State& right){
    return left.stateName == right.stateName;
}

#endif //PROJECT2020_STATE_H
