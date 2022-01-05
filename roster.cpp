#include "roster.h"
//parse each of the students
void Roster::parse(string studentdata)
{
    DegreeTypeEnum degreeProgram = Undecided;
    if (studentdata.back() == 'Y') degreeProgram = SECURITY;
    else if (studentdata.back() == 'E') degreeProgram = SOFTWARE;
    else if (studentdata.back() == 'K') degreeProgram = NETWORK;
   
    int rhs = studentdata.find(","); //find the comma
    string studentID = studentdata.substr(0, rhs); // extract the substring in front of the comma, found studentID

    int lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string firstName = studentdata.substr(lhs, rhs - lhs); // Found First Name

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string lastName = studentdata.substr(lhs, rhs - lhs); // Found Last Name

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string emailAddress = studentdata.substr(lhs, rhs - lhs); // Found Email

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int age = stod(studentdata.substr(lhs, rhs - lhs)); // Found Age

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse1 = stod(studentdata.substr(lhs, rhs - lhs)); // Found Days1

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse2 = stod(studentdata.substr(lhs, rhs - lhs)); // Found Days2

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse3 = stod(studentdata.substr(lhs, rhs - lhs)); // Found Days3

    //add method
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);//create object
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeTypeEnum degreeProgram)
{
    // puts days into an array for the constructor
    int daysInCourses[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    classRosterArray[++currentStudentsRoster] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourses, degreeProgram);
}

//removes record by student ID
void Roster::remove(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::currentStudentsRoster; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::currentStudentsRoster--;// "removed book", no longer visable
        }
    }
    if (success)
    {
        cout << studentID << " removed from Roster." << std::endl << std::endl;
        this->printAll(); //displays books, removed one shouldnt be there
    }
    //error message if student id isnt found
    else cout << studentID << " could not be found." << std::endl << std::endl;
}

//prints student information
void::Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::currentStudentsRoster; i++)
    {
        classRosterArray[i]->print();
       
     }
}

//prints average days in course
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::currentStudentsRoster; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
        
            cout << classRosterArray[i]->getStudentID() << ":";
            cout << (classRosterArray[i]->getDays()[0]
            + classRosterArray[i]->getDays()[1]
            + classRosterArray[i]->getDays()[2]) / 3.0 << std::endl;
        }
    }
    cout << std::endl;
}

//prints invald emails, each student email must contain a . or @
void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::currentStudentsRoster; i++)
    {
        string emailAddress = (classRosterArray[i]->getEmailAddress());
        if (emailAddress.find(' ') != string::npos || (emailAddress.find('.') == string::npos || (emailAddress.find('@') == string::npos)))
        {
            any = true;
            cout << emailAddress << std::endl;
        }
    }
    if (!any) cout << "ERROR" << std::endl;
}

//prints by degree program
void Roster::printByDegreeProgram(DegreeTypeEnum degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::currentStudentsRoster; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << std::endl;
}

//destructor
Roster::~Roster()
{
    cout << "Destructor in progress!" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying Student" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}