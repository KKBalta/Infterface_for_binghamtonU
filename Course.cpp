#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"


using namespace std;

Course::Course() {
    crn = "";
    dep = "";
    num = "";
    name = "";
    // student array cause segmentation fault
    count = 0;
}

Course::Course(std::string n, std::string a, std::string m, std::string x) {
    crn = n;
    dep = a;
    num = m;
    name = x;
    count = 0;
    myList={};
    
}

Course::~Course() {
    
}


// Getter functions
vector<Student> Course::getList()
{
    return myList;    
}
string Course::getcrn() {
    return crn;
}

string Course::getdep() {
    return dep;
}

string Course::getnum() {
    return num;
}

string Course::getname() {
    return name;
}

// Setter functions
void Course::setname(string namee) {
    name = namee;
}

void Course::setcrn(string n) {
    crn = n;
}

void Course::setdep(string a) {
    dep = a;
}

void Course::setId(string m) {
    num = m;
}

// Other member functions
void Course::printInfo() {
    cout << "crn: " << crn << endl;
    cout << "Age: " << dep << endl;
    cout << "Id: " << num << endl;
    cout << "Name: "<< name << endl;
}
 bool Course::dubcheck(string bnum){
    for(int i = 0; i<myList.size(); i++)
    {
        if(myList[i].getBnum()== bnum)
        {
            return true;
        }
    }
    return false;
 }

 void Course::addToList(Student value) {
        myList.push_back(value);
    }

void Course::removeFromList(string bnum) {
    for (int i = 0; i < myList.size(); i++) {
        if (myList[i].getBnum() == bnum) {
            myList.erase(myList.begin() + i);
            return;
        }
    }
}

int Course::getListSize() {
        return myList.size();
    }

void Course::printList() {
    for(int i = 0; i< myList.size(); i++)
    {
        cout << myList[i].getBnum()<<" "<< myList[i].getName()<<endl;
    }
}

