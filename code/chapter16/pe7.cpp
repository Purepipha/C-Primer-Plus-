// pe7.cpp -- simulation of lottery card
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> Lotto(int numbers, int num_choices);
void show(int x) { std::cout << x << ' ';}
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    int numebrs, num_choices;
    cout << "Enter the numbers of point and the numebr of chooses <q to quit>: ";
    while (cin >> numebrs >> num_choices)
    {
        auto winner = Lotto(numebrs,num_choices);
        cout << "The winner's numbers is ";
        std::for_each(winner.begin(), winner.end(), show);
        cout << endl;
        cout << "Enter next two numbers <q to quit>: ";
    }
    
    return 0;
}

vector<int> Lotto(int numbers, int num_choices)
{
    vector<int> temp;
    vector<int> result;
    for (int i = 1; i <= numbers; i++)
        temp.push_back(i);
    for (int i = 0; i < num_choices; i++)
    {
        std::random_shuffle(temp.begin(), temp.end());
    // make sure the value not repeat
        while (find(result.begin(), result.end(),temp[0]) != result.end())
            std::random_shuffle(temp.begin(), temp.end());
        result.push_back(temp[0]);
    }
    return result;
}