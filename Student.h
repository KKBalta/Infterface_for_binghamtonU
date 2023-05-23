#ifndef STUDENT_H
#define STUDENT_H

#include <string>


class Student {
private:
    std::string name;
    std::string bnum;
    std::string Id;

public:
    // Constructors
    Student();
    Student(std::string n, std::string a, std::string m);

    // Destructor
    ~Student();

    // Getter functions
    std::string getName();
    std::string getBnum();
    std::string getId();

    // Setter functions
    void setName(std::string n);
    void setBnum(std::string a);
    void setId(std::string m);

    // Other member functions
    void printInfo();
};

#endif