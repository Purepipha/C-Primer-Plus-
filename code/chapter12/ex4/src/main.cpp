// stacker10_12.cpp -- testing the Stack class
#include <iostream>
#include <cctype>
#include "stack.h"

Item findmax(Stack st);	// using Stack(const Stack & st) to get copy od st
int main()
{
    using namespace std;
	Item num;
    Stack st1(6);
	Stack st2;
	int count = 0;
	cout << "Enter a seires of number, I'll show them and find the maximum.\n";
	cout << "Enter q to quit\n";
	while(!st1.isfull())
	{
		cout << "Value #" << count + 1 << ": ";
		cin >> num;
		if(!cin)
			break;
		st1.push(num);
		count++;
	}
    cout << "The list of you input number:\n";
	st2 = st1;		// using Stack & operator=(const Stack & st)
	while (!st2.isempty())
	{
		st2.pop(num);
		cout << num << '\t';
	}
	cout << endl;
	Item max = findmax(st1);
	cout << "The maximun of these numbers is " << max << endl;
	cout << "Pop st1:\n";
	while (!st1.isempty())
	{
		st1.pop(num);
		cout << num << '\t';
	}
	cout << endl;
	cout << "Done\n";
    return 0;
}

Item findmax(Stack st)
{
	Item max,temp;
	st.pop(max);
	while(!st.isempty())
	{
		st.pop(temp);
		max = max > temp ? max : temp;
	}
	return max;
}