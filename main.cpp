#include "roster.h"
#include <iostream>
using std::cout;

int main() 
{
    cout << "Class roster\t",
    cout << "C++\t",
    cout << "Avery Landseadal\n";
    
    //strings to parse
    const string studentData[]
    {
     "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Avery,Landseadal,alands@fakeemail.com,25,30,25,40,SOFTWARE"
    };

    const int numStudents = 5;
    Roster classRoster; //creates instance roster using default parameterless constructor

    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying student information: " << std::endl;
    classRoster.printAll();
    cout << std::endl;

    cout << "The following students have invalid emails :" << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
   
    cout << "Displaying average course length: " << std::endl;
    for (int i = 0; i < 5; i++) classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());

    for (int i = 0; i < 5; i++)
    {
        cout << "Displaying degree: " << degreeProgramStrings[i] << std::endl;
        classRoster.printByDegreeProgram((DegreeTypeEnum)i);
     }

    cout << "Removing student by ID: " << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    cout << "Displaying all students: " << std::endl;
    classRoster.printAll();
    cout << std::endl;

    // should display a message stating the student with this id was not found
    cout << "Removing student by ID: " << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    system("pause");
    return 0;
}

   
