#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class DynamicStringArray
{
public:
	DynamicStringArray() :size(0), dynamicArray(0) {}; //default constructor
	int retSize() { return size; }
	DynamicStringArray(const DynamicStringArray& a); //deep copy constructor
	~DynamicStringArray();
	DynamicStringArray& operator=(const DynamicStringArray& right);
	void addEntry(string s);
	bool deleteEntry(string s);
	string getEntry(int idx);
private:
	string* dynamicArray;
	int size;
};
int main() 
{
	DynamicStringArray A;
	A.addEntry("AAAAA");
	A.addEntry("BBBBB");
	A.addEntry("CCCCC");
	A.addEntry("DDDDD");
	A.addEntry("EEEEE");
	cout << "DynamicStringArray A's lists\n\n";
	for (int i = 0; i < A.retSize(); i++)
	{
		cout << A.getEntry(i) << '\n';
	}
	cout << "\n\n";
	A.addEntry("FFFFF");
	cout << "Adding \"FFFFF\" in the dynamicArray\n";
	for (int i = 0; i < A.retSize(); i++)
	{
		cout << A.getEntry(i) << '\n';
	}
	cout << "\n\n";
	A.deleteEntry("CCCCC");
	cout << "Deleting \"CCCCC\" in the dynamicArray\n";
	for (int i = 0; i < A.retSize(); i++)
	{
		cout << A.getEntry(i) << '\n';
	}
	cout << "\n\n";
	A.deleteEntry("ABCDE");
	cout << "Deleting \"ABCDE\" that not in the dynamicArray\n";
	for (int i = 0; i < A.retSize(); i++)
	{
		cout << A.getEntry(i) << '\n';
	}
	cout << "\n\n";
	cout << "Deleting all strings in the dynamicArray\n";
	while (A.retSize() > 0)
	{
		A.deleteEntry(A.getEntry(A.retSize() - 1));
	}
	for (int i = 0; i < A.retSize(); i++)
	{
		cout << A.getEntry(i) << '\n';
	}
	cout << "\n\n";
	A.addEntry("ABCDE");
	A.addEntry("ZYXWV");
	cout << "Adding \"ABCDE\" and \"ZYXWV\" in the dynamicArray\n";
	for (int i = 0; i < A.retSize(); i++)
	{
		cout << A.getEntry(i) << '\n';
	}
	cout << "\n\n";
	cout << "B's dynamicArray that copies A\n";
	DynamicStringArray B(A);
	for (int i = 0; i < B.retSize(); i++)
	{
		cout << B.getEntry(i) << '\n';
	}
	cout << "\n\n";
	cout << "C's dynamicArray. Assign B to C\n";
	DynamicStringArray C=B;
	for (int i = 0; i < C.retSize(); i++)
	{
		cout << C.getEntry(i) << '\n';
	}
	cout << "\n\n";
	return 0;
}
DynamicStringArray::DynamicStringArray(const DynamicStringArray& a)
{
	size = a.size;
	if (size > 0)
	{
		dynamicArray = new string[size];
		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = a.dynamicArray[i];
		}
	}
	else { dynamicArray = 0; }
}
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& right)
{
	size = right.size;
	
	if (size > 0)
	{
		if (dynamicArray != 0) 
		{
			delete[] dynamicArray;
		}
		dynamicArray = new string[size];
		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = right.dynamicArray[i];
		}
	}
	else 
	{
		delete[] dynamicArray;
		dynamicArray = 0;
	}
	return *this;
}
void DynamicStringArray::addEntry(string s) 
{
	string* temp = new string[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = dynamicArray[i];
	}
	temp[size] = s;
	delete[] dynamicArray;
	dynamicArray = new string[size + 1];
	for (int i = 0; i <= size; i++)
	{
		 dynamicArray[i]=temp[i];
	}
	delete[] temp;
	size++;
}
bool DynamicStringArray::deleteEntry(string s)
{
	int location = -77;
	if (size == 0)
	{
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		if (dynamicArray[i] == s)
		{
			location = i;
			break;
		}
	}
	if (location == -77)
	{
		return 0;
	}
	else 
	{
		string* temp = new string[size - 1];
		int k = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != location)
			{
				temp[k++] = dynamicArray[i];
			}
		}
		delete[] dynamicArray;
		dynamicArray = new string[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			dynamicArray[i] = temp[i];
		}
		delete[] temp;
		size--;
		return 1;
	}
}
string DynamicStringArray::getEntry(int idx)
{
	if ((idx < 0) || (idx >= size))
	{
		return NULL;
	}
	else 
	{
		return dynamicArray[idx];
	}
}
DynamicStringArray::~DynamicStringArray()
{
	if (dynamicArray != 0)
	{
		delete[] dynamicArray;
	}
}