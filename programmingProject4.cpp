#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Student
{
public:
	Student() :numClasses(0), classList(0) { name = ""; } //default constructor
	~Student(); //destructor
	void input(); //input member variables function
	void output(); //output member variables function
	void reset(); //reset member variables like default constructor
	Student& operator= (const Student& right); //overloading assign to
private:
	string name;
	int numClasses;
	string* classList;
};
int main() 
{
	Student A, B;
	cout << "Input student A's datalists\n";
	A.input();
	cout << "\nStudent A's datalists :\n";
	A.output();
	cout << '\n';
	cout << "Student B that copies student A's datalists :\n";
	B = A;
	B.output();
	cout << "\nStudent B resets datalists\n";
	B.reset();
	B.output();

	cout << "\nInput student B's datalists\n";
	B.input();
	cout << "\nStudent B's datalists :\n";
	B.output();

	return 0;
}
void Student::reset()
{
	if (classList != 0)
	{
		delete[] classList;
	}
	classList = 0;
	numClasses = 0;
	name = "";
}
void Student::input()
{
	reset();
	cout << "Enter student name :";
	getline(cin, name);
	cout << "Enter number of classes :";
	cin >> numClasses;
	cin.ignore();
	if (numClasses >= 1)
	{
		classList = new string[numClasses];
		for (int i = 0; i < numClasses; i++)
		{
			cout << "Enter your Class name of No." << i + 1 << '\n';
			getline(cin, classList[i]);
		}
	}
}
void Student::output()
{
	cout << "Student name : " << name << '\n';
	cout << "Number of classes : " << numClasses << '\n';
	for (int i = 0; i < numClasses; i++) {
		cout << "Class No." << i + 1 << " : " << classList[i] << '\n';
	}
}
Student& Student::operator= (const Student& right)
{
	reset();
	name = right.name;
	numClasses = right.numClasses;
	if (numClasses != 0)
	{
		classList = new string[numClasses];
		for (int i = 0; i < numClasses; i++)
		{
			classList[i] = right.classList[i];
		}
	}
	return *this;
}
Student::~Student()
{
	if (classList != 0)
	{
		delete[] classList;
	}
}