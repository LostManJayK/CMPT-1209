#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
	string first; // instance member variable
	string last; // instance
	static int numStudents; // static member 
public:
	Student(string = " ", string = " ");
	~Student();
	string getFirst() const;
	string getLast() const;
	static int getNumStudents();
	void setFirst(string);
	void setLast(string);
	void output() const;
};
int Student::numStudents = 0;
Student::Student(string x1, string x2)
{
	first = x1;
	last = x2;
	numStudents++;
}
Student::~Student()
{
	numStudents--;
}
string Student::getFirst() const
{
	return first;
}
string Student::getLast() const
{
	return last;
}
int Student::getNumStudents()
{
	return numStudents;
}
void Student::setFirst(string x)
{
	first = x;
}
void Student::setLast(string x)
{
	last = x;
}
void Student::output() const
{
	cout << first << " " << last << " " << endl;
}
int main()
{
	Student x("Daniel", "Robinson");
	Student y("Mike", "Richardson");
	Student m("Jeff", "Jackson");
	//{
	//	Student z;
	//	cout << m.getNumStudents() << endl;
	//}
	x.output();
	y.output();
	m.output();



	cout << Student::getNumStudents() << endl;

	return 0;
}