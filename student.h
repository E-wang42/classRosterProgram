#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public: const static int daysToComplete = 3;
private:
	// initiate variables
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[daysToComplete];
	DegreeType degree;
public:
	// define constructor
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType degree);
	// define getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeType getDegree();
	// define setters
	void setStudentID(string ID);
	void setFirstName(string first);
	void setLastName(string last);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeType(DegreeType type);
	// print header if necessary 
	static void printHeader();
	// print student info
	void print();
	// define destructor
	~Student();
};