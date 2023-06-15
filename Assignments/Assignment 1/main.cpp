#include <iostream>
#include "Course.h"

using namespace std;

int main() {
    Course course("CMPT", 1, 35);

    int choice;
    string input;

    do {
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
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
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

    } while (choice != 0);

    return 0;
}