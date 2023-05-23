#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <regex>
#include <sstream>
#include <cctype>
#include "Student.h"
#include "Course.h"
using namespace std;
	
	bool dubcheckincourse(string num,int currsize,Course* list){
		for(int k = 0; k <currsize; k++){
			if(list[k].dubcheck(num)) return true;
		}
		return false;
	}
	
	void deleteStudent(int pos, int& currsize, Student*& list) {
    // Create a new array with reduced size
    Student* new_arr = new Student[currsize - 1];
    // Copy the elements from the old array up to the delete position
    for (int i = 0; i < pos; i++) {
        new_arr[i] = list[i];
    }
    // Copy the remaining elements from the old array to the new array, skipping the deleted element
    for (int i = pos + 1; i < currsize; i++) {
        new_arr[i-1] = list[i];
    }
    // Delete the old array
    delete[] list;
    // Update the pointer to the new array
    list = new_arr;
    // Decrement the array size
    currsize--;
}

	void insertStudent(int pos, Student value, int& currsize, Student*& list) {
    // Create a new array with increased size
    Student* new_arr = new Student[currsize + 1];
    // Copy the elements from the old array up to the insert position
    for (int i = 0; i < pos; i++) {
        new_arr[i] = list[i];
    }
    // Insert the new value at the given position
    new_arr[pos] = value;
    // Copy the remaining elements from the old array to the new array
    for (int i = pos + 1; i < currsize + 1; i++) {
        new_arr[i] = list[i - 1];
    }
    // Delete the old array
    delete[] list;
    // Update the pointer to the new array
    list = new_arr;
    // Increment the array size
    currsize++;
}
	
	void deleteCourse(int pos, int& currsize, Course*& list) {
    // Create a new array with reduced size
    Course* new_arr = new Course[currsize - 1];
    // Copy the elements from the old array up to the delete position
    for (int i = 0; i < pos; i++) {
        new_arr[i] = list[i];
    }
    // Copy the remaining elements from the old array to the new array, skipping the deleted element
    for (int i = pos + 1; i < currsize; i++) {
        new_arr[i-1] = list[i];
    }
    // Delete the old array
    delete[] list;
    // Update the pointer to the new array
    list = new_arr;
    // Decrement the array size
    currsize--;
}





	void insertCourse(int pos, Course value, int& currsize, Course*& list) {
    // Create a new array with increased size
    Course* new_arr = new Course[currsize + 1];
    // Copy the elements from the old array up to the insert position
    for (int i = 0; i < pos; i++) {
        new_arr[i] = list[i];
    }
    // Insert the new value at the given position
    new_arr[pos] = value;
    // Copy the remaining elements from the old array to the new array
    for (int i = pos + 1; i < currsize + 1; i++) {
        new_arr[i] = list[i - 1];
    }
    // Delete the old array
    delete[] list;
    // Update the pointer to the new array
    list = new_arr;
    // Increment the array size
    currsize++;
}

	bool CourseCrnCheck(string value, const int& currsize, Course*& list){
		
		for (int i  = 0 ; i<currsize; i++){
			
			if(value == list[i].getcrn()){
				return false;
			}
		}
		return true;
	}

	bool StudentBnumCheck(string value, const int& currsize, Student*& list){
		
		for (int i  = 0 ; i<currsize; i++){
			
			if(value == list[i].getBnum()){
				return false;
			}
		}
		return true;
	}

	bool idCheck(string id)
		{
			if (!id.empty()) {
			char firstChar = id[0];
			return std::isalpha(firstChar);
		}
		return false;
		}
	bool BnumberCheck(string num)
		{
			if(num[0] != 'B'){return false;}
			num.erase(0,1);
			int digits = std::stoi(num);
			if(digits>10000000 && digits<99999999){return true;}
			return false;
		}
	bool depCheck(string dep){
		int size = dep.length();
		for (char c : dep) {
			if (!std::isupper(c)) {
				return false;
			}
		}
		if(size >= 2 && size<=4){
			return true;
		}
		else{return false;}
		
	}

	bool depNumCheck(string number){
		int num = std::stoi(number);
		if(num>100 && num <700){return true;}
		else{return false;}
	}

	bool crnCheck(string number){

	int num = std::stoi(number);
	if(num>100000 && num<999999)
		{
			return true;
		}
		else return false;
	}


int main(int argc, char **argv) {

    cout << "Enter [ build <crn> <department> <number> <name>" << endl;
	cout << "      cancel <crn>" << endl;
	cout << "      enroll <bnumber> <userid> <first> <last>" << endl;
	cout << "      add <bnumber> <crn>" << endl;
	cout << "      drop <bnumber> <crn>"<< endl;
	cout << "      roster <crn>"<< endl;
	cout << "      schedule <bnumber>" << endl;
	cout << "      quit]"<< endl;
	int sizecourse = 1;
	int sizestudent = 1;
	Course* courseList = new Course[sizecourse];
	Student* studentList = new Student[sizestudent];
	while (true)
    {
        cout <<": ";
        string commandAsline;
        getline(cin,commandAsline);

	vector<string> separatedCommand;
	std :: stringstream ss(commandAsline);
	string tmp;
	while (ss >> tmp) {
        separatedCommand.push_back(tmp);
    }


	if(!(separatedCommand.front().compare("quit")) ||!(separatedCommand.front().compare("roster"))||!(separatedCommand.front().compare("build"))||!(separatedCommand.front().compare("cancel"))||!(separatedCommand.front().compare("enroll"))||!(separatedCommand.front().compare("add"))||!(separatedCommand.front().compare("drop"))||!(separatedCommand.front().compare("schedule"))){
		
		if (separatedCommand[0] == "quit")
		{
			return 0;
		}

		if ( separatedCommand[0]== "build")
		{
				
			if(separatedCommand.size() < 5)
			{
				cout << "Too few arugments" << endl;
			}
			
			else if(!(crnCheck(separatedCommand[1])))
			{
				cout<<"Input Error: illegal CRN"<< endl;
			}

			else if(!(depCheck(separatedCommand[2])))
			{
				cout<<"Input Error: illegal department" << endl;
			}
			else if(!(depNumCheck(separatedCommand[3])))
			{
				cout<<"Input Error: illegal course number"<< endl;
			}
			else if(!(CourseCrnCheck(separatedCommand[1],sizecourse,courseList)))
			{
				cout<<"Fail: cannot build course "<<separatedCommand.at(2)<< separatedCommand.at(3)<< " (CRN: " << separatedCommand.at(1)<<"): "<<endl;
			}
			else
			{
				cout<<"Succsess: " <<separatedCommand.at(0) << " course "<< separatedCommand.at(2) <<  separatedCommand.at(3) << " (CRN: " << separatedCommand.at(1)<<"): "  ;
				string Coursename = "";
				for(int j = 4; j < separatedCommand.size(); j++)
				{
					Coursename = Coursename+separatedCommand[j]+" ";
					cout << separatedCommand[j] << " ";
				}
				cout << endl;
				Course newCourse(separatedCommand.at(1),separatedCommand.at(2),separatedCommand.at(3),Coursename);
				insertCourse(sizecourse-1,newCourse,sizecourse,courseList);
				courseList[sizecourse-2].printInfo();
				cout << sizecourse << endl;
				
			}
		}

		if (!(separatedCommand.front().compare("cancel")))
		{	
			if(CourseCrnCheck(separatedCommand[1],sizecourse,courseList)){
				cout << "Fail: cannot cancel course, CRN does not exist"<< endl;
			}
			else if(separatedCommand.size() > 2)
			{
				cout << "Warning: ignoring extra argument(s)" <<endl;
				for(int j = 0; j < sizecourse; j++){
					if(courseList[j].getcrn()== separatedCommand.at(1)){
						deleteCourse(j,sizecourse,courseList);
						courseList[0].printInfo();
						cout << sizecourse << endl;
					}
				}
				cout << "Success: cancelled course " << separatedCommand.at(1) << endl;

			}
			else if (separatedCommand.size() <= 1){
				cout << "CRN is missing !!" << endl;
			}
			else if(!(crnCheck(separatedCommand[1])))
			{
				cout<<"Input Error: illegal CRN"<< endl;
			}
			
			else
			{
				for(int j = 0; j < sizecourse; j++){
					if(courseList[j].getcrn()== separatedCommand.at(1)){
						deleteCourse(j,sizecourse,courseList);
					}
				}
				cout << "Success: cancelled course " << separatedCommand.at(1) << endl;
	
			}
		}
		
		if (!(separatedCommand.front().compare("enroll")))
		{
			if(separatedCommand.size() < 5)
			{
				cout << "Input Error: too few arguments " <<endl;
			}else if (!(BnumberCheck(separatedCommand[1])))
			{
				cout << "Fail: cannot enroll student, B Number is not correct syntax"<< endl;
			}
			else if (!(idCheck(separatedCommand[2])))
			{
				cout << "fail: Illegal ID" << endl;
			}
			else if(!(StudentBnumCheck(separatedCommand[1],sizestudent,studentList)))
			{
				cout << "Fail: cannot enroll student, B Number exists"<< endl;
			}
			else
			{	
				string Studentname= "";
				for(int j = 3; j < separatedCommand.size(); j++)
				{
					Studentname = Studentname+separatedCommand[j]+" ";
				}
				Student newStudent(Studentname,separatedCommand[1],separatedCommand[2]);
				insertStudent(sizestudent-1,newStudent,sizestudent,studentList);
				studentList[sizestudent-2].printInfo();
				cout << sizestudent << endl;

				cout << "Success: enroll student " << separatedCommand.at(1)<< " (" <<separatedCommand.at(2)<< ") " <<separatedCommand.at(4) << ", " << separatedCommand.at(3) << endl;
				
				
			}
		}

		if (!(separatedCommand.front().compare("add")))
		{
			if(separatedCommand.size() != 3)
			{
				cout << "invalid" <<endl;
			}
			else if (!(BnumberCheck(separatedCommand[1])))
			{
				cout << "Fail: cannot add student, B Number is not correct syntax"<< endl;
			}
			else if(StudentBnumCheck(separatedCommand[1],sizestudent,studentList))
			{
				cout << "Fail: cannot add student, B Number does not exists"<< endl;
			}
			else if(CourseCrnCheck(separatedCommand[2],sizecourse,courseList)){
				cout << "Fail: cannot add course, CRN does not exist"<< endl;
			}
			else if(!(crnCheck(separatedCommand[2])))
			{
				cout<<"Input Error: illegal CRN"<< endl;
			}
			else if(dubcheckincourse(separatedCommand[1],sizecourse,courseList)){
				cout << "Fail: cannot add, student " << separatedCommand[1] <<" already enrolled in course "<<separatedCommand[2] <<endl;
			}
			else
			{
				for (int i  = 0 ; i<sizecourse; i++){
					if(separatedCommand[2] == courseList[i].getcrn()){
						for(int j = 0; j < sizestudent; j++)
						{	
							if(separatedCommand[1] == studentList[j].getBnum()){
								courseList[i].addToList(studentList[j]);
							}
								
						}
					}
				}
		
				cout << "add student " << separatedCommand.at(1) << " into course " << separatedCommand.at(2) << endl;
				
			}
		}
		if (!(separatedCommand.front().compare("drop")))
		{
			if(separatedCommand.size() != 3)
			{
				cout << "invalid" <<endl;
			}
			else if (!(BnumberCheck(separatedCommand[1])))
			{
				cout << "Fail: cannot drop student, B Number is not correct syntax"<< endl;
			}
			else if(StudentBnumCheck(separatedCommand[1],sizestudent,studentList))
			{
				cout << "Fail: cannot drop student, B Number does not exists"<< endl;
			}
			else if(CourseCrnCheck(separatedCommand[2],sizecourse,courseList)){
				cout << "Fail: cannot drop course, CRN does not exist"<< endl;
			}
			else if(!(crnCheck(separatedCommand[2])))
			{
				cout<<"Input Error: illegal CRN"<< endl;
			}
			else if(!(dubcheckincourse(separatedCommand[1],sizecourse,courseList))){
				cout << "Fail: cannot drop, student " << separatedCommand[1] <<" not enrolled in course "<<separatedCommand[2] <<endl;
			}
			else
			{
				for (int i  = 0 ; i<sizecourse; i++){
					if(separatedCommand[2] == courseList[i].getcrn()){
						for(int j = 0; j < sizestudent; j++)
						{
							courseList[i].removeFromList(studentList[j].getBnum());
							cout << courseList[i].getListSize()<< endl;	
						}
					}
				}
				cout << "Success: remove student " << separatedCommand.at(1) << " from course " << separatedCommand.at(2)<< endl;
			}
		}
		if (!(separatedCommand.front().compare("roster")))
		{
			if(separatedCommand.size() != 2)
			{
				cout << "invalid" <<endl;
			}
			else if(!(crnCheck(separatedCommand[1])))
			{
				cout<<"Input Error: illegal CRN"<< endl;
			}
			else
			{	
				for(int i = 0 ; i<sizecourse; i++)
				{
					
					if(courseList[i].getcrn() == separatedCommand[1])
					{
						cout << "CRN: "<<courseList[i].getcrn()<<endl;
						cout << "Students: "<<courseList[i].getListSize()<< endl;
						courseList[i].printList();
						break;
					}
				}
			}
		}
		if (!(separatedCommand.front().compare("schedule")))
		{
			if(separatedCommand.size() != 2)
			{
				cout << "invalid" <<endl;
			}
			else
			{
				cout << "schedule of student " << separatedCommand.at(1) << endl;
			}
		}

		}
		else{cout << "Command not recognized, please try again. "<<endl;}

		// copy paste for guidence
		cout << "Enter [ build <crn> <department> <number> <name>" << endl;
		cout << "      cancel <crn>" << endl;
		cout << "      enroll <bnumber> <userid> <first> <last>" << endl;
		cout << "      add <bnumber> <crn>" << endl;
		cout << "      drop <bnumber> <crn>"<< endl;
		cout << "      roster <crn>"<< endl;
		cout << "      schedule <bnumber>" << endl;
		cout << "      quit]"<< endl;
	} 
    

delete[] courseList;
delete[] studentList;

}
