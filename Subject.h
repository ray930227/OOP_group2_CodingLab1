#ifndef OOP_SUBJECT_H
#define OOP_SUBJECT_H

#include <string>
#include <vector>

class Subject {
private:
    std::string name;
    std::string type;
    std::vector<int> time;
public:
    Subject();
    Subject(std::string name,std::string type,std::vector<int> time);
    void setName(std::string name);
    void setType(std::string type);
    void setTime(std::vector<int> time);

    std::string getName();
    std::string getType();
    std::vector<int> getTime();
};

#endif // OOP_SUBJECT_H
