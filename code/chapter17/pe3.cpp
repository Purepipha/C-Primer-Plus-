// pe3.cpp -- copy the text from file 1 to file 2
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
    using namespace std;
    if (argc == 1)
    {
        cout << "Useage[s]" << argv[0] << endl;
        cout << "First file is the original file, and second file is target file\n";
        exit(EXIT_FAILURE);
    }
// prototype fstream object
    ifstream fin;
    ofstream fout;
// filename interact with stream object
    fin.open(argv[1]);
    fout.open(argv[2]);
// fin.open() fail
    if (!fin.is_open())
    {
        cerr << "Can't open the file: " << argv[1] << endl;
        fin.clear();
        exit(EXIT_FAILURE);
    }
    cout << "Open the copy file: " << argv[1] << endl;
    
    char ch;
    cout << "Start copy and paste\n";
// copy and paste
    while (fin.get(ch))
    {
        fout << ch;
    }
    cout << "Copy complete\n";
    fin.clear();
    fin.close();
    fout.close();

    return 0;
}