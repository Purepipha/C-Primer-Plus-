// test_cpmv.cpp -- test the class cpmv
#include "cpmv.h"
#include <utility>

int main()
{
	{
	// using Cpmv(std::string q, std::string z)
		Cpmv one("C++", "Fight!");
		Cpmv two(", I love!",", go go go!");
		one.Display();
		two.Display();
	// using Cpmv(Cpmv && mv) and operator+(const Cpmv & obj)
		std::cout << "\nthree(one + two): ";
		Cpmv three(std::move(one + two));
		three.Display();
	// using Cpmv(const Cpmv & cp)
		Cpmv four(one);
		four.Display();
	// operator=(Cpmv && mv) and operator+(const Cpmv & obj)
		std::cout << "\none = four + two: ";
		one = four + two;
		one.Display();
	// operator=(const Cpmv & mv)
		two = three;
		two.Display();
	}
	std::cout << "Done.\n";
	return 0;
}