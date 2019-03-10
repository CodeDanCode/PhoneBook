#ifndef CALL_CLASS_H_
#define CALL_CLASS_H_

// included libraries
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

// A Class called "call_record"
class call_record
{
public:
	string firstname;
	string lastname;
	string cell_num;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};

// A Class called "call_class"
class call_class
{
public:
	call_class();
	call_class(const call_class &);
	~call_class(); //de-allocates all memory allocate to call_DB by operator new.
	bool is_empty(); //inline implementation
	bool is_full();//inline implementation
	int search(const string key);//returns location if item in listl; otherwise return -1
	void add(); //adds a call record to call_DB
	call_class & operator-(const string key); //removes an item from the list
	void double_size();
	void process();
	void personSearch(const string key); // search database for specific person using cell number.
	friend ostream & operator<<(ostream & out_to_screen, call_class & Org); //prints all the elements in the list to the screen.
	void outFile();
private:
	int count;
	int size;
	call_record *call_DB;
};
#endif // CALL_CLASS_H_