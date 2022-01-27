// pe4_a.cpp -- combination of two files to third file 
// first get lines of two files
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
    using namespace std;
// no other file
    if (argc == 1)   
    {
        cout << "Useages(s): " << argv[0] << endl;
    }
    if (argc !=4 )
    {
        cerr << "You don't have input correct numbers of file.\n";
        cout << "First and second: orginal file, third: output file" << endl;
        exit(EXIT_FAILURE);
    }
// prototype file stream object
    ifstream fin1;
    ifstream fin2;
    ofstream fout;
// file with stream
    fin1.open(argv[1]);
    fin2.open(argv[2]);
    fout.open(argv[3]);
// if file is not open
    if (!fin1.is_open())
    {
        cerr << "Could not open " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    if (!fin2.is_open())
    {
        cerr << "Could not open " << argv[2] << endl;
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open())
    {
        cerr << "Could not open " << argv[3] << endl;
        exit(EXIT_FAILURE);
    }
// get lines of file1 and lines of file2
    string input;                // get file input
    int lines1 = 0;
    int lines2 = 0;
    while (getline(fin1, input))
        lines1++;
    while (getline(fin2,input))
        lines2++;
    // close 
    fin1.clear();
    fin1.close();
    fin2.clear();
    fin2.close();
    // link restart
    fin1.open(argv[1]);
    fin2.open(argv[2]);
    if (lines1 == lines2)
    {
        for(int i = 0; i < lines1 - 1; i++)
        {
            getline(fin1, input);
            fout << input << ' ';
            getline(fin2, input);
            fout << input << endl;
        }
        getline(fin1, input);
        fout << input << ' ';
        getline(fin2, input);
        fout << input;              // last line have not endl
    }
    if (lines1 < lines2)
    {
        for (int i = 0; i < lines1; i++)
        {
            getline(fin1, input);
            fout << input << ' ';
            getline(fin2, input);
            fout << input << endl;
        }
        for (int i = 0; i < lines2 - lines1 - 1; i++)
        {
            getline(fin2, input);
            fout << input << endl;
        }
        getline(fin2, input);
        fout << input;
    }

    if (lines1 > lines2)
    {
        for (int i = 0; i < lines2; i++)
        {
            getline(fin1, input);
            fout << input << ' ';
            getline(fin2, input);
            fout << input << endl;
        }
        for (int i = 0; i < lines1 - lines2 - 1; i++)
        {
            getline(fin1, input);
            fout << input << endl;
        }
        getline(fin1, input);
        fout << input;
    }

    
// close all file fstream
    fin1.clear();
    fin1.close();
    fin2.clear();
    fin2.close();
    fout.clear();
    fout.close();
    cout << "Done\n";
    return 0;
//
}