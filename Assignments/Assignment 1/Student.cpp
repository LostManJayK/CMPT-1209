#include <iostream>
#include <string>
#include <iomanip>

#include "Student.h"

using namespace std;

Student::Student()
{
    this->firstName=" ";
    this->lastName=" ";
    this->studentID=" ";
    this->phoneNumber=" ";
    this->gpa = 0.0;
}

Student::Student(string firstName, string lastName, string studentID, string phoneNumber, float gpa)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->studentID = studentID;
    this->setPhoneNumber(phoneNumber); //Use setter for validation
    this->gpa = gpa;
}

Student::~Student()
{
    ;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}

void Student::setPhoneNumber(string phoneNumber)
{
    bool valid=true;
    
    for(int i=0; i<phoneNumber.size(); i++)
    {
        if(!(phoneNumber[i]-'0' <= 0 || phoneNumber[i] == ' '))
        {
            valid = false;
            break;
        }
    }

    if(phoneNumber[3] != ' ' || phoneNumber[7] != ' ')
    {
        valid = false;
    }
    else if(phoneNumber.size() != 12)
    {
        valid = false;
    }

    if(!valid)
    {
        cout << "Phone number invalid. Please enter in format (XXX-XXX-XXXX)" << endl;
        this->phoneNumber = " ";
    }
    else
    {
        this->phoneNumber = phoneNumber;
    }
}

void Student::setGPA(float gpa)
{
    this->gpa = gpa;
}

string Student::getFirstName() const
{
    return this->firstName;
}

string Student::getLastName() const
{
    return this->lastName;
}

string Student::getStudentID() const
{
    return this->studentID;
}

string Student::getPhoneNumber() const
{
    return this->phoneNumber;
}

float Student::getGPA() const
{
    return this->gpa;
}

void Student::input()
{
    cout << "Please enter the following details for the student:" << endl;

    cout << "First Name: ";
    getline(cin, this->firstName);

    cout << "Last Name: ";
    getline(cin, this->lastName);

    cout << "Student ID: ";
    cin >> this->studentID;

    cout << "Phone Number: ";
    cin >> this->phoneNumber;

    cout << "GPA: ";
    cin >> this->gpa;

    cin.ignore();
}

int Student::firstWidth = 15;
int Student::lastWidth = 15;
int Student::idWidth = 20;
int Student::phoneWidth = 15;
int Student::gpaWidth = 5;


void Student::output() const
{
    cout << left << setw(Student::firstWidth) << this->firstName;
    cout << left << setw(Student::lastWidth) << this->lastName;
    cout << left << setw(Student::idWidth) << this->studentID;
    cout << left << setw(Student::phoneWidth) << this->phoneNumber;
    cout << left << setw(Student::gpaWidth) << this->gpa << endl;
}

