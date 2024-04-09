#pragma once
#include "student.h"
#include "degree.h"

class Roster
{
public:
	int endIndex = -1;
	const static int numStudents = 5;
	// create array of pointers for roster
	Student* rosterArray[numStudents];
	// parse studentData
	void parse(string studentData);
	// create add method for studentData
	void add(string id, string firstName, string lastName, string email, int age,
		int courseDays1, int courseDays2, int courseDays3, DegreeType degreeType);
	// printall method
	void printAll();
	// print by degree method
	void printByDegreeType(DegreeType degreeType);
	// print invalid emails method
	void printInvalidEmails();
	// print by average days in course method
	void printAverageDays(string id);
	// revmove student from roster by student ID
	void removeStudentByID(string sID);
	// destructor
	Roster();
	~Roster();
};