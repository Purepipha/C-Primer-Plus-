// ex1.cpp -- test Cow class
// compile with cow.cpp
#include <iostream>
#include <cstring>
#include "cow.h"


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int num;
	char tname[20];
	double wt;
	char tho[20];
	cout << "Enter the number of student: ";
	cin >> num;
	cin.get();
	Cow cows[num];
	int i;
	for(i = 0; i < num; i++)
	{
		cout << "Student #" << i + 1 << ":\n";
		cout << "Enter student's name<empty line to quit>: ";
		cin.getline(tname, 20);
		if(strcmp(tname, "") == 0)
			break;
		cout << "Enter the hobby of this student: ";
		cin.getline(tho,20);
		cout << "Enter this student's weight: ";
		cin >> wt;
		cin.get();
		cows[i] = Cow(tname,tho,wt);
	}
	int total = i;
	cout << "Student list:\n";
	for (i = 0; i < total; i++)
		cows[i].ShowCow();
	Cow last;
	last = cows[total - 1];
	cout << "Last student is \n"; 
	last. ShowCow();
	return 0;
}