#include "call_class.h"


//default constructor
call_class::call_class()
{
	size = 5;
	count = 0;

	ifstream in;   //fstream variable
	call_DB = new call_record[size];


	in.open("callstats_data.txt");

	if (in.fail()) {
		cout << "failed to open file " << endl;
	}
	else {
		while (!in.eof()) {


			for (int i = count; i < size; i++) {

				in >> call_DB[i].firstname;
				in >> call_DB[i].lastname;
				in >> call_DB[i].cell_num;
				in >> call_DB[i].relays;
				in >> call_DB[i].call_length;

				process();
				count++;

			}
			if (is_full()) {
				if (count == size) {
					double_size();
				}
			}


		}

	}

	in.close();

}

// copy constructor
call_class::call_class(const call_class & obj) {
	
	size = obj.size;
	count = obj.count;
	call_DB = new call_record[size];
	for (int i = 0; i < count; i++) {
		call_DB[i] = obj.call_DB[i];
	}
}

//boolean function to check if array if empty
bool call_class::is_empty()
{
	return count == 0;
}

// boolean function to check if array is full
bool call_class::is_full()
{
	return count == size;
}

//search function
int call_class::search(const string key)
{
	for (int i = 0; i<count; i++)
	{
		if (call_DB[i].cell_num == key)
		{
			return i;
		}
	}
	return -1;
}

//add function
void call_class::add()
{
	cout << "Please enter first name " << endl;
	cin >> call_DB[count - 1].firstname;
	cout << "please enter last name" << endl;
	cin >> call_DB[count - 1].lastname;
	cout << "please enter cell number " << endl;
	cin >> call_DB[count - 1].cell_num;
	cout << "please enter number of relays" << endl;
	cin >> call_DB[count - 1].relays;
	cout << "please enter call length" << endl;
	cin >> call_DB[count - 1].call_length;

	// doubles size of the array if it is full
	if (count - 1 == size)
	{
		double_size();
	}
	count++;


	//processes the new added information

	if (call_DB[count - 2].relays >= 0 && call_DB[count - 2].relays <= 5) {
		call_DB[count - 2].tax_rate = 0.01;
	}
	else if (call_DB[count - 2].relays >= 6 && call_DB[count - 2].relays <= 11) {
		call_DB[count - 2].tax_rate = 0.03;
	}
	else if (call_DB[count - 2].relays >= 12 && call_DB[count - 2].relays <= 20) {
		call_DB[count - 2].tax_rate = 0.05;
	}
	else if (call_DB[count - 2].relays >= 21 && call_DB[count - 2].relays <= 50) {
		call_DB[count - 2].tax_rate = 0.08;
	}
	else if (call_DB[count - 2].relays > 50) {
		call_DB[count - 2].tax_rate = 0.12;
	}


	// setting net_cost, call_tax, total_cost with the value from each equation
	call_DB[count - 2].net_cost = call_DB[count - 2].relays / 50.0 * 0.4 * call_DB[count - 2].call_length;
	call_DB[count - 2].call_tax = call_DB[count - 2].net_cost * call_DB[count - 2].tax_rate;
	call_DB[count - 2].total_cost = call_DB[count - 2].net_cost + call_DB[count - 2].call_tax;
}

// delete function
call_class & call_class::operator-(const string key)
{

	while (search(key) > -1) {
		int loc = search(key);

		if (loc != -1)
		{
			for (int j = loc; j < count - 1; j++)
			{
				call_DB[j] = call_DB[j + 1];

			}
			count--;
		}
	}

	return *this;
}

//double size function
void call_class::double_size()
{
	size *= 2;
	call_record *temp = new call_record[size];

	for (int i = 0; i<count; i++)
	{
		temp[i] = call_DB[i];
	}

	delete[] call_DB;
	call_DB = temp;
}

// person search function
void call_class::personSearch(const string key) {

	int iD = search(key);

	cout << endl;
	cout << call_DB[iD].firstname << " "
		<< call_DB[iD].lastname << "\t"
		<< call_DB[iD].cell_num << "\t"
		<< call_DB[iD].relays << "\t"
		<< call_DB[iD].call_length << "\t"
		<< call_DB[iD].net_cost << "\t"
		<< call_DB[iD].tax_rate << "\t"
		<< call_DB[iD].call_tax << "\t"
		<< call_DB[iD].total_cost << endl;
}

// processing function
void call_class::process()
{
	// if statement for checking tax_rate.

	if (call_DB[count].relays >= 0 && call_DB[count].relays <= 5) {
		call_DB[count].tax_rate = 0.01;
	}
	else if (call_DB[count].relays >= 6 && call_DB[count].relays <= 11) {
		call_DB[count].tax_rate = 0.03;
	}
	else if (call_DB[count].relays >= 12 && call_DB[count].relays <= 20) {
		call_DB[count].tax_rate = 0.05;
	}
	else if (call_DB[count].relays >= 21 && call_DB[count].relays <= 50) {
		call_DB[count].tax_rate = 0.08;
	}
	else if (call_DB[count].relays > 50) {
		call_DB[count].tax_rate = 0.12;
	}


	// setting net_cost, call_tax, total_cost with the value from each equation
	call_DB[count].net_cost = call_DB[count].relays / 50.0 * 0.4 * call_DB[count].call_length;
	call_DB[count].call_tax = call_DB[count].net_cost * call_DB[count].tax_rate;
	call_DB[count].total_cost = call_DB[count].net_cost + call_DB[count].call_tax;

}

// function overloading to screen
ostream & operator<<(ostream & out, call_class & Org)
{
	
	for (int i = 0; i < Org.count - 1; i++)
	{
		out.setf(ios::fixed);
		out << i << ". " << setw(10) << left << Org.call_DB[i].firstname << "\t"
			<< setw(10) << Org.call_DB[i].lastname << "\t"
			<< Org.call_DB[i].cell_num << "\t"
			<< Org.call_DB[i].relays << "\t"
			<< Org.call_DB[i].call_length << "\t"
			<< setprecision(2) << Org.call_DB[i].net_cost << "\t"
			<< setprecision(2) << Org.call_DB[i].tax_rate << "\t"
			<< setprecision(2) << Org.call_DB[i].call_tax << "\t"
			<< setprecision(2) << Org.call_DB[i].total_cost << endl;
	}
	

	return out; 
}

// deconstructor
call_class::~call_class()
{
	delete[]call_DB;
	call_DB = 0;
}

// creates a text file
void call_class::outFile() {
	ofstream out;
	out.open("weekly_call_info.txt");

	for (int i = 0; i<count - 1; i++)
	{
		out.setf(ios::fixed);
		out << i << ". " << setw(10) << left << call_DB[i].firstname << "\t"
			<< setw(10) << call_DB[i].lastname << "\t"
			<< call_DB[i].cell_num << "\t"
			<< call_DB[i].relays << "\t"
			<< call_DB[i].call_length << "\t"
			<< setprecision(2) << call_DB[i].net_cost << "\t"
			<< setprecision(2) << call_DB[i].tax_rate << "\t"
			<< setprecision(2) << call_DB[i].call_tax << "\t"
			<< setprecision(2) << call_DB[i].total_cost << endl;


	}

	out.close();
}
