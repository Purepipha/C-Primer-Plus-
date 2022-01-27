#include<iostream>
int main()
{
	using namespace std;
	long long seconds;
	cout << "Enter the number of seconds: ";
	cin >> seconds;

	int second, minute, hour, days;
	second = seconds % 60;
	long minutes = seconds / 60;
	minute = minutes % 60;
	long hours = minutes / 60;
	hour = hours % 24;
	days = hours / 24;
	
	cout << seconds <<" seconds = " << days <<" days, " << hour;
	cout << " hours, " << minute <<" minutes, " << second << "seconds" <<endl;
	cin.get();
	cin.get();
	return 0;
}
