#include<iostream>
int main()
{
    using namespace std;
    int yam[3];
    yam[0] = 7;
    yam[1] = 8;
    yam[2] = 6;
    int yamcosts[3] = {20, 30, 5};
    cout << "Total yams = ";
    cout << yam[0] + yam[1] + yam[2] << endl;
    cout << "The pcakage with " << yam[1] << "yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = yam[0] * yamcosts[0] + yam[1] * yamcosts[1];
    total = total + yam[2] * yamcosts[2];
    cout << "The total yams expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yam;
    cout << " bytes.\n";
    cout << "Size of one element = " << sizeof yam[0];
    cout << " bytes.\n";
    return 0;
}