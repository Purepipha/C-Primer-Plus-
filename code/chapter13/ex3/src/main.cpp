#include "dma.h"
const int MAX = 3;
const int CMAX = 40;

int main()
{
	using std::cin;
    using std::cout;
    using std::endl;
	char temp1[CMAX];
	int tempr;
	char kind;

	DMAABC * p_dma[MAX];

	for(int i = 0; i < MAX; i++)
	{
		cout << "Enter the label: ";
		cin.getline(temp1,CMAX);
		cout << "Enter the rating: ";
		(cin >> tempr).get();
		cout << "Enter 1 for baseDMA or "
			 << "2 for lacksDMA or "
			 << "3 for hasDMA: ";
		while (cin >> kind &&(kind != '1' && kind != '2' && kind != '3'))
        {
            cout << "Enter either 1 or 2 or 3: ";
        }
		while(cin.get() != '\n')
			continue;
		if(kind == '1')
			p_dma[i] = new baseDMA(temp1, tempr);
		else if (kind == '2')
		{
			char temp2[CMAX];
			cout << "Enter the color: ";
			cin.getline(temp2,CMAX);
			p_dma[i] = new lacksDMA(temp2, temp1, tempr);
		}
		else
		{
			char temp2[CMAX];
			cout << "Enter the style: ";
			cin.getline(temp2,CMAX);
			p_dma[i] = new hasDMA(temp2, temp1, tempr);
		}
	}
	cout << endl;
	for(int i = 0; i < MAX; i++)
	{
		p_dma[i]->View();
		cout << endl;
	}

	for(int i = 0; i < MAX; i++)
		delete p_dma[i];
	
	cout << "Done\n";
	return 0;
}