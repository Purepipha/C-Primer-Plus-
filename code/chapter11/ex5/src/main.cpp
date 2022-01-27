// ex5_main.cpp -- test the Stonewt class
// compile with stonewt.cpp
#include "stonewt.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	double pounds;
	int number;			// the number of egg
	Stonewt egg;
	Stonewt weight;
	egg = Stonewt(15.0);
	cout << "Enter your weight in pounds: ";
	cin >> pounds;
	weight = Stonewt(pounds);
	cout << "Before ate eggs, your weight:\n";
	cout << weight << endl;
	cout << "Enter the number of egg you eat: ";
	cin >> number;
	cout << "After ate " << number << " eggs, your weight:\n";
	weight = weight + number * egg;
	cout << weight << endl;
	weight.stone_mode();
	cout << weight << endl;
	weight.int_pounds_mode();
	cout << weight << endl;
	return 0;
}