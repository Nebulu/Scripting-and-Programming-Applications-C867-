//Step D1
class Student {
public:
	int studentID;
	string firstName;
	string lastName;
	string emailAddr;
	int age;
	int daystoFinish;
	string degreeProgram;
}

//Step D.1
Student::Student() {
	Student::studentID = "";
	Student::firstName = "";
	Student::lastName = "";
	Student::email = "";
	Student::age = -1;
	Student::daysInCourse = { -1,-1,-1 };
	Student::degree = DegreeProgram::SOFTWARE;
}

//Step D.2.d
Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmail, int newAge, vector<int> newDaysInCourse, DegreeProgram newDegree) {
	Student::studentID = newStudentID;
	Student::firstName = newFirstName;
	Student::lastName = newLastName;
	Student::email = newEmail;
	Student::age = newAge;
	Student::daysInCourse = newDaysInCourse;
	Student::degree = newDegree;
}

//destructor
Student::~Student() {}

//Step D.2.a
string Student::getStudentID() {
	return Student::studentID;
}
string Student::getFirstName() {
	return Student::firstName;
}
string Student::getLastName() {
	return Student::lastName;
}
string Student::getEmail() {
	return Student::email;
}
int Student::getAge() {
	return Student::age;
}
vector<int> Student::getDaysInCourse() {
	return Student::daysInCourse;
}
DegreeProgram Student::getDegree() {
	return Student::degree;
}

//Step D.2.b
void Student::setStudentID(string newStudentID)
{
	Student::studentID = newStudentID;
}
void Student::setFirstName(string newFirstName) {
	Student::firstName = newFirstName;
}
void Student::setLastName(string newLastName) {
	Student::lastName = newLastName;
}
void Student::setEmail(string newEmail) {
	Student::email = newEmail;
}
void Student::setAge(int newAge) {
	Student::age = newAge;
}
void Student::setDaysInCourse(vector<int> newDaysInCourse) {
	Student::daysInCourse = newDaysInCourse;
}
void Student::setDegree(DegreeProgram newDegree) {
	Student::degree = newDegree;
}

//converts a DegreeProgram enum to a string, used in Student::Print
string Student::getDegreeProgramName() {
	switch (getDegree()) {
	case DegreeProgram::SECURITY:
		return "Security";
	case DegreeProgram::NETWORK:
		return "Network";
	case DegreeProgram::SOFTWARE:
		return "Software";
	default:
		return "ERROR";
	}
}

//Step D.2.e
void Student::print() {
	cout << getStudentID();
	cout << "\t" << "First Name: ";
	cout << getFirstName();
	cout << "\t" << "Last Name: ";
	cout << getLastName();
	cout << "\t" << "Age: ";
	cout << getAge();
	cout << "\t" << "daysInCourse: ";

	//format the age in the following format: {35, 40, 55}
	string formattedAge = "{";
	int i = 1;
	for (auto itr : getDaysInCourse()) {
		if (i == getDaysInCourse().size()) {
			formattedAge = formattedAge + to_string(itr);
		}
		else {
			formattedAge = formattedAge + to_string(itr) + ", ";
		}
		i++;
	}
	formattedAge = formattedAge + "}";

	cout << formattedAge;
	cout << " Degree Program: ";
	cout << getDegreeProgramName();
	cout << endl;
}