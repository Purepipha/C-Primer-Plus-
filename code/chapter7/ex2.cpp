// ex2.cpp -- calculate the average grade of golf
#include<iostream>

const int Max = 10;

int input_ar(double *grades, int Max);
void show(double grade[], int n);
double cal_av(double grade[], int n);

int main()
{
    using namespace std;
    double grade[Max];
    double average_g;
    
    int len = input_ar(grade,Max);
    show(grade,len);
    average_g = cal_av(grade,len);
    cout << "Average grade = " << average_g << endl;
    return 0;
}

int input_ar(double *grades, int n)
{
	using namespace std;
	int count = 0;
	cout << "Enter the grade of golf(enter q to quit): ";
	while(count < n && cin >> grades[count])
	{
		count++;
        if(count == 10)
            break;
		cout <<"Next grade(enter q to quit): ";
	}
	return count;
}

void show(double grade[], int n)
{
	using namespace std;
	cout << "All grades: ";
	for(int i = 0; i < n; i++)
		cout << grade[i] << " ";
	cout << endl;
}

double cal_av(double grade[], int n)
{
	double sum = 0;
	for(int i = 0; i < n; i++)
		sum += grade[i];
	return sum / n;
}