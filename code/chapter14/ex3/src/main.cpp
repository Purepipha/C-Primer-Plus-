// workmi12.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include "queuetp.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    QueueTP<Worker *> qlolas(SIZE);

    int ct;
	Worker * lolas[SIZE];
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employmee catagory:\n"
             << "w: waiter  s: singer   "
             << "t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq",choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w': lolas[ct] = new Waiter;
				  qlolas.enqueue(lolas[ct]);
                  break;
        case 's': lolas[ct] = new Singer;
				  qlolas.enqueue(lolas[ct]);
                  break;
        case 't': lolas[ct] = new SingingWaiter;
				  qlolas.enqueue(lolas[ct]);
                  break;
        default:
            break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        Worker * temp;
		qlolas.dequeue(temp);
        temp->Show();
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";
    return 0;
}