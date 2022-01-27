// pe4.cpp -- definition of int reduce(long ar[], int n) and use STL
#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int reduce(long ar[], int n);

int main()
{
    using std::cout;
    using std::endl;
    srand(time(0));
    const int LIM = 20;
    long testar[LIM];
    for (int i = 0; i < LIM; i++)
        testar[i] = rand() % 10;
    cout << "Before using reduce() function, the test array:\n";
    for (int i = 0; i < LIM; i++)
    {
        cout << testar[i] << " ";
        if (i % 10 == 9)
            cout << "\n";
    }
    if (LIM % 10 != 0)
        cout << endl;
    int len = reduce(testar, LIM);
    cout << "After using reduce() function, the test array:\n";
    for (int i = 0; i < len; i++)
    {
        cout << testar[i] << " ";
        if (i % 10 == 9)
            cout << "\n";
    }
    if (len % 10 != 0)
        cout << endl;
    
    cout << "Done\n";
    return 0;

}
// // version use set
// int reduce(long ar[], int n)
// {
//     std::set<long> temp;
//     // std::vector<long> temp(n);
//     for (int i = 0; i < n; i++)
//         temp.insert(ar[i]);
//     int len = temp.size();
//     int i;
//     copy(temp.begin(), temp.end(), ar);
//     return len;
// }

// version use sort and unique
int reduce(long ar[], int n)
{
    std::sort(ar, ar + n);
    auto air = std::unique(ar, ar + n);
    return (air - ar) ;
}