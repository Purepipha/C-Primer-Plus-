// ex3.cpp -- rand walk problem
// compile with the vect.cpp file
#include <cstdlib>  // rand(), srand() protypes
#include <ctime>    // time() protype
#include "vector1.h"
unsigned long average(unsigned long arr[],int n);
unsigned long findmax(unsigned long arr[],int n);
unsigned long findmin(unsigned long arr[],int n);
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    double target;
    double dstep;
    int times;
    cout << "Enter target distance: ";
    cin >> target;
    cout << "Enter step length: ";
    cin >> dstep;
    cout << "Enter the times you want to test: ";
    cin >> times;
    unsigned long steps[times];
    for(int i = 0; i < times; i++)
    {
        // initialize and reset result to 0
        steps[i] = 0;
        result.reset(0.0, 0.0); // is necessary

        while(result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps[i]++;
        }
    }
    unsigned long steps_max = findmax(steps, times);
    unsigned long steps_min = findmin(steps, times);
    unsigned long steps_ave = average(steps, times);

    cout << "After " << times << " times test:\n";
    cout << "Maximum steps is " << steps_max << endl;
    cout << "Minimun steps is " << steps_min << endl;
    cout << "Average steps is " << steps_ave << endl;
    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n')
        continue;
    return 0;
}

unsigned long average(unsigned long arr[],int n)
{
    unsigned long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

unsigned long findmax(unsigned long arr[],int n)
{
    unsigned long max = 0;
    for(int i = 0; i < n; i++)
        max = max < arr[i] ? arr[i] : max;
    return max;
}

unsigned long findmin(unsigned long arr[],int n)
{
    unsigned long min = arr[0];
    for(int i = 0; i < n; i++)
        min = min < arr[i] ? min : arr[i];
    return min;
}