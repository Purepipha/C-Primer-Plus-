// ex5.cpp -- structure
#include<iostream>

struct CandyBar
{
    char brand[20];
    float weight;
    int calori;
};

int main()
{
    using namespace std;
    CandyBar snack {"Mocha Munch", 2.3, 350};
    cout << "Brand: " << snack.brand << endl;
    cout << "Weight: " << snack.weight << endl;
    cout << "Calori: " << snack.calori << endl;
    return 0;
}