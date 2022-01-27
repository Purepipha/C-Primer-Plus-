// pe3.cpp -- test hangman words form file
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    using std::cout;
    using std::string;
    using std::cin;
    using std::vector;
    using std::ifstream;
    vector<string> wordlist;
    string word;            // record word from file
// input words from files
    ifstream inFlie;
    inFlie.open("wordlist.txt");
    if (!inFlie.is_open())
    {
        cout << "Can't open the file. Bye.\n";
        exit(EXIT_FAILURE);
    }
    while (inFlie >> word)
        wordlist.push_back(word);
    inFlie.close();
// hangman game
    char play;
    cout << "Will you play the game? <y/n>";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        srand(time(0));
        string target = wordlist[rand() % wordlist.size()];
        int length = target.size();
        string attempt(length, '-');
        string badchars;
        int guesses = target.size();
        cout << "Guess my secret word. It has " << length 
             << " letters, and your guess\n"
             << "one letter at a time. You get "<< guesses
             << " wrong guesses.\n";
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (attempt.find(letter) != string::npos || 
                badchars.find(letter) != string::npos)
            {
                cout << "You have guessed the letter. Try again.\n";
                continue;
            }
            int pos = target.find(letter);
            if (pos == string::npos)
            {
                cout << "Oh, bad guess!\n";
                badchars += letter;
                guesses--;
            }
            else
            {
                cout << "Good guess!\n";
                while (pos != string::npos)
                {
                    attempt[pos] = letter;
                    pos = target.find(letter,pos + 1);
                }
            }
            cout << "Your word: " << attempt << std::endl;
            if (attempt != target)
            {
                if (badchars.size() > 0)
                    cout << "Bad choices: " << badchars << std::endl;
                cout  << guesses << " bad guesses left\n";
            }
        }

        if (guesses > 0)
            cout << "Congratlations! You guess the word: " << target << std::endl;
        else
            cout << "Sorry, the word is " << target << std::endl;
        cout << "Will you play another? <y/n>";
        cin >> play;
    }
    cout << "Done\n";
    return 0;
}

