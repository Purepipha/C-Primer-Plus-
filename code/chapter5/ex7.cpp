// ex7.cpp -- struct,new,for
#include<iostream>
#include<string>
#include<cstring>

// struct car
// {
//     std::string make;
//     int year;
// };
struct car
{
    char make[30];
    int year;
};

int main()
{
    using namespace std;
    char temp[20];
    int temp_y;
    int n;
    cout << "How many cars do you wish to catalog? ";
    (cin >> n).get();
    car* Car = new car[n];
    for(int i = 0; i < n; ++i)
    {
        cout << "Car #" << (i+1) << ":\n"; 
        cout << "Please enter the make: ";
        cin.getline(Car[i].make,30);
        cout << "Please enter the year made: ";
        (cin >> Car[i].year).get();
    }
    for(int i = 0; i < n; ++i)
        cout << (Car+i)->year << " " << Car[i].make << endl;
    return 0;
}

