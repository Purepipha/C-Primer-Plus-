#include<iostream>

    
int main()
{
    using namespace std;
    char first_name[20];
    char last_name[10];
    char grade;
    int age;
    cout << "What is your first name? ";
    cin.getline(first_name,20); // cin.getline(s1.first_name,20).get() get()函数和getlin()函数
    cout << "What is your last name? ";
    cin.getline(last_name,20); // cin.getline(s1.last_name,20).get();
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;
    cout << "Name: " << last_name << ", " 
         << first_name << endl;
    grade = grade + 1;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;
    return 0;
}