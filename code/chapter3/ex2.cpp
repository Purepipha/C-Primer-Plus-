#include<iostream>
int main()
{
	using namespace std;
	const int inch_per_foot = 12;
	const double meters_per_inch = 0.0254;
	const double pounds_per_kg = 2.2;
	int feet,inches;
	cout << "Enter your height in feet and inches: "<< endl;
	cout << "First, enter feet: __\b\b";
	cin >> feet;
	cout << "Second, enter inches: __\b\b";
	cin >> inches;
	cout << "Enter you weight in pound:___\b\b\b";
	double pounds;
	cin >> pounds;
	int height_inch = feet * inch_per_foot + inches;
	double height_m = height_inch * meters_per_inch;
	double weight = pounds / pounds_per_kg;
	double BMI = weight / (height_m * height_m);

	cout << "Your BMI is " << BMI <<endl;
	cin.get();
	cin.get();
	return 0;
}
