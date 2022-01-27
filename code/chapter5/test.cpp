#include<iostream>
int main()
{
    using namespace std;
	int i;
	for (i = 1; i < 64; i *= 2)
		cout << i << "、";
	cout << i << endl;
	return 0;
}