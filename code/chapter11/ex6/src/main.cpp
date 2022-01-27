#include "stonewt.h"

int main()
{
	const int Arsize = 6;
	using std::cin;
	using std::cout;
	using std::endl;
	double lbs;
	Stonewt max;
	Stonewt min;
	int count = 0;
	Stonewt starr[Arsize] = {
		100,200,300
	};
	for(int i = 3; i < Arsize; i++)
	{
		cout << "Enter the weight in pounds: ";
		cin >> lbs;
		starr[i] = Stonewt(lbs);
	}
	cout << "Stonewt array list:\n";
	for(int i = 0; i < Arsize; i++)
		cout << starr[i] << endl;
	cout << endl;
	max = starr[0];
	for(int i = 0; i < Arsize; i++)
	{
		max = max > starr[i] ? max : starr[i];
	}
	cout << "The maximum Stonewt object:\n" << max << endl;
	
	min = starr[0];
	for(int i = 0; i < Arsize; i++)
	{
		min = min < starr[i] ? min : starr[i];
	}
	cout << "The minimum Stonewt object:\n" << min << endl;

	Stonewt st11 = Stonewt(11,0.0);
	for(int i = 0; i < Arsize; i++)
	{
		if(starr[i] >= st11)
			count++;
	}

	cout << "The Stonewt array >= 11 stone number: " << count << endl;
	return 0;
}