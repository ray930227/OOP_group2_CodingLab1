#include "ClassTable.h"
#include<iostream>
#include <vector>
#include <iomanip>

ClassTable::ClassTable(std::string studentID){
    this->studentID=studentID;
}

void ClassTable::addSubject(Subject subject) {
    std::vector<int> time=subject.getTime();
    for(int i=0;i<time.size();i++){
        if(classes[time[i]/STUDY_DAYS_PRE_WEEK][time[i]%STUDY_DAYS_PRE_WEEK].getName()!=""){
            std::cout<<"This subject overlaps with \033[1m"
                     <<classes[time[i]/STUDY_DAYS_PRE_WEEK][time[i]%STUDY_DAYS_PRE_WEEK].getName()
                     <<"\033[0m\n";
            return;
        }
    }
    for(int i=0;i<time.size();i++){
        classes[time[i]/STUDY_DAYS_PRE_WEEK][time[i]%STUDY_DAYS_PRE_WEEK]=subject;
    }
}

void ClassTable::getClasses(Subject classes[STUDY_HOURS_PRE_DAY][STUDY_DAYS_PRE_WEEK]){
    for(int i=0;i<STUDY_HOURS_PRE_DAY;i++){
        for(int j=0;j<STUDY_DAYS_PRE_WEEK;j++){
            classes[i][j]=this->classes[i][j];
        }
    }
}

std::string ClassTable::getStudentID(){
    return studentID;
}

int ClassTable::calculateElectiveScore(){
    int result=0;
    for(int i=0;i<STUDY_HOURS_PRE_DAY;i++){
        for(int j=0;j<STUDY_DAYS_PRE_WEEK;j++){
            if(classes[i][j].getType()=="E") result++;
        }
    }
    return result;
}

int ClassTable::calculateRequiredScore() {
    int result=0;
    for(int i=0;i<STUDY_HOURS_PRE_DAY;i++){
        for(int j=0;j<STUDY_DAYS_PRE_WEEK;j++){
            if(classes[i][j].getType()=="R") result++;
        }
    }
    return result;
}

void ClassTable::dropClasses(std::string name){
    bool check=true;
    for(int i=0;i<STUDY_HOURS_PRE_DAY;i++){
        for(int j=0;j<STUDY_DAYS_PRE_WEEK;j++){
            if(classes[i][j].getName()==name) {
                classes[i][j].setName("");
                classes[i][j].setType("");
                classes[i][j].setTime({});
                check=false;
            }
        }
    }
    if(check)
        std::cout<<"Class not found.\n";
}

void ClassTable::printTable(){
    int width=5;
    for(int i=0;i<STUDY_HOURS_PRE_DAY;i++)
        for(int j=0;j<STUDY_DAYS_PRE_WEEK;j++)
            if(classes[i][j].getName().size()>=width)
                width=classes[i][j].getName().size()+1;

    printLine(width);
    std::string week[5]={"Mon.","Tue.","Wed.","Thr.","Fri."};
    std::cout<<"|";
    std::cout<<std::setw(3)<<std::left<<"";
    for(int i=0;i<STUDY_DAYS_PRE_WEEK;i++)
        std::cout<<"|"<<std::setw(width)<<std::left<<week[i];
    std::cout<<"|"<<std::endl;
    
    printLine(width);

    for(int i=0;i<STUDY_HOURS_PRE_DAY;i++){
        std::cout<<"|"<<std::setw(3)<<std::left<<i+1;
        for(int j=0;j<STUDY_DAYS_PRE_WEEK;j++){
            std::cout<<"|";
            std::string tempType=classes[i][j].getType();
            if(tempType=="R") std::cout<<"\033[31m";
            else if(tempType=="E") std::cout<<"\033[34m";
            else if(tempType=="T")std::cout<<"\033[33m";
            std::cout<<std::setw(width)<<std::left<<classes[i][j].getName()<<"\033[0m";
        }
        std::cout<<"|"<<std::endl;
        printLine(width);
    }
}

void ClassTable::printLine(int width){
    std::cout<<"+---";
    for(int i=0;i<STUDY_DAYS_PRE_WEEK;i++){
        std::cout<<"+";
        for(int j=0;j<width;j++)
            std::cout<<"-";
    }
    std::cout<<"+"<<std::endl;
}
 