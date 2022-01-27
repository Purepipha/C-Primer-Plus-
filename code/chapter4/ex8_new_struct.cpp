// ex8_new_struct.cpp -- use new to struct
#include<iostream>

struct pissa
{
    char name_company[30];
    float diameter;
    float weight;
};

int main()
{
    using namespace std;
    pissa* p1= new pissa; // problem
    cout << "Enter the diameter of pissa: ";
    (cin >> (p1->diameter)).get();
    cout << "Enter the company of pissa: ";
    cin.getline(p1->name_company,30);
    cout << "Enter the weight of pissa: ";
    cin >> (p1->weight);
    cout << "Company: " << (*p1).name_company << endl;
    cout << "Diameter: " << (*p1).diameter << endl;
    cout << "Weight: " << (*p1).weight << endl;
    delete p1;
    return 0;
}