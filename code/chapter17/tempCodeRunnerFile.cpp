// pe4.cpp -- combination of two files to third file
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
// get file1 and file2 to file3
    string input1, input2;
    int cnt_eof1 = 0;           // count times the fin1.peek() == EOF
    int cnt_eof2 = 0;           // count times the fin2.peek() == EOF
    while (1)
    {
        if (fin1.peek() != EOF || fin2.peek() != EOF)
        {
            if (getline(fin1, input1))          // get file1 one line
            {
                fout << input1;                 // file1 ont line to output
                if (fin2.peek() == EOF)         
                    cnt_eof2++;                 // get the times of fin2.peek() == EOF to realize lines of file 1 > lines of file 2
                if (cnt_eof2 >= 1 && fin1.peek() != EOF)    // make sure this line of file1 is not last line
                    fout << endl;               // when lines of file1 > lines of file2, should add endl to file3
            }
            if (getline(fin2,input2))           // get file2 one line
            {
                if (fin1.peek() == EOF)         
                    cnt_eof1++;                 // get the times of fin1.peek() == EOF to realize lines of file 1 < lines of file 2
                if (cnt_eof1 <= 1)              // when lines of file2 > lines of file1
                {
                    fout << ' ';                // the blank of between file1 line and file2 line
                    fout << input2;
                    if (fin1.peek() != EOF)     // make sure the lines of file1 and lines of file2 is equal
                        fout << endl;
                }
                else                            // when the lines of file2 > lines of file1
                {
                    fout << endl;
                    fout << input2;
                }
            }       
        }
        else
            break;
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