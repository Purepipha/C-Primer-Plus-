// lotto.cpp -- probability of win
#include<iostream>
long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed:\n";
    while((cin >> total >> choices) && total >= choices)
    {
        cout << "You have chance in ";
        cout << probability(total, choices);
        cout << " of winning.\n";
        cout << "Next two numbers(q to quit): ";
    }
    cout << "bye\n";
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1;
    // for (int i = picks; i > 0; i--)
    // {
    //     result = result * (numbers + i - picks) / i;
    // }
    for(int n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}