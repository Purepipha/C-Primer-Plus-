// pe5.cpp -- template definition of int reduce(long ar[], int n) and use STL

// pe4.cpp -- definition of int reduce(long ar[], int n) and use STL
#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>

template <class T>
int reduce(T ar[], int n);

int main()
{
    using std::cout;
    using std::endl;
    srand(time(0));
// test long numbers
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
    int len = reduce<long>(testar, LIM);
    cout << "After using reduce() function, the test array:\n";
    for (int i = 0; i < len; i++)
    {
        cout << testar[i] << " ";
        if (i % 10 == 9)
            cout << "\n";
    }
    if (len % 10 != 0)
        cout << endl;
// test string
    std::string test_sar[LIM] = {"Union", "for", "cat", "dog", "for", "why", "how", "what", "want", "cat",
        "white", "can", "air", "dog", "for", "why", "how", "what", "want", "cat"};
    cout << "Before using reduce() function, the test array:\n";
    for (int i = 0; i < LIM; i++)
    {
        cout << test_sar[i] << " ";
        if (i % 10 == 9)
            cout << "\n";
    }
    if (LIM % 10 != 0)
        cout << endl;
    len = reduce<std::string>(test_sar, LIM);
    cout << "After using reduce() function, the test array:\n";
    for (int i = 0; i < len; i++)
    {
        cout << test_sar[i] << " ";
        if (i % 10 == 9)
            cout << "\n";
    }
    if (len % 10 != 0)
        cout << endl;
    cout << "Done\n";
    return 0;

}
// version use set
template <class T>
int reduce(T ar[], int n)
{
    std::set<T> temp;
    // std::vector<long> temp(n);
    for (int i = 0; i < n; i++)
        temp.insert(ar[i]);
    int len = temp.size();
    int i;
    copy(temp.begin(), temp.end(), ar);
    return len;
}

// // version use sort and unique
// template <class T>
// int reduce(T ar[], int n)
// {
//     std::sort(ar, ar + n);
//     auto air = std::unique(ar, ar + n);
//     return (air - ar) ;
// }