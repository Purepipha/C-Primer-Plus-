//ex6.cpp - - mpg convert to l/100km
#include<iostream>
int main()
{
	using namespace std;
	double m,g; // mlie ,garlon
	cout << "Enter the mile: ";
	cin >> m;
	cout << "Enter the garlon: ";
	cin >> g;
	cout << "The mile per garlon is " << m / g << " mpg." << endl;
	double l = g * 3.875 / (m / 62.14);
	cout << "The fuel consumption is " << l << "L/100Km.";
	cin.get();
	cin.get();
	return 0;
}