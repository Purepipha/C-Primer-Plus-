// test Person class and using MI
// compile with personmi.cpp
#include <iostream>
#include <cstring>
#include "personmi.h"

const int SIZE = 5;
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Person *p[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the person category:\n";
		cout << "g: gunslinger	p: pokerplayer\n";
		cout << "b: baddude     q: quit\n";
		while (cin >> choice && strchr("gpbq", choice) == NULL)
			cout << "Please enter a g, p, b, q: ";
		if (choice == 'q')
			break;
		switch(choice)
		{
			case 'g' : p[ct] = new Gunslinger;
					   break;
			case 'p' : p[ct] = new PokerPlayer;
					   break;
			case 'b' : p[ct] = new BadDude;
					   break;	
			default :  break;   	   
		}
		p[ct]->Set();
	}

	for (int i = 0; i < ct; i++)
	{
		p[i]->Show();
	}
	for (int i = 0; i < ct; i++)
		delete p[i];
	cout << "Done.\n";
	return 0;
}