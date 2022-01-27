#include<iostream>
int main()
{
	using namespace std;
	const int inch_per_foot =12;
	int height;
	cout << "Enter your height in inch:___\b\b\b";
	cin >> height;
	int foot = height / inch_per_foot;
	int inch = height % inch_per_foot;
	cout << "Your height is " << foot <<" feet, " <<inch <<" inches."<<endl;
	cin.get();
	cin.get();
	return 0;
}
