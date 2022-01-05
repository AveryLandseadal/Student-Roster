#include <student.h>

//constructor that sets default values
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysToCompleteCourseArray; i++) this->days[i] = 0;
    this->degreeProgram = DegreeTypeEnum::Undecided; //default degree program value
}
//constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeTypeEnum degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysToCompleteCourseArray; i++) this->days[i] = days[i];
    this->degreeProgram = degreeProgram;
      
}
//destructor
Student::~Student() {}

//getters
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; } //pointer
DegreeTypeEnum Student::getDegreeProgram() { return this->degreeProgram; }

//setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])
{
    for (int i = 0; i < daysToCompleteCourseArray; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeTypeEnum degreeProgram) { this->degreeProgram = degreeProgram; }

//prints header
void Student::printHeader()
{
    cout << "Student ID|First Name|Last Name|Email| Age |Days in Course| Degree Program\n";
}

//prints out student information
void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getAge() << '\t' << '{';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '}' << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}