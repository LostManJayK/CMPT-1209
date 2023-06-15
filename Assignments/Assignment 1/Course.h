#ifndef COURSE_H
#define COURSE_H

#include <iostream>

#include "Student.h"

using std::cout;
using std::cin;
using std::getline;
using std::string;

class Course
{

    private:
        string code;
        int section;
        int capacity;
        int numStudents;
        Student **list;
        static void printHeader();
    public:
        //Accessors
        string getCode() const;
        int getSection() const;
        int getCapacity() const;
        int getNumStudents() const;

        //Mutators
        void setCode(string);
        void setSection(int);

        Course();
        Course(string, int=1, int=35);

        ~Course();

        //Utility functions
        void add();
        void remove(string&);
        void sortByFirstAsc();
        void sortByFirstDes();
        void sortByLastAsc();
        void sortByLastDes();
        void sortByIDAsc();
        void sortByIDDes();
        void sortByPhoneAsc();
        void sortByPhoneDes();
        void sortByGPAAsc();
        void sortByGPADes();

        void display() const;
        void displayByFirst(string&) const;
        void displayByLast(string&) const;
        void displayByID(string&) const;
        void displayByPhone(string&) const;
        




};

#endif