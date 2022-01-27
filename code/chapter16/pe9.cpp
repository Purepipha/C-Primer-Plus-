// pe9.cpp -- compare the speed list.sort and copy list to vector, sort, and copy to list
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>

const int LIM = 10000000;         // numbers of elements

int main()
{
    using std::cout;
    using std::sort;
    using std::list;
    using std::vector;
    using std::copy;
    using std::endl;
    using std::insert_iterator;

    cout << "Number of elements: " << LIM << endl;
// generate elements of vector<int> vi0
    srand(time(0));             // generate random seeds
    vector<int> vi0;
    for (int i = 0; i < LIM; i++)
        vi0.push_back(rand() % LIM);
// copy vi0 to ci and li
    vector<int> vi;
    list<int> li;
    copy(vi0.begin(), vi0.end(), insert_iterator<vector<int>>(vi, vi.begin()));
    copy(vi0.begin(), vi0.end(), insert_iterator<list<int>>(li, li.begin()));
/**** calculate the time of sort(vi) and li.sort() ****/
// calculate the time of sort(vi.begin(), vi.end());
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "The time of sort(vi.begin(), vi.end()):\n";
    cout << (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl;
// calculate the time of list.sort();
    start = clock();
    li.sort();
    end = clock();
    cout << "The time of li.sort():\n";
    cout << (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl;

/**** calculate the time of copy() + sort(vi.begin(),vi.end()) + copy() ****/
// clear list and vi
    li.erase(li.begin(), li.end());
    vi.erase(vi.begin(), vi.end());
// calculate time
    copy(vi0.begin(), vi0.end(), insert_iterator<list<int>>(li, li.begin()));
    start = clock();
    copy(li.begin(), li.end(), insert_iterator<vector<int>>(vi, vi.begin()));
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), insert_iterator<list<int>>(li, li.begin()));
    end = clock();
    cout << "The time of combination:\n";
    cout << (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl;

    return 0;

}