#include "Teacher.h"


Teacher::Teacher() {}


Teacher::Teacher(int _id, string _name, string _pwd) {
	this->emp_id = _id;
	this->emp_name = _name;
	this->emp_pwd = _pwd;
}


void Teacher::operMenu() {
	cout << "Welcome~" << endl;
	cout << "Teacher " << this->emp_name << " log in~" << endl;
	cout << "\t\t*********************************************************\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t|              1. Show all appointments                 |\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t|              2. Review an appointments                |\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t|              0. Sign out                              |\n";
	cout << "\t\t|                                                       |\n";		
	cout << "\t\t*********************************************************\n";
	cout << "Please choose your operation: ";
}


void Teacher::showAllAppointment() {}

void Teacher::reviewAppointments() {}