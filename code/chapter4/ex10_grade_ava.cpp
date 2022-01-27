// ex10_grade_ava.cpp -- use array to calculate average grade
#include<iostream>
#include<array>
int main()
{
    using namespace std;
    array<double,3> grades; 
    cout << "Enter the grade of run: ";
    cin >> grades[0];
    cout << "Enter the grade of run: ";
    cin >> grades[1];
    cout << "Enter the grade of run: ";
    cin >> grades[2];
    double average = (grades[0] + grades[1] + grades[2])/3;
    cout << "Average grade: " << average << endl;
    return 0;

}