#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"

class Course {
private:
std::string crn;
std::string dep;
std::string num;
std::string name;
std::vector<Student> myList;

int count; // keep track of number of elements in the array
    public:
        Course();
        // Constructor
        Course(std::string n, std::string a, std::string m, std::string x);
        // Destructor
        ~Course();
        // Getter functions
        std::vector<Student> getList();
        std::string getcrn();
        std::string getdep();
        std::string getnum();
        std::string getname();
        // Setter functions
        void setname(std::string namee);
        void setcrn(std::string n);
        void setdep(std::string a);
        void setId(std::string m);
        
        // Other member functions
        void printInfo();
        void insertStudent(int pos,Student value);
        void addToList(Student value);
        void removeFromList(std::string bnum);
        bool dubcheck(std::string bnum);
        int getListSize();
        void printList();
};

#endif // COURSE_H