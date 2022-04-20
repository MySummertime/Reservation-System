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


void Teacher::showAllAppointment() {
	Appointments am;

	int qty = am.appointments_qty;
	if (!qty) {
		cout << "No appointment exists~" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < qty; ++i) {
		cout << "No. " << i + 1 << endl
			<< "Date: Day " << am.appointments_map[i]["Date"] << endl
			<< "Interval: " <<
			(am.appointments_map[i]["Interval"] == "1" ? "Morning" :
				"Afternoon") << endl
			<< "StudentId: " << am.appointments_map[i]["StudentId"] << endl
			<< "StudentName: " << am.appointments_map[i]["StudentName"] << endl
			<< "RoomId: " << am.appointments_map[i]["RoomId"] << endl
			<< "Status: " <<
			(am.appointments_map[i]["Status"] == "1" ? "Under Reviewing~" :
			(am.appointments_map[i]["Status"] == "2" ? "Appointment Done~" :
			(am.appointments_map[i]["Status"] == "3" ? "Appointment Failed~" :
			(am.appointments_map[i]["Status"] == "0" ? "Appointment Canceled~" :
				"Unknown"))))
			<< endl << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::reviewAppointments() {}