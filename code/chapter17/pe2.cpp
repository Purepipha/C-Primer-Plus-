// pe2.cpp -- keyboard input save to file
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
    using namespace std;
    if (argc == 1)
    {
        cout << "Useage[s]" << argv[0] << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++)
    {
        cout << "Enter the text you want to save to " << argv[i] << endl;
        ofstream fout;
        fout.open(argv[i]);
        cout << "Enter ctrl + Z to get EOF:\n";
        char ch;
        while (cin.peek() != EOF)
        {
            cin.get(ch);
            // fout << ch;
            fout.put(ch);
        }
        fout.clear();
        fout.close();
    }
    cout << "Done\n";
    return 0;
}