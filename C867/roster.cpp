#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::stringstream;
using std::getline;
using std::cout;
using std::end;
using std::endl;
#include "roster.h"

//parses the student data
void Roster::parse(string data) {
	stringstream ss(data);

	//the values which will contain each data type
	string studentID = "", firstName = "", lastName = "", email = "";
	int age = -1, daysInCourse1 = -1, daysInCourse2 = 1, daysInCourse3 = -1;
	DegreeProgram degree = DegreeProgram::SOFTWARE;

	//first delimit the data using the ; as a seperator, which will give us each students data
	while (getline(ss, data, ';'))
	{
		//secondly, we will delimit the data using , as a seperator, which will give us each individual data piece of each student.
		//we will then insert each piece of data into the variables we created above
		stringstream ss(data);
		string individualData;
		int i = 0;
		while (getline(ss, individualData, ',')) {
			switch (i) {
			case 0:
				studentID = individualData;
				break;
			case 1:
				firstName = individualData;
				break;
			case 2:
				lastName = individualData;
				break;
			case 3:
				email = individualData;
				break;
			case 4:
				age = stoi(individualData);
				break;
			case 5:
				daysInCourse1 = stoi(individualData);
				break;
			case 6:
				daysInCourse2 = stoi(individualData);
				break;
			case 7:
				daysInCourse3 = stoi(individualData);
				break;
			case 8:
				if (individualData == "SECURITY") {
					degree = DegreeProgram::SECURITY;
				}
				else if (individualData == "NETWORK") {
					degree = DegreeProgram::NETWORK;
				}
				else if (individualData == "SOFTWARE") {
					degree = DegreeProgram::SOFTWARE;
				}
				break;
			}
			i++;
		}
	}

	//update the roster with the new student
	Roster::add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

//Step E.1
//Creates a new Student object and adds it to the classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	vector<int> daysInCourse;
	daysInCourse.push_back(daysInCourse1);
	daysInCourse.push_back(daysInCourse2);
	daysInCourse.push_back(daysInCourse3);
	classRosterArray[studentsAdded] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
	studentsAdded++;
}

//destructor
//removes the student objects from the heap
Roster::~Roster() {
	int i = 0;
	for (Student* student : classRosterArray) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

//find the student object that belongs to the specified student id
Student* Roster::getStudentObject(string studentID) {
	for (Student* student : classRosterArray) {
		if (student->getStudentID() == studentID) {
			return student;
		}
	}
}

//Removes a specific student specified by studentID from the classRosterArray
void Roster::remove(string studentID) {
	//iterate over each student in the classRosterArray, find the studentID that matches and set it to null
	//method will return if the specified ID was nullified, otherwise outputs an error.
	int i = 0;
	for (Student* student : classRosterArray) {
		if (student != NULL) {
			if (student->getStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				return;
			}
		}
		i++;
	}
	cout << "Student could not be found!" << "\n" << endl;
}

//prints all of the students data by looping over each student object in the classRosterArray and calling printStudentData()
void Roster::printAll() {
	for (auto student : classRosterArray) {
		if (student != NULL) {
			student->print();
		}
	}
	cout << "\n";
}

//prints the average number of days in three courses
void Roster::printAverageDaysInCourse(string studentID) {
	Student* student = getStudentObject(studentID);
	int totalDays = 0, averageDays;
	vector<int> daysInCourse = student->getDaysInCourse();
	for (int days : daysInCourse) {
		totalDays = totalDays + days;
	}
	averageDays = totalDays / daysInCourse.size();
	cout << "Average number of days in three courses: " << averageDays << endl;
}

//prints all of the invalid emails of students
void Roster::printInvalidEmails() {
	cout << "Invalid Emails:" << "\n";
	for (Student* student : classRosterArray) {
		string email = student->getEmail();
		bool containsSpace = false;
		bool containsAt = false;
		bool containsPeriod = false;

		for (char character : email) {
			if (character == ' ') {
				containsSpace = true;
				break;
			}
			else if (character == '@') {
				containsAt = true;
			}
			else if (character == '.') {
				containsPeriod = true;
			}
		}

		if (!containsAt || !containsPeriod || containsSpace) {
			cout << email << "\n";
		}
	}
	cout << "\n";
}

//prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (Student* student : classRosterArray) {
		if (student->getDegree() == degreeProgram) {
			student->print();
		}
	}
	cout << "\n";
}