Course Management System
The Course Management System is a command-line program that allows you to manage courses and students enrolled in those courses. It provides functionality to build courses, cancel courses, enroll students, add students to courses, drop students from courses, view course rosters, view student schedules, and quit the program.

Usage
The Course Management System supports the following commands:

build <crn> <department> <number> <name>: Builds a new course with the specified CRN, department, course number, and name.
cancel <crn>: Cancels a course with the specified CRN.
enroll <bnumber> <userid> <first> <last>: Enrolls a student with the specified B-number, user ID, first name, and last name.
add <bnumber> <crn>: Adds a student with the specified B-number to the course with the specified CRN.
drop <bnumber> <crn>: Drops a student with the specified B-number from the course with the specified CRN.
roster <crn>: Displays the roster of the course with the specified CRN.
schedule <bnumber>: Displays the schedule of the student with the specified B-number.
quit: Exits the program.
Code Structure
The code consists of the following files:

main.cpp: Contains the main function and the implementation of the command-line interface for the Course Management System.
Student.cpp and Student.h: Define the Student class, which represents a student and stores information about their name, B-number, and ID.
Course.cpp and Course.h: Define the Course class, which represents a course and stores information about its CRN, department, course number, name, and the list of students enrolled in the course.
Getting Started
To compile and run the Course Management System, follow these steps:

Ensure that you have a C++ compiler installed on your system.

Download the source code files to your local machine.

Compile the code using the following command:

Copy code
g++ -o main main.cpp Student.cpp Course.cpp
Run the executable using the following command:

Copy code
./main
Contributing
Contributions to the Course Management System are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request on the project's GitHub repository.

License
The Course Management System is released under the MIT License. Feel free to use, modify, and distribute the code as per the terms of the license.
