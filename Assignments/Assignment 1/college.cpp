#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

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

int main() {
    Course course("CMPT", 1, 35);

    int option;
    string input;

    do {
        cout << "0. Exit" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Sort by First(Ascending)" << endl;
        cout << "4. Sort by Last(Descending)" << endl;
        cout << "5. Sort by Student(Ascending)" << endl;
        cout << "6. Sort by Phone(Descending)" << endl;
        cout << "7. Sort by GPA (Ascending)" << endl;
        cout << "8. Display by First" << endl;
        cout << "9. Display by Last" << endl;
        cout << "10. Display by ID" << endl;
        cout << "11. Display by Phone" << endl;
        cout << "12. Remove" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: 
            {
                cout << "Adding a student:" << endl;
                course.add();
                break;
            }
            case 2: 
            {
                cout << "Displaying all students:" << endl;
                course.display();
                break;
            }
            case 3: 
            {
                cout << "Displaying by first name in ascending order:" << endl;
                course.sortByFirstAsc();
                course.display();
                break;
            }
            case 4: 
            {
                cout << "Displaying by last name in descending order:" << endl;
                course.sortByLastDes();
                course.display();
                break;
            }
            case 5: 
            {
                cout << "Displaying by student ID in ascending order:" << endl;
                course.sortByIDAsc();
                course.display();
                break;
            }
            case 6: 
            {
                cout << "Displaying by phone number in descending order:" << endl;
                course.sortByPhoneDes();
                course.display();
                break;
            }
            case 7: 
            {
                cout << "Displaying students sorted by GPA in ascending order:" << endl;
                course.sortByGPAAsc();
                course.display();
                break;
            }
            case 8: 
            {
                cout << "Enter the first name to display students: ";
                getline(cin, input);
                cout << "Displaying students with first name \"" << input << "\":" << endl;
                course.displayByFirst(input);
                break;
            }
            case 9: 
            {
                cout << "Enter the last name to display students: ";
                getline(cin, input);
                cout << "Displaying students with last name \"" << input << "\":" << endl;
                course.displayByLast(input);
                break;
            }
            case 10: 
            {
                cout << "Enter the student ID to display students: ";
                getline(cin, input);
                cout << "Displaying students with student ID \"" << input << "\":" << endl;
                course.displayByID(input);
                break;
            }
            case 11: 
            {
                cout << "Enter the phone number to display students: ";
                getline(cin, input);
                cout << "Displaying students with phone number \"" << input << "\":" << endl;
                course.displayByPhone(input);
            }
            case 12: 
            {
                cout << "Enter the phone number of the student to remove: ";
                getline(cin, input);
                course.remove(input);
                cout << "Student with phone number \"" << input << "\" removed successfully." << endl;
                break;
            }
            case 0: 
            {
                cout << "Exiting the program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

        cout << endl;

    } while (option != 0);

    return 0;
}