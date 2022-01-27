// ex6.cpp -- record the Patrons
#include<iostream>
#include<cstring>
struct Patron
{
    char name[20];
    int donation ;
};

int main()
{
    using namespace std;
    int num;
    int count = 0;
    cout << "Please enter the number of patrons: ";
    (cin >> num).get();
    Patron* patrons = new Patron[num];
    cout << "Please enter the patrons' name and donations,\n";
    cout << "Enter the partons' name: ";
    for (int i = 0; i < num; i++)
    {
        cout << "Praton #" << i + 1 << ":\n";
        cout << "Name: ";
        cin.getline(patrons[i].name,20);
        cout << "Donation: ";
        cin >> patrons[i].donation;
        cin.get();
    }
// display Grand Patrons
    cout << "Grand Patrons\n";
    for (int i = 0; i < num; i++)
    {
        if(patrons[i].donation > 10000)
        {
            cout << "Name: " << patrons[i].name
                 << ",  donation: " << patrons[i].donation << endl;
            count++;
        } 
    }
    if(count == 0)
    {
        cout << "none\n";
    }
    count = 0;
    cout << "Patrons\n";
    cout << "Name: ";
    for (int i = 0; i < num; i++)
    {
        if(patrons[i].donation <= 10000)
        {
            cout << patrons[i].name << "    ";
            count++;
        } 
    }
    if(count == 0)
    {
        cout << "none";
    }
    return 0;
}