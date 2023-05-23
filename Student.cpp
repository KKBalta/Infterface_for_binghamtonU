// Student.cpp

#include "Student.h"
#include <iostream>
using namespace std;
// Constructor
Student::Student() {
    name = "";
    bnum = "";
    Id = "";
}

// Constructor with arguments
Student::Student(std::string newName, std::string newBnum, std::string newId) {
    name = newName;
    bnum = newBnum;
    Id = newId;
}

// Destructor
Student::~Student() {}

// Getter functions
std::string Student::getName() {
    return name;
}

std::string Student::getBnum() {
    return bnum;
}

std::string Student::getId() {
    return Id;
}

// Setter functions
void Student::setName(std::string newName) {
    name = newName;
}

void Student::setBnum(std::string newBnum) {
    bnum = newBnum;
}

void Student::setId(std::string newId) {
    Id = newId;
}
void Student::printInfo() {
    cout << "Name: " << name << endl;
    cout << "BuID: " << bnum << endl;
    cout << "Id: " << Id << endl;
    
}