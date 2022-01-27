// ex9_new_arr_str.cpp -- use new to construct dynamic array of struct;
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

    CandyBar * pt = new CandyBar[3];

    // invalid -- can read,can't write
    // (*pt).brand = "dabaitu";
    // pt->brand = "dabaitu";
    // pt[0].brand = "dabaitu";

    // invalid -- should the type of struct
    // pt[0] = {"daibaitu", 0.8, 300 };
    // pt[1] = pt[0];
    // pt[2] = {"simth", 0.3, 300 };
    pt[0] = CandyBar{"fruit candy", 0.8, 300 };
    pt[1] = pt[0];
    *(pt+2) = CandyBar{"milk candy", 0.3, 300 };

    cout << "Brand: " << pt[0].brand << endl;
    cout << "Weight: " << pt[0].weight << endl;
    cout << "Calori: " << pt[0].calori << endl;
    cout << "Brand: " << (pt+1)->brand << endl;
    cout << "Weight: " << (pt+1)->weight << endl;
    cout << "Calori: " << (pt+1)->calori << endl;
    // cout << "Brand: " << *(pt+2).brand << endl;
    // cout << "Weight: " << *(pt+2).weight << endl;
    // cout << "Calori: " << *(pt+2).calori << endl;
    cout << "Brand: " << pt[2].brand << endl;
    cout << "Weight: " << pt[2].weight << endl;
    cout << "Calori: " << pt[2].calori << endl;
    delete [] pt;
    return 0;
}