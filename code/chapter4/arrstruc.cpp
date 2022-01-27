// arrstruc.cpp -- an array of structure
#include<iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable guests[2]=
    {
        {"Aurthor", 0.6 , 21.99},
        {"John", 200 , 300.2}
    };

    cout << "The guests " << guests[0].name;
    cout << " and " << guests[1].name;
    cout << "\nhave a comnbine volume of "
         << guests[0].volume + guests[1].volume
         << "cubice feet.\n";
    return 0; 
}