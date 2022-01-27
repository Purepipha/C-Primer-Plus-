// ex1.cpp -- walk random problem
// compile with vector.cpp
#include <fstream>
#include <cstdlib>  // rand(), srand() protypes
#include <ctime> 	// time() protype
#include "vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
//	write in file
	ofstream fout;
	fout.open("walk_random.txt");

	srand(time(0));			//generate a seed of random
	double target;
	double dstep;
	unsigned long steps = 0;
	Vector step;
	Vector result(0.0,0.0);
	cout << "Enter the Target Distance(enter q to quit): ";
	while(cin >> target)
	{
		cout << "Enter the distance of every step: ";
		while(!(cin >> dstep))
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Bad input, please enter a double value: ";
		}

		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while(result.mag_val() < target)
		{
			step.reset(dstep, rand() % 360, Vector::POL);
			step.rect_mode();
			fout << steps << ": " << step << endl;
			result = result + step;
			steps++;
		}
		fout << "After " << steps << " steps, the subject has the following location:\n";
		fout << result << endl;
		fout << "or\n";
		result.polar_mode();
		fout << result << endl;
		fout << "Average outward distance per step = " << result.mag_val() / steps << endl;
		cout << "Enter next Target Distance(enter q to quit): ";
	}
	fout.close();
	cout << "Bye\n";
	return 0;
}