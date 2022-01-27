// arrfun4.cpp -- funciton with an array range
#include<iostream>
const int Arsize = 8;

int sum_arr(const int * begin, const int * end);

int main()
{
    using namespace std;
    int cookies[Arsize] = {1,2,4,8,16,32,64,128};

    int sum = sum_arr(cookies, cookies + Arsize);
    cout << "Total cookies eaten: " << sum << " cookies.\n";
    sum = sum_arr(cookies, cookies + 3);
    cout << "First three eaters ate : " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, cookies + Arsize);
    cout << "Last four eaters ate : " << sum << " cookies.\n";

}

int sum_arr(const int * begin, const int * end)
{
    int total = 0;
    const int * pt; // need const
    for (pt = begin; pt != end; pt++)
        total += *pt;
    return total;
}