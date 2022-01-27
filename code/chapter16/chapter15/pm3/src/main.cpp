// pe3.cpp -- inheritance logic_error
#include "exc_mean.h"
#include <cmath>
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	double x, y, z;
	cout <<	"Enter two numbers: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " 
				 << y << " is " << z << endl;
			z = gmean(x, y);
			cout << "Geimetric mean of " << x << " and "
				 << y << " is " << z << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch(const bad_meanABC & bm)
		{
			bm.mesg();
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a,b);
	else
		return 2 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a,b);
	else
		return sqrt(a * b);
}