// pe6.cpp use queue to realize bank
#include <iostream>
#include <cstdlib>      // for rand() and srand()
#include <ctime>        // for time()
#include <queue>
const int MIN_PER_HR = 60;

// Custormer items
class Customer
{
private:
    long arrive;                // arrive time for customer
    int processtime;            // processing time for customer
public:
    Customer() { arrive = processtime = 0; }

    void set(long when);
    long When() const { return arrive; }
    int Ptime() const { return processtime; }
};
typedef Customer Item;
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

bool newcustomer(double x); // is there a new customer

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    using std::queue;
// setting things up
    std::srand(std::time(0));   // random intializing of rand

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter the maximum size of queue: ";
    int qs;
    cin >> qs;
    queue<Item> line;            // line queue holds up to qs people

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;  // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;                 // new customer data
    long turnaways = 0;        // turn away by full queue
    long customers = 0;        // joined the queue
    long served = 0;           // served during the simulation
    long sum_line = 0;         // cmulative line length
    long wait_time = 0;        // time untile autoteller is free
    long line_wait = 0;        // cumulative time in line
// running the  simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if(newcustomer(min_per_cust))   // have newcomer
        {
            if(line.size() == qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);        // cycle = time of arrival
                line.push(temp);
                // line.enqueue(temp);     // add newcomer to line
            }
        }
        if(wait_time <= 0 && !line.empty())
        {
            temp = line.front();
            line.pop();         // attend next customer
            wait_time = temp.Ptime();   // for wait_time minuetes
            line_wait += cycle - temp.When();
            served++;
        }
        if(wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }
// reporting results
    if(customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " avergae wait time: "
             << (double) line_wait / served << "minutes\n";
    }
    else
        cout << "No customerr!\n";
    cout << "Done!\n";

    return 0;
}

// x = average time in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}