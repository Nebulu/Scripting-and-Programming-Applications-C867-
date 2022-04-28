#include <iostream>
#include <roster.h>
#include <degree.h>
#include <roster.h>
#include <string>

int main()
{   //The output below is step F.1
    cout << "Name: John Mihaley\n";
    cout << "Student ID: 001677757\n";
    cout << "Class: Scripting and Programming - Applications\n";
    cout << "Programming Language: C++\n";

        const string studentData[] =
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,John,Mihaley,jmihale@student.wgu.edu,27,20,30,40,SOFTWARE"


};
}


2.  Create an instance of the Roster class called classRoster.

3.  Add each student to classRoster.

4.  Convert the following pseudo code to complete the rest of the  main() function :

    classRoster.printAll();

classRoster.printInvalidEmails();



//loop through classRosterArray and for each element:

classRoster.printAverageDaysInCourse(/*current_object's student id*/);


Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.


classRoster.printByDegreeProgram(SOFTWARE);

classRoster.remove("A3");

classRoster.printAll();

classRoster.remove("A3");

//expected: the above line should print a message saying such a student with this ID was not found.