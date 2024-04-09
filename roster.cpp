#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "roster.h"
#include "student.h"


// parse and add each student object to rosterArray
void Roster::parse(string studentData)
{
	// parse student ID
	int lastIndex = studentData.find(",");
	string id = studentData.substr(0, lastIndex);

	// parse first name
	int firstIndex = lastIndex + 1;
	lastIndex = studentData.find(",", firstIndex);
	string firstName = studentData.substr(firstIndex, lastIndex - firstIndex);

	// parse last name
	firstIndex = lastIndex + 1;
	lastIndex = studentData.find(",", firstIndex);
	string lastName = studentData.substr(firstIndex, lastIndex - firstIndex);

	// parse email
	firstIndex = lastIndex + 1;
	lastIndex = studentData.find(",", firstIndex);
	string email = studentData.substr(firstIndex, lastIndex - firstIndex);

	// parse age
	firstIndex = lastIndex + 1;
	lastIndex = studentData.find(",", firstIndex);
	int age = stoi(studentData.substr(firstIndex, lastIndex - firstIndex));

	// parse days1
	firstIndex = lastIndex + 1;
	lastIndex = studentData.find(",", firstIndex);
	int courseDays1 = stoi(studentData.substr(firstIndex, lastIndex - firstIndex));

	// parse days2
	firstIndex = lastIndex + 1;
	lastIndex = studentData.find(",", firstIndex);
	int courseDays2 = stoi(studentData.substr(firstIndex, lastIndex - firstIndex));

	// parse days3
	firstIndex = lastIndex + 1;
	lastIndex = studentData.find(",", firstIndex);
	int courseDays3 = stoi(studentData.substr(firstIndex, lastIndex - firstIndex));

	// parse degree type
	firstIndex = lastIndex + 1;
	lastIndex = studentData.find('/0', firstIndex);
	DegreeType degreeType = UNDECIDED;
	if (studentData.substr(firstIndex, lastIndex - firstIndex) == "SECURITY")
	{
		degreeType = SECURITY;
	}
	else if (studentData.substr(firstIndex, lastIndex - firstIndex) == "NETWORK")
	{
		degreeType = NETWORK;
	}
	else if (studentData.substr(firstIndex, lastIndex - firstIndex) == "SOFTWARE")
	{
		degreeType = SOFTWARE;
	}
	else
	{
		degreeType = UNDECIDED;
	}

	// add data to roster
	add(id, firstName, lastName, email, age, courseDays1, courseDays2, courseDays3, degreeType);
}

void Roster::add(string id, string firstName, string lastName, string email, int age, int courseDays1, int courseDays2, int courseDays3, DegreeType degreeType)
{
	int courseDays[3] = { courseDays1, courseDays2, courseDays3 };
	rosterArray[endIndex] = new Student(id, firstName, lastName, email, age, courseDays, degreeType);
	endIndex++;
}

void Roster::removeStudentByID(string studentID)
{
	// find student ID in rosterArray
	bool studentFound = false;
	for (int i = 0; i < endIndex; i++)
	{
		if (rosterArray[i]->getStudentID() == studentID)
		{
			// remove found student
			studentFound = true;
			for (int j = i; j < endIndex; j++)
			{
				rosterArray[j] = rosterArray[j + i];
			}
			endIndex--;
			cout << "Student " << studentID << " is removed from roster." << endl;
		}
	}
	// print message if student not found
	if (!studentFound)
	{
		cout << "Student ID was not found." << endl;
	}
}

// print complete list of student data
void Roster::printAll()
{
	cout << "ID" << endl;
	cout << "First Name" << endl;
	cout << "Last Name" << endl;
	cout << "Email" << endl;
	cout << "Age" << endl;
	cout << "Days in Course" << endl;
	cout << "Degree Type" << endl;

	for (int i = 0; i < endIndex; i++)
	{
		rosterArray[i]->print();
	}
}

void Roster::printAverageDays(string id)
{
	int days1 = 0;
	int days2 = 0;
	int days3 = 0;
	double averageDays = 0;
	for (int i = 0; i < numStudents; i++)
	{
		if (rosterArray[i]->getStudentID() == id)
		{
			days1 = rosterArray[i]->getDays()[0];
			days2 = rosterArray[i]->getDays()[1];
			days3 = rosterArray[i]->getDays()[2];
			averageDays = (days1 + days2 + days3) / 3;

			// print output
			cout << "Student: " << id << '\t';
			cout << "Average Days: " << averageDays << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	bool invalidEmail = false;
	string checkEmail = "";
	for (int i = 0; i < numStudents; i++)
	{
		checkEmail = rosterArray[i]->getEmail();

		// "@" validation
		if (checkEmail.find("@") == string::npos)
		{
			invalidEmail = true;
			cout << checkEmail << endl;
		}
		// "." validation
		else if (checkEmail.find(".") == string::npos)
		{
			invalidEmail = true;
			cout << checkEmail << endl;
		}
		// null space validation
		else if (checkEmail.find(" ") != string::npos)
		{
			invalidEmail = true;
			cout << checkEmail << endl;
		}

		// print if all email is valid
		if (invalidEmail)
		{
			cout << "All emails are valid." << endl;
		}
	}
}

void Roster::printByDegreeType(DegreeType degreeType)
{
	// convert degree enum to string
	string degreeString = "UNDECIDED";
	if (degreeType == SECURITY)
	{
		degreeString = "SECURITY";
	}
	else if (degreeType == NETWORK)
	{
		degreeString = "NETWORK";
	}
	else if (degreeType == SOFTWARE)
	{
		degreeString = "SOFTWARE";
	}
	else
	{
		degreeString = "UNDECIDED";
	}

	// print output
	cout << "ID: " << '\t';
	cout << "First Name: " << '\t';
	cout << "Last Name: " << '\t';
	cout << "Email: " << '\t';
	cout << "Age: " << '\t';
	cout << "Days in Course: " << '\t';
	cout << "Degree Type: " << endl;

	// print students in requested degree
	bool inDegree = false;
	for (int i = 0; i < numStudents; i++)
	{
		if (rosterArray[i]->getDegree() == degreeType)
		{
			inDegree = true;
			rosterArray[i]->print();
		}

	}
	// print if no students are in the degree
	if (inDegree)
	{
		cout << "NONE FOUND." << endl;
	}
}

Roster::~Roster()
{
	for (int i = 0; endIndex; i++)
	{
		delete rosterArray[i];
	}
	cout << "--Class Roster Cleared--" << endl;
}