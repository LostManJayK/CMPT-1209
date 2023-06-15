#include <iostream>
#include <algorithm>
#include <iomanip>

#include "Student.h"
#include "Course.h"

using namespace std;

Course::Course()
{
    this->code = "CMPT";
    this->section = 1;
    this->capacity=35;
    this->numStudents = 0;
    this->list = new Student*[this->capacity];
}

Course::Course(string code, int section, int capacity)
{
    this->code = code;
    this->section = section;
    this->capacity = capacity;
    this->numStudents = 0;
    this->list = new Student*[this->capacity];
}

Course::~Course()
{
    cout << "Course with code: " << this->code << " and section: " << this->section << " removed." << endl;
}

void Course::add()
{
    try
    {
        if(this->numStudents == capacity)
        {
            throw std::out_of_range("Capacity!");
        }
        this->list[this->numStudents] = new Student();
        (*this->list[this->numStudents]).input();
        this->numStudents++;
    }
    catch(const std::out_of_range e)
    {
        std::cerr << e.what() << ": Course has reached capacity!";
    }
}
void Course::remove(string &phone)
{
    for(int i=0; i<this->numStudents; i++)
    {
        if((*this->list[i]).getPhoneNumber() == phone)
        {
            for(int j=i; j<this->numStudents-1; j++)
            {
                *(this->list+j) = *(this->list+j+1);
            }

            break;
            
        }
    }

    delete this->list[--this->numStudents]; //Decrement numStudents then delete object
    this->list[this->numStudents] = nullptr;
}

void Course::sortByFirstAsc()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getFirstName() < temp.getFirstName())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByFirstDes()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getFirstName() > temp.getFirstName())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByLastAsc()
{
        Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getLastName() < temp.getLastName())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByLastDes()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getLastName() > temp.getLastName())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByIDAsc()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getStudentID() < temp.getStudentID())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByIDDes()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getStudentID() > temp.getStudentID())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByPhoneAsc()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getPhoneNumber() < temp.getPhoneNumber())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByPhoneDes()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getPhoneNumber() > temp.getPhoneNumber())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByGPAAsc()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getGPA() < temp.getGPA())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}
void Course::sortByGPADes()
{
    Student temp;
    int index=0;

    //Selection sort
    for(int i=0; i<this->numStudents; i++)
    {
        index = i;
        temp = *(this->list[i]);
        for(int j=i+1; j<numStudents; j++)
        {
            if((*this->list[j]).getGPA() > temp.getGPA())
            {
                index = j;
            } 
        }

        temp = *this->list[index];
        *this->list[index] = *this->list[i];
        *this->list[i] = temp;

    }
}


void Course::printHeader()
{
    cout << left << setw(15) << "First Name";
    cout << left << setw(15) << "Last Name";
    cout << left << setw(20) << "Student ID";
    cout << left << setw(15) << "Phone Number";
    cout << left << setw(5) << "GPA" << endl;
}

void Course::display() const
{

    Course::printHeader();

    for(int i=0; i<this->numStudents; i++)
    {
        (*this->list[i]).output();
    }
}
void Course::displayByFirst(string& first) const
{
    Course::printHeader();

    for(int i=0; i<this->numStudents; i++)
    {
        if((*this->list[i]).getFirstName() == first)
        {
            (*this->list[i]).output();
        }
    }
}
void Course::displayByLast(string &last) const
{
        Course::printHeader();

    for(int i=0; i<this->numStudents; i++)
    {
        if((*this->list[i]).getFirstName() == last)
        {
            (*this->list[i]).output();
        }
    }
}
void Course::displayByID(string &id) const
{
    Course::printHeader();

    for(int i=0; i<this->numStudents; i++)
    {
        if((*this->list[i]).getFirstName() == id)
        {
            (*this->list[i]).output();
        }
    }
}
void Course::displayByPhone(string &phone) const
{
    Course::printHeader();

    for(int i=0; i<this->numStudents; i++)
    {
        if((*this->list[i]).getFirstName() == phone)
        {
            (*this->list[i]).output();
        }
    }
}