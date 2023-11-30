#include "ClassTable.cpp"
#include <bits/stdc++.h>

std::vector<ClassTable> table;
void mode1();
void mode2();
void mode3();
void mode4();
void addClassTable();//新增一個新的課表
void showClassTable(std::string studentID);//印出某人的課表
int findTable(std::string studentID);//印出某人的課表在table裡的索引
void addSubjectToClassTable(std::string studentID);//新增課程到某人的課表裡
std::string inpputStudentID();//輸入學號的function
void showScore(std::string studentID);//印出某人的學分
void delSubjectFromClassTable(std::string studentID);//刪除某人的課表裡的某課程
void printSubjectTime();//輸出時間對照表

int main() {
    bool check=true;
    while(check){ 
        system("cls");//清空終端機畫面
        //------------------------------------------------------
        //根據輸入執行模式
        std::cout<<"1.Add new class table\n";
        std::cout<<"2.Show someone's class table and score\n";
        std::cout<<"3.Add subject to someone's class table\n";
        std::cout<<"4.Del subject from someone's class table\n";
        std::cout<<"5.Exit\n";
        std::cout<<"choose mode:";
        int mode;
        std::cin>>mode;
        while(mode<1 || mode>5){
            std::cout<<"Incorrect input\n";
            std::cout<<"choose mode again:";
            std::cin>>mode;
        }
        if(mode==1) mode1();
        else if(mode==2) mode2();
        else if(mode==3) mode3();
        else if(mode==4) mode4();
        else if(mode==5) break;
        //------------------------------------------------------

        //------------------------------------------------------
        //判斷是否繼續執行
        std::cout<<"contiune?(Y/N)";
        std::string temp;
        std::cin>>temp;
        check = temp=="Y" ? true:false;
        //------------------------------------------------------
    }
    system("pause");//讓程式暫停
}

void mode1(){
    addClassTable();
}

void mode2(){
    if(table.empty()){
        std::cout<<"No one's ClassTable has been saved yet.\n";
        return;
    }
    std::string studentID=inpputStudentID();
    system("cls");
    std::cout<<"\033[1m"<<studentID<<"'s ClassTable:\033[0m \n";
    std::cout<<"\033[31mRequired\033[0m's subject is red.\n";
    std::cout<<"\033[34mElective\033[0m's subject is blue.\n";
    showClassTable(studentID);
    showScore(studentID);
}

void mode3(){
    if(table.empty()){
        std::cout<<"No one's ClassTable has been saved yet.\n";
        return;
    }
    std::string studentID=inpputStudentID();
    addSubjectToClassTable(studentID);
}

void mode4(){
    if(table.empty()){
        std::cout<<"No one's ClassTable has been saved yet.\n";
        return;
    }
    std::string studentID=inpputStudentID();
    delSubjectFromClassTable(studentID);
}

void addClassTable(){
    std::string studentID;
    std::cout<<"please enter the studentID:";
    std::cin>>studentID;
    while(findTable(studentID)!=-1){
        std::cout<<studentID<<"'s ClassTable has been saved.\n";
        std::cout<<"please enter the studentID again:";
        std::cin>>studentID;
    }
    ClassTable temp(studentID);
    table.push_back(temp);
}

void showClassTable(std::string studentID){
    table[findTable(studentID)].printTable();
}

int findTable(std::string studentID){
    for(int i=0;i<table.size();i++){
        if(table[i].getStudentID()==studentID) return i; 
    }
    return -1;
}

void addSubjectToClassTable(std::string studentID){
    int index=findTable(studentID);
    std::string name;
    std::string type;
    std::vector<int> time;
    std::cout<<"please enter the subject's name:";
    std::cin>>name;
    std::cout<<"please enter the subject's type(R:Required/E:Elective):";
    std::cin>>type;

    printSubjectTime();
    std::cout<<"please enter the subject's time(enter -1 to end):";
    int t;
    std::cin>>t;
    while(t==-1){
        std::cout<<"subject's time need at least one hour\n";
        std::cout<<"please enter the subject's time again(enter -1 to end):";
        std::cin>>t;
    }
    while(t!=-1){
        time.push_back(t);
        std::cout<<"please enter the subject's time again(enter -1 to end):";
        std::cin>>t;
    }
    Subject temp(name,type,time);
    table[index].addSubject(temp);
}

std::string inpputStudentID(){
    std::string studentID;
    std::cout<<"please enter the studentID:";
    std::cin>>studentID;
    while(findTable(studentID)==-1){
        std::cout<<"No such student found.\nplease enter the studentID again:";
        std::cin>>studentID;
    }
    return studentID;
}

void showScore(std::string studentID){
    int index=findTable(studentID);
    std::cout<<"RequiredSubject's score:"<<table[index].calculateRequiredScore()<<std::endl;
    std::cout<<"ElectiveSubject's score:"<<table[index].calculateElectiveScore()<<std::endl;
}

void delSubjectFromClassTable(std::string studentID){
    int index=findTable(studentID);
    std::string name;
    std::cout<<"please enter the subject's name:";
    std::cin>>name;
    table[index].dropClasses(name);
}

void printSubjectTime(){
    //把時間對照的數字當作名子放進ClassTable
    //再使用ClassTable的printTable來輸出
    ClassTable tempClassTable("temp");
    for(int i=0;i<STUDY_HOURS_PRE_DAY;i++){
        for(int j=0;j<STUDY_DAYS_PRE_WEEK;j++){
            std::string tempString="";
            if(i*5+j>9) tempString.push_back(char((i*5+j)/10)+'0'); //實位數(10以下不顯示)
            tempString.push_back(char((i*5+j)%10)+'0'); //個位數
            Subject tempSubject(tempString,"T",{i*5+j});
            tempClassTable.addSubject(tempSubject);
        }
    }
    tempClassTable.printTable();
}
