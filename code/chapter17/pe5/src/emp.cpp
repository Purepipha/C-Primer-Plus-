// emp.cpp -- methods for mi

#include<cctype>
#include "emp.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
// function definition
void ShowMenu()
{
    cout << "Enter your choice e m f h <q to quit>:\n"
         << "e: employee        m: manager\n"
         << "f: fink            h: highfink\n";
}

void ListHeader()
{
    cout << std::right << setw(8) << "Sequence"
         << setw(15) << "Name" << setw(15) << "Job"
         << setw(26) << "Number managing employees"
         << setw(15) << "Reports to" << endl;;
}


// methods for employee_class
// protected mothod
void employee::Data() const
{
    string name = lname + ", " + fname;
    cout << setw(15) << name << setw(15) << job;
}

void employee::Get()
{
    cout << "Enter firstname: ";
    cin >> fname;
    cout << "Enter lastname: ";
    cin >> lname;
    while (cin.get() != '\n')
        continue;
    cout << "Enter job: ";
    getline(cin, job);
}
void employee::Write(std::ofstream & fo) const
{
    fo << fname << endl;
    fo << lname << endl;
    fo << job << endl;
}
void employee::Read(std::ifstream & fi)
{
    getline(fi, fname);
    getline(fi, lname);
    getline(fi, job);
}
// public method
employee::employee() { }

employee::employee(const std::string & fn, const std::string & ln,
              const std::string & j) : fname(fn), lname(ln), job(j) { }

void employee::ShowAll() const
{
    employee::Data();
    cout << endl;
}

void employee::SetAll()
{
    cout << "Category employee:\n";
    employee::Get();
}

void employee::writeall(std::ofstream & fo) const
{
    fo << Employee << endl;
    employee::Write(fo);
}

void employee::readall(std::ifstream & fi)
{
    employee::Read(fi);
}
std::ostream & operator<<(std::ostream & os, employee & e)
{
    os << e.lname << ", " << e.fname;
    return os;
}
employee::~employee() { }         // is necessary


// methods for manager class
// protected method
void manager::Get()
{
    cout << "Enter number of in charge of employees: ";
    cin >> inchargeof;
    while (cin.get() != '\n')
        continue;
}

void manager::Data() const
{
    cout << setw(26) << inchargeof;
}

void manager::Write(std::ofstream & fo) const
{
    fo << inchargeof << endl;
}

void manager::Read(std::ifstream & fi)
{
    fi >> inchargeof;
    fi.get();               // 
}
// public method
manager::manager() { }
manager::manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico) : employee(fn, ln, j),
            inchargeof(ico) { }
manager::manager(const employee & e, int ico) : employee(e), inchargeof(ico) { }
manager::manager(const manager & m) : employee(m)
{
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
    employee::Data();
    manager::Data();
    cout << endl;
}

void manager::SetAll()
{
    cout << "Category manager:\n";
    employee::Get();
    manager::Get();
}

void manager::writeall(std::ofstream & fo) const
{
    fo << Manager << endl;
    employee::Write(fo);
    manager::Write(fo);
}

void manager::readall(std::ifstream & fi)
{
    employee::Read(fi);
    manager::Read(fi);
}
// methods for fink class
// protected method
void fink::Get()
{
    cout << "Enter repeorts to : ";
    getline(cin, reportsto);
}

void fink::Data() const
{
    cout << setw(15)<< reportsto;
}

void fink::Write(std::ofstream & fo) const
{
    fo << reportsto << endl;
}

void fink::Read(std::ifstream & fi)
{
    getline(fi, reportsto);
}
// public method
fink::fink() { }
fink::fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo) : employee(fn, ln, j),
         reportsto(rpo) { }
fink::fink(const employee & e, const std::string & rpo) : 
        employee(e), reportsto(rpo) { }
fink::fink(const fink & f) : employee(f)
{
    reportsto = f.reportsto;
}
void fink::ShowAll() const
{
    employee::Data();
    cout << setw(26) << " ";
    fink::Data();
    cout << endl;
}
void fink::SetAll()
{
    cout << "Category fink:\n";
    employee::Get();
    fink::Get();
}
void fink::writeall(std::ofstream & fo) const
{
    fo << Fink << endl;
    employee::Write(fo);
    fink::Write(fo);
}
void fink::readall(std::ifstream & fi)
{
    employee::Read(fi);
    fink::Read(fi);
}
// methods for highfink class
highfink::highfink() { }
highfink::highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico) : employee(fn, ln, j), manager(fn, ln, j, ico),
             fink(fn, ln, j, rpo) { }
highfink::highfink(const employee & e, const std::string & rpo, int ico) : 
             employee(e), manager(e, ico), fink(e, rpo) { }

highfink::highfink(const manager & m, const std::string & rpo) : employee(m),
            manager(m), fink(m,rpo) { }
        
highfink::highfink(const fink & f, int ico) : employee(f), manager(f, ico),
            fink(f) { }

highfink::highfink(const highfink & h) : employee(h), manager(h), fink(h) { }

void highfink::ShowAll() const
{
    employee::Data();
    manager::Data();
    fink::Data();
    cout << endl;
}

void highfink::SetAll()
{
    cout << "Category highfink:\n";
    employee::Get();
    manager::Get();
    fink::Get();
}

void highfink::writeall(std::ofstream & fo) const
{
    fo << Highfink << endl;
    employee::Write(fo);
    manager::Write(fo);
    fink::Write(fo);
}

void highfink::readall(std::ifstream & fi)
{
    employee::Read(fi);
    manager::Read(fi);
    fink::Read(fi);
}

// function definition
int Menu(employee * e[], std::ofstream & fout, int n)
{
    
    int i;
    char choice;
	for (i = 0; i < n; i++)
	{
	    ShowMenu();
		cin >> choice;
        choice = tolower(choice);
		if (choice == 'q')
			break;
	    while (!strchr("emfh",choice))
	    {
		    cout << "Please enter e m f h\n";
		    cin >> choice;
	    }
	    switch (choice)
	    {
	    case 'e': e[i] = new employee;
			      e[i]->SetAll();
			      e[i]->writeall(fout);
			      break;
	    case 'm': e[i] = new manager;
			      e[i]->SetAll();
			      e[i]->writeall(fout);
			      break;
	    case 'f': e[i] = new fink;
			      e[i]->SetAll();
			      e[i]->writeall(fout);
			      break;
	    case 'h': e[i] = new highfink;
                  e[i]->SetAll();
                  e[i]->writeall(fout);
                  break;
        }
	}
    return i;
}

void ShowList(employee * ar[], int n)
{
    ListHeader();
    for (int i = 0; i < n; i++)
    {
        cout << setw(8) << i + 1;
        ar[i]->ShowAll();
    }
        
}

int Readfile(std::ifstream & fin, employee * pc[], int n)
{
    int i = 0;
	int classtype;

	while (fin >> classtype)    // get emloyee class
	{
		fin.get();
		switch(classtype)   
		{
			case Employee : pc[i] = new employee;
							pc[i]->readall(fin);
							break;
			case Manager :  pc[i] = new manager;
							pc[i]->readall(fin);
							break;
			case Fink	 : 	pc[i] = new fink;
							pc[i]->readall(fin);
							break;
			case Highfink : pc[i] = new highfink;
							pc[i]->readall(fin);
							break;
			default : break;
		}
		i++;
        if (i == n)
            break;
		}
    return i;
}

void DealWith(std::string & filename)
{
// fstream prototype
    std::ofstream fout;
	std::ifstream fin;
// variable prototype
    employee * pc[MAX];	    // prototype a pointer array to employee
// link file with ofstream;
    fin.open(filename.c_str());
	if (!fin.is_open())
	{
		fout.open(filename.c_str());
		
		int cnt = Menu(pc, fout, MAX);
        ShowList(pc, cnt);
	}
	else
	{
		int cnt = Readfile(fin, pc, MAX);   // get the numbers in file
		ShowList(pc, cnt);
        fin.clear();
        fin.close();                        // break link
		fout.open(filename.c_str(), std::ios_base::out|std::ios_base::app);
		int count = Menu(pc + cnt, fout, MAX);
        ShowList(pc, count + cnt);
	}
    fout.clear();
	fout.close();       // break link
}