// cingolf.cpp -- 
#include<iostream>
const int Max = 5;
int main()
{
    using namespace std;
    double score[Max];
//get data
    cout << "Please Enter your golf score.\n";
    cout << "You must enter " << Max << " rounds.\n";
    for(int i = 0; i < Max; i++)
    {
        cout << "round #" << i << ": ";
        while(!(cin >> score[i]))
        {
            cin.clear(); // reset input;
            while (cin.get() != '\n')
                continue; //get rid of bad input
            cout << "Please enter a numbet: ";
        }
    }
// calculate total score
    double total = 0;
    for(int j =0; j < Max; j++)
        total += score[j];
// report results
    cout << total / Max << " = average score "
         << Max << " rounds\n";
    return 0;
}