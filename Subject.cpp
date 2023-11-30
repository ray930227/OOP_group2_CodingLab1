#include "Subject.h"

Subject::Subject(){
    this->name="";
    this->type="";
    this->time={};
}

Subject::Subject(std::string name, std::string type, std::vector<int> time){
    this->name=name;
    this->type=type;
    this->time=time;
}

void Subject::setName(std::string name){
    this->name=name;
}

void Subject::setType(std::string type){
    this->type=type;
}

void Subject::setTime(std::vector<int> time){
    this->time=time;
}

std::string Subject::getName(){
    return name;
}

std::string Subject::getType(){
    return type;
}

std::vector<int> Subject::getTime(){
    return time;
}