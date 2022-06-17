#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	char* str = new char[101]; //until 100 letters okay
	
	cout << "Enter string less than or equal to 100 letters :";
	cin.getline(str, 101);
	char* head = str;
	int i = 0;
	while (str[i++] != '\0'); //i == stringLength+2
	i-=2; //i == stringLength
	char* tail = &(str[i]); //pointer that is pointing last word 
	while (head < tail) //change head pointer with tail pointer while tail is larger
	{
		if (*head!=*tail) 
		{
			cout << "The word is not palindrome\n";
			delete[] str;
			exit(1);
		}
		head++; tail--;
	}
	cout << "The word is palindrome\n";
	delete[] str;
	return 0;
}