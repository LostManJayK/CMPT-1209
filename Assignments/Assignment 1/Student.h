#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
    private:
        string firstName;
        string lastName;
        string studentID;
        string phoneNumber;
        float gpa;
        static int firstWidth, lastWidth, idWidth, phoneWidth, gpaWidth;

    public:

        // Constructors
        Student();
        Student(string, string=" ", string=" ", string=" ", float=0.0);

        // Destructor
        ~Student();

        // Mutators
        void setFirstName(string);
        void setLastName(string);
        void setStudentID(string);
        void setPhoneNumber(string);
        void setGPA(float);

        // Accessors
        string getFirstName() const;
        string getLastName() const;
        string getStudentID() const;
        string getPhoneNumber() const;
        float getGPA() const;

        // I-O
        void input();
        void output() const;

};

#endif