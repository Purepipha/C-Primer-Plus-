// ex3.cpp -- using placement new to store structure array
#include<iostream>
#include<cstring>

const int BUF = 500;
const int CSize = 20;

struct chaff
{
    char dross[CSize];
    int slag;
};
// dynamic ram
char * buffer = new char[BUF];
//enter dross is empty string to stop enter
int setchaff(chaff & c);
void showchaff(const chaff & c);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    int num;
    int count = 0;                          // store the enter num of chaff
    cout << "Enter the number of chaff: ";
    cin >> num;
    cin.get();
    chaff *arr = new(buffer) chaff[num];
    for(int i = 0; i < num; i++)
    {
        cout << "Chaff #" << i + 1 << ":\n";
        if(!setchaff(arr[i]))
            break;
        count++;
    }

    for(int i = 0; i < count; i++)
    {
        cout << "Chaff #" << i + 1 << ":\t";
        showchaff(arr[i]);
    }
    cout << "Bye\n";
    delete []buffer;
    return 0;
    
}

int setchaff(chaff & c)
{
    using std::cout;
    using std::cin;
    char name[CSize];
    cout << "Dross(enter empty string to quit): ";
    cin.getline(name,CSize);
    if(!strcmp(name,""))
        return 0;
    strcpy(c.dross,name);
    cout << "slag: ";
    cin >> c.slag;
    cin.get();
    return 1;
}

void showchaff(const chaff & c)
{
    using std::cout;
    cout << "Dross: " << c.dross << ", slag = " << c.slag << "\n";
}