#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"

// default constructor values
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysToComplete; i++) this->days[i] = 0;
	this->degree = DegreeType::UNDECIDED;
}
// constructor with input parameters
Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType degree)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysToComplete; i++) this->days[i] = days[i];
	this->degree = degree;
}
// create getters methods for each instance variable
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeType Student::getDegree() { return this->degree; }
// create setter methods for each instance variable
void Student::setStudentID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email; }
void Student::setAge(int age) { this->age; }
void Student::setDays(int days[])
{
	for (int i = 0; i < daysToComplete; i++) this->days[i] = days[i];
}
void Student::setDegreeType(DegreeType degreeType) { this->degree = degreeType; }
// print header format
void Student::printHeader()
{
	cout << "Output format: ID | firstName | lastName | email | age | daysToComplete | degreeType\n";
}
// print student data
void Student::print()
{
	string degreeTypeString = "";
	switch (degree)
	{
	case SECURITY:
		degreeTypeString = "SECURITY";
		break;
	case NETWORK:
		degreeTypeString = "NETWORK";
		break;
	case SOFTWARE:
		degreeTypeString = "SOFTWARE";
		break;
	default:
		degreeTypeString = "UNDECIDED";
		break;
	}

	// output
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << degreeTypeString[this->getDegree()] << '\n';
}
// destructor
Student::~Student() {};