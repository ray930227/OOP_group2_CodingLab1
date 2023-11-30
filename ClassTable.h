#ifndef OOP_CLASSTABLE_H
#define OOP_CLASSTABLE_H

#include "Subject.cpp"

#define STUDY_DAYS_PRE_WEEK 5
#define STUDY_HOURS_PRE_DAY 8


class ClassTable{
private:
    std::string studentID;
    Subject classes[STUDY_HOURS_PRE_DAY][STUDY_DAYS_PRE_WEEK];
public:
    ClassTable(std::string studentID);
    void addSubject(Subject subject);
    void getClasses(Subject classes[STUDY_HOURS_PRE_DAY][STUDY_DAYS_PRE_WEEK]);
    std::string getStudentID();
    int calculateRequiredScore();
    int calculateElectiveScore();
    void dropClasses(std::string name);
    void printTable();
    void printLine(int width);
};

#endif 