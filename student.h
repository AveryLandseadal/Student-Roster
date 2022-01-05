#pragma once
#include <iostream>
#include <iomanip>
#include <degree.h>
using std::string;
using std::cout;

class Student
{
public:
    const static int daysToCompleteCourseArray = 3;
protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[daysToCompleteCourseArray];
    DegreeTypeEnum degreeProgram;
public:
    //Constructor
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeTypeEnum degreeProgram);
    //destructor
    ~Student();

    //getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDays();
    DegreeTypeEnum getDegreeProgram();

    //setters

    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeTypeEnum degreeProgram);

    //displays a header for the data to follow
    static void printHeader();

    //displays students data
    void print();
};