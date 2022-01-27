// ex6_str_arr.cpp -- combine array and struct
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
    // CandyBar ca[3];
    // ca[0] = {"dabaitu", 0.3 , 200};
    // ca[1] = ca[0];
    // ca[2] = {"aiyuan", 0.7, 400};
    CandyBar ca[3] =
    {
        {"fruit candy", 0.3 , 200},
        {"salad", 0.7, 400}
    };
    ca[2] = ca[1];

    cout << "Brand: " << ca[0].brand << endl;
    cout << "Weight: " << ca[0].weight << endl;
    cout << "Calori: " << ca[0].calori << endl;
    cout << "Brand: " << ca[1].brand << endl;
    cout << "Weight: " << ca[1].weight << endl;
    cout << "Calori: " << ca[1].calori << endl;
    cout << "Brand: " << ca[2].brand << endl;
    cout << "Weight: " << ca[2].weight << endl;
    cout << "Calori: " << ca[2].calori << endl;
    return 0;
}