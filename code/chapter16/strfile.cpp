// strfile.cpp -- reading strings from a file
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
int main()
{
    using namespace std;
    ifstream inFile;
    inFile.open("tobuy.txt");
    if (inFile.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }
    string item;
    int count = 0;
    getline(inFile, item, ':');
    while (inFile)
    {
        ++count;
        cout << count << ": " << item << endl;
        getline(inFile, item, ':');
    }
    cout << "Done\n";
    inFile.close();
    return 0;
}