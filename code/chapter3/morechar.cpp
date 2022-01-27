#include<iostream>
int main()
{
	using namespace std;
	char ch = 'M';
	int i = ch;
	cout << "The ASCII code for " << ch << " is " << i <<endl;
	ch = ch + 1;
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i <<endl;

	cout << "Display ch using cout.put(ch): "<< ch <<" character." <<endl;
	cout.put(ch);
	cout.put('!');
	cout << '$';
	cin.get();
	
	return 0;

}
