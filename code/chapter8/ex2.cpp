// ex2.cpp -- using default argument and reference of structure
#include<iostream>
#include<cstring>
const int Size = 20;
struct CandyBar
{
    char name[Size];
    double weight;
    int carloris;
};

char  ps[Size] = {"Millennium Munch"};
void fill(CandyBar &, char * n = ps, double w = 2.85, int c = 350);
void show(const CandyBar &);

int main()
{
    using namespace std;
    char *cname = new char[Size];
    double cweight;
    int ccaloris;
    CandyBar cbs;
    fill(cbs);
    show(cbs);

    cout << "Enter the name of CandyBar: ";
    cin.getline(cname,Size);
    cout << "After input name:\n";
    fill(cbs, cname);
    show(cbs);

    cout << "Enter the weight of CandyBar: ";
    cin >> cweight;
    cin.get();
     cout << "After input weight:\n";
    fill(cbs, cname, cweight);
    show(cbs);

    cout << "Enter the weight of CandyBar: ";
    cin >> ccaloris;
    cin.get();
    cout << "After input caloris:\n";
    fill(cbs, cname, cweight, ccaloris);
    show(cbs);
    return 0;
}


void fill(CandyBar & cb, char * n, double w, int c)
{
    strcpy(cb.name,n);
    cb.weight = w;
    cb.carloris = c;
}

void show(const CandyBar &cb)
{
    using std::cout;
    cout << "Name: " << cb.name << "\tWeight: " << cb.weight;
    cout << "\tCarloris: " << cb.carloris << "\n";
}