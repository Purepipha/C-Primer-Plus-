// arith.cpp - - some C++ arithmetic 
#include<iostream>
int main()
{
	using namespace std;
	float hats, heads;
	cout << "Enter a number: ";
	cin >> hats;
	cout << "Enter another number: ";
	cin >> heads;
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout << "hats = " << hats << "; heads = " << heads << endl;
	cout << "hats + head =" << hats + heads << endl;
	cout << "hats - head =" << hats - heads << endl;
	cout << "hats * head =" << hats * heads << endl;
	cout << "hats / head =" << hats / heads << endl;
	cin.get();
	cin.get();
	return 0;
}