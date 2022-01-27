// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib>		// for rand and srand()
#include <ctime>		// for time
#include "queue.h"

const int MIN_PER_HR = 60;
bool newcustomer(double x);		// is there a new customer
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = hours * MIN_PER_HR;
	
	double perhour = 20;
	int qs = int(4*perhour);
	

	Item temp;                 // new customer data
    long turnaways = 0;        // turn away by full queue
    long customers = 0;        // joined the queue
    long served = 0;           // served during the simulation
    // long sum_line = 0;         // cmulative line length
    long wait_time1 = 0;       // time untile autoteller1 is free
	long wait_time2 = 0;	   // time untile autoteller2 is free
    long line_wait = 0;        // cumulative time in line
	do
	{
		int qs = int(4*perhour);
		double min_per_cust = MIN_PER_HR / perhour;		// is necessary at while body
		Queue line1 (qs),line2(qs);
    	turnaways = 0;        // turn away by full queue
    	customers = 0;        // joined the queue
    	served = 0;           // served during the simulation
    	// sum_line = 0;         // cmulative line length
    	wait_time1 = 0;
		wait_time2 = 0;        // time untile autoteller is free
    	line_wait = 0;        // cumulative time in line
		for(int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if(newcustomer(min_per_cust))
			{
				if(line1.isfull()&&line2.isfull())	// line1 full && line2 full
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);
					if(line1.queuecount()<line2.queuecount())
						line1.enqueue(temp);
					else
						line2.enqueue(temp);
				}
			}

			if(wait_time1 <= 0 && !line1.isempty())
			{
				line1.dequeue(temp);
				wait_time1 = temp.Ptime();
				line_wait += cycle - temp.When(); 
				served++;
			}
			if(wait_time2 <= 0 && !line2.isempty())
			{
				line2.dequeue(temp);
				wait_time2 = temp.Ptime();
				line_wait += cycle - temp.When(); 
				served++;
			}
			if(wait_time1 > 0)
			{
				wait_time1--;
			}
			if(wait_time2 > 0)
			{
				wait_time2--;
			}
		}
		cout << "Perhour = " << perhour << ":\n";
	// reporting results
    	if(customers > 0)
    	{
        	cout << "customers accepted: " << customers << endl;
        	cout << "  customers served: " << served << endl;
        	cout << "         turnaways: " << turnaways << endl;
			cout << " avergae wait time: "
				<< (double) line_wait / served << "minutes\n";
    	}
    	else
		{
			cout << "No customerr!\n";
		}
		perhour+=1;
	}while((double) line_wait / served < 1);
	cout << "Done\n";
    return 0;
}

// x = average time in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}