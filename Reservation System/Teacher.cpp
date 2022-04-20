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
			(am.appointments_map[i]["Status"] == "2" ? "Accepted~" :
			(am.appointments_map[i]["Status"] == "3" ? "Rejected~" :
			(am.appointments_map[i]["Status"] == "0" ? "Canceled~" :
				"Unknown"))))
			<< endl << endl;
	}
	system("pause");
	system("cls");
}


void Teacher::reviewAppointments() {
	Appointments am;

	int qty = am.appointments_qty;
	if (!qty) {
		cout << "No appointment exists~" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Appointments under reviewing are as below" << endl;

	vector<int> vec;
	int idx = 0;
	for (int i = 0; i < qty; ++i) {
		if (am.appointments_map[i]["Status"] == "1") {
			vec.push_back(i);
			cout << "No." << ++idx << endl;
			cout << "Date: Day" << am.appointments_map[i]["Date"] << endl
				<< "Interval: " <<
				(am.appointments_map[i]["Interval"] == "1" ? "Morning" :
					"Afternoon") << endl
				<< "StudentId: " << am.appointments_map[i]["StudentId"] << endl
				<< "StudentNmae: " << am.appointments_map[i]["StudentName"] << endl
				<< "RoomId: " << am.appointments_map[i]["RoomId"] << endl
				<< "Status: Under Reviewing~" << endl << endl;
		}
	}

	cout << "Please enter the code of appointment you want to review(0 for Exit):";
	
	int code = 0;	//[0, qty == am.appointment_map.size()]
	int ans = 0;	//{1: Accept, 2: Reject}
	while (true) {
		cin >> code;
		cin.get();
		if (code >= 0 && code <= qty) {
			if (!code) {
				break;
			}
			else {
				cout << "Please enter the result of review(0 for Exit):" << endl;
				cout << "1. Accept" << endl << "2. Recect" << endl;
				cin >> ans;
				cin.get();
				if (ans == 1) {
					am.appointments_map[vec[code - 1]]["Status"] = "2";
				}
				else if (ans == 2) {
					am.appointments_map[vec[code - 1]]["Status"] = "3";
				}
				else {
					break;
				}
				am.updateAppointment();
				cout << "Review successfully finished~" << endl;
				break;
			}
		}
		cout << "Incorrect code, please enter again~" << endl;
	}
	system("pause");
	system("cls");
}