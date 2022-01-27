// emp.h -- header file for abstr_emp class and children
#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

const int MAX = 10;     // the number of employees

// function prototype
void ShowMenu();
void ListHeader();  // display the list first line

// enum classkind
enum classkind { Employee, Manager, Fink, Highfink };	// in class header
// class prototype
class employee
{
private:
    std::string fname;      // employee's first name
    std::string lname;      // employee's last name
    std::string job;
protected:
    void Get();             
    void Data() const;
    void Write(std::ofstream & fo) const;
    void Read(std::ifstream & fi);            // read from file
public:
    employee();
    employee(const std::string & fn, const std::string & ln,
             const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream & fo) const;
    virtual void readall(std::ifstream & fi);  
    friend std::ostream &
            operator<<(std::ostream & os, employee & e);
    virtual ~employee();
};

class manager : virtual public employee
{
private:
    int inchargeof;
protected:
    void Get();
    void Data() const;
    void Write(std::ofstream & fo) const;
    void Read(std::ifstream & fi);            // read from file
public:
    manager();
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0);
    manager(const employee & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream & fo) const;
    virtual void readall(std::ifstream & fi);  
};

class fink : virtual public employee
{
private:
    std::string reportsto;      // to whom fink reports
protected:
    void Get();
    void Data() const;
    void Write(std::ofstream & fo) const;
    void Read(std::ifstream & fi);            // read from file
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo);
    fink(const employee & e, const std::string & rpo);
    fink(const fink & f);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream & fo) const;
    virtual void readall(std::ifstream & fi);  
};

class highfink : public manager, public fink
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico);
    highfink(const employee & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream & fo) const;
    virtual void readall(std::ifstream & fi);  
};

// function protype
// choice a object to create and save to filename
int Menu(employee * e[], std::ofstream & fout, int n);
// show the list of employee ar[]
void ShowList(employee *ar[], int n);
// Read employee from file
int Readfile(std::ifstream & fin, employee * pc[], int n);
// dealwith filename
void DealWith(std::string & filename);

#endif