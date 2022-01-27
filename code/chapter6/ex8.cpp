// ex8.cpp -- read a file by char
#include<iostream>
#include<fstream>

const int Fnsize = 40;
int main()
{
    using namespace std;
    ifstream inFile;
    char ch;
    int count = 0;
    char filename[Fnsize];
    cout << "Enter the filename you want to open: \n";
    cin.getline(filename, Fnsize);
    inFile.open(filename);
    inFile.get(ch);
    while(!inFile.eof())
    {
        ++count;
        cout << ch;
        inFile.get(ch);  // 
    }
    cout << "The file has " << count << " characters.\n";
    inFile.close();
    return 0;
}