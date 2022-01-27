#include <iostream>
#include "emp.h"

int main(int argc, char *argv[])
{
	using namespace std;
	string filename("employee.txt");

	if (argc == 1)
	{
		cout << "Useage(s): " << argv[0] << endl;
		cout << "Deal with " << filename << endl;
		DealWith(filename);// link file with ofstream;
	}
	else
	{
		for (int a = 1; a < argc; a++)
		{
			filename = argv[a];
			DealWith(filename);
		}
	}
	cout << "Done.\n";
	return 0;
}