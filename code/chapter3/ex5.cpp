#include<iostream>
int main()
{
	using namespace std;
	long long pp_us, pp_world;
	cout << "Enter the worlds's population: ";
	cin >> pp_world;
	cout << "Enter the population of US: ";
	cin >> pp_us;
	double percentage = double(pp_us) / double(pp_world) * 100;
	cout.precision(6);
	cout << "The population of US is " << percentage;
	cout << "% of the world population." <<endl;
	cin.get();
	cin.get();
	return 0;
}