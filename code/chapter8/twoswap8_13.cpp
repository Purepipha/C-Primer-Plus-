// twoswap8_13.cpp -- specialization overrides a template
#include<iostream>
template<typename T>
void Swap(T &, T &);

struct  job
{
    char name[40];
    double salary;
    int floor;
};

// explicit specialization
template<>void Swap<job>(job &j1, job &j2);
void show(job &);

int main()
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios_base::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-genterated int swapper:\n";
    Swap(i,j); //generate a Swap(int & a, int & b)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job swapping:\n";
    show(sue);
    show(sidney);
    Swap(sue,sidney);
    cout << "After job swapping:\n";
    show(sue);
    show(sidney);
    return 0;
}

template<typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<>void Swap<job>(job &j1, job &j2)
{
    Swap(j1.salary, j2.salary);
    Swap(j1.floor, j2.floor);
}

void show(job &j)
{
    using std::cout;
    cout << "Name: " << j.name << ", Salary: " << j.salary;
    cout << ", Floor: " << j.floor << "\n";
}