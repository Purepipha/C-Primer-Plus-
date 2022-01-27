// swaps8_4.cpp -- swapping with references and with pointers
#include<iostream>

void swapr(int &x, int &y);
void swapp(int *x, int *y);
void swapv(int x, int y);

int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $" << wallet1;
    cout << ", wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet2,wallet1);
    cout << "wallet1 = $" << wallet1;
    cout << ", wallet2 = $" << wallet2 << endl;

    cout << "Using pointer to swap contents:\n";
    swapp(&wallet2,&wallet1);
    cout << "wallet1 = $" << wallet1;
    cout << ", wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapv(wallet2,wallet1);
    cout << "wallet1 = $" << wallet1;
    cout << ", wallet2 = $" << wallet2 << endl;
    return 0;

}

void swapr(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swapp(int *x, int *y)
{
    int temp;
    temp = * x;
    * x = * y;
    * y = temp;
}

void swapv(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}