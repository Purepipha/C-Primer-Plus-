// ex10.cpp -- using point to function
#include<iostream>

double calculate(double , double , double (*p) (double , double ));
double add(double x, double y);
double sub(double x, double y);
double multi(double x, double y);
double div(double x, double y);

int main()
{
    using namespace std;
    double (*pf[4]) (double , double) = {add, sub, multi, div};
    char op[4] = {'+','-','*','/'};
    double num1, num2;
    cout << "Enter two number(enter q to quit): ";
    while(cin >> num1 >> num2)
    {
        for(int i = 0; i < 4; i++)
        {
            double result = calculate(num1,num2, pf[i]);
            cout << num1 << " "<< op[i] << " " << num2 << " = " << result << endl;
        }
        cout << "Enter next two number(enter q to quit): ";
    }
    cout << "Done\n";
    return 0;
}

double calculate(double x, double y, double (*p) (double , double ))
{
    return (*p)(x,y); // return p(x,y) is right
}
double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double multi(double x, double y)
{
    return x * y;
}

double div(double x, double y)
{
    return x / y;
}