//ex6.cpp - - l/100km convert to mpg
#include<iostream>
int main()
{
	using namespace std;
	const double m_per_100km = 62.14;
	const double l_per_g = 3.875;
	double l; // mlie ,garlon
	cout << "Enter the fuel comsuption per 100 km: ";
	cin >> l;
	double m = m_per_100km / (l / l_per_g);
	cout << l <<" L/100km = " << m << " mpg" <<endl;
	cin.get();
	cin.get();
	return 0;
}