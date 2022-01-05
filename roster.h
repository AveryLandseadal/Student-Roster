#pragma once
#include "student.h"
class Roster 
{
private:
	int currentStudentsRoster = -1;
	const static int numStudents = 5;
	
public:
	Student* classRosterArray[numStudents];
	void parse(string studentdata);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeTypeEnum degreeProgram);
	void remove(string studentID); //removes a student by their ID
	void printAll(); //prints list of student data
	void printAverageDaysInCourse(string studentID); //print the students average number of days in the courses
	void printInvalidEmails(); //displays invalid email addresses
	void printByDegreeProgram(DegreeTypeEnum degreeProgram); // prints student information for a degree program
	~Roster();
};
