#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "roster.h"
#include "student.h"
#include "degree.h"

int main()
{
	const int numStudents = 5;
	// include own student data in the provided data set
	const string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ric,Dub,student@wgu.edu,95,10,11,12,SOFTWARE"
	};

	// print course info
	cout << "--(C867) Scripting and Programming Applications--" << endl;
	cout << "Microsoft Visual Studio C++ 2022" << endl;
	cout << "WGU Student ID: ---------" << endl;
	cout << "WGU Student Name: ----------" << endl;

	// create Roster class
	Roster classRoster;

	// add students to Roster
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.parse(studentData[i]);
	}

	// print entire roster
	cout << "Class Roster" << endl;
	cout << "------------" << endl;
	classRoster.printAll();

	// print invalid emails
	cout << "Invalid Emails" << endl;
	cout << "------------" << endl;
	classRoster.printInvalidEmails();

	// print days in course
	cout << "Average Days in Course" << endl;
	cout << "------------" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDays(classRoster.rosterArray[i]->getStudentID());
	}

	// print by degree type
	cout << "Software Students" << endl;
	cout << "------------" << endl;
	classRoster.printByDegreeType(SOFTWARE);

	// remove student by ID
	cout << "Remove student by ID" << endl;
	cout << "------------" << endl;
	classRoster.removeStudentByID("A3");

	// print entire roster again
	cout << "Class Roster" << endl;
	cout << "------------" << endl;
	classRoster.printAll();

	// remove same student that was previously removed
	cout << "Remove student by same ID" << endl;
	cout << "------------" << endl;
	classRoster.removeStudentByID("A3");

	return 0;
}
