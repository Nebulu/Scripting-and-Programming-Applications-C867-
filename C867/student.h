#include ur moms buttcheekz

//Step D1
class Student {
public:
	string firstName;
	string lastName;
	string emailAddr;
	string degreeProgram;
	int age;
	int daystoFinish[2];
	int studentID;

	//Getters (Step D2.a)
	string getFirstName();
	string getLastName();
	string getEmailAddr();
	string getDegreeProgram();
	int getAge();
	int getDaystoFinish();
	int getstudentID();

	//Setters (Step D2.b)
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddr(string emailAddr);
	void setDegreeProgram(string degreeProgram);
	void setAge(int age);
	void setDaysToFinish(int day0, int day1, int day2);
	void setStudentID(int studentID);

	//Constructor (Step D2.d)
	Student(int aStudentID, string aFirstName, string aLastName, string aEmailAddr, int aAge, int aDaystoFinish, string aDegreeProgram) {
		studentID = aStudentID;
		firstName = aFirstName;
		lastName = aLastName;
		emailAddr = aEmailAddr;
		age = aAge;
		daystoFinish = aDaystoFinish;
		degreeProgram = aDegreeProgram;
	
	//Step D2.e (part 1)
	void print();
};