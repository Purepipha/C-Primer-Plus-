// ex7_pissa_record.cpp -- use struct to record pissa
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
    pissa p1;
    cout << "Enter the company of pissa: ";
    cin.getline(p1.name_company,30);
    cout << "Enter the diameter of pissa: ";
    cin >> p1.diameter;
    cout << "Enter the weight of pissa: ";
    cin >> p1.weight;
    cout << "Company: " << p1.name_company << endl;
    cout << "Diameter: " << p1.diameter << endl;
    cout << "Weight: " << p1.weight << endl;
    return 0;
}