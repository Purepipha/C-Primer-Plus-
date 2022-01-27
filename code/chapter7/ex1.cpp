// ex1.cpp -- calculate average with function
#include<iostream>

double cal_average(double x1, double x2);
int main()
{
    using namespace std;
    double num1, num2, result;
    cout << "Enter two number(enter 0 to quit): ";
    cin >> num1 >> num2;
    while(num1 * num2 != 0)
    {
        if(!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input, process will terminate.\n";
            break;
        }
        result = cal_average(num1, num2);
        cout << "The calculate reuslt is " << result << ".\n";
        cout << "Enter next two number(enter 0 to quit): ";
        cin >> num1 >> num2;
    }
    cout << "Bye\n";
    return 0;

}

double cal_average(double x, double y)
{
    double aver;
    aver = 2.0 * x * y / (x + y);
    return aver;
}