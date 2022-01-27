// ex9.cpp -- read file and deal with file
#include<iostream>
#include<cstring>
#include<fstream>

// const char filename[30] = "D:\\code\\C++\\chapter6\\patrons.txt";

struct Patron
{
    char name[20];
    int donation ;
};

int main()
{
    using namespace std;
    ifstream inFile;
    inFile.open("D:\\code\\C++\\chapter6\\patrons.txt");
    int num;
    int count = 0;
    (inFile >> num).get();
    Patron* patrons = new Patron[num];
    for (int i = 0; i < num; i++)
    {
        inFile.getline(patrons[i].name,20);
        (inFile >> patrons[i].donation).get();
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
//display Patrons
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
    inFile.close();
    return 0;
}