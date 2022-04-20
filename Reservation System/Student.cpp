#include "Student.h"
#include <fstream>
#include <sstream>


Student::Student() {}


Student::Student(int id, string name, string pwd) {
	//initialize the attributes of student
	this->student_id = id;
	this->student_name = name;
	this->student_pwd = pwd;

	//initialize the attributes of computer room
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);

	ComputerRoom croom;
	//copy computer room info to vector
	while (ifs >> croom.id && ifs >> croom.qty) {
		c_vec.push_back(croom);
	}

	ifs.close();
}


void Student::operMenu() {
	cout << "Welcome~" << endl;
	cout << "Student " << this->student_name << " log in~" << endl;
	cout << "\t\t*********************************************************\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t|              1. Initialize an appointment             |\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t|              2. Show my appointments                  |\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t|              3. Show all appointments                 |\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t|              4. Cancel an appointments                |\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t|              0. Sign out                              |\n";
	cout << "\t\t|                                                       |\n";
	cout << "\t\t*********************************************************\n";
	cout << "Please choose your operation: ";
}


//init an appointment
void Student::initAppointment() {
	cout << "Available time for appointment: Mon --> Fri" << endl;
	cout << "Please enter a date code (1 to 5): " << endl;
	cout << "1. Mon" << endl;
	cout << "2. Tue" << endl;
	cout << "3. Mon" << endl;
	cout << "4. Thu" << endl;
	cout << "5. Fir" << endl;
	int date = 0;
	while (true) {
		cin >> date;
		cin.get();
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "Incorrect input, please enter again~" << endl;
	}

	cout << "Please enter an interval code (1 to 2): " << endl;
	cout << "1. A.M." << endl;
	cout << "2. P.M." << endl;
	int interval = 0;
	while (true) {
		cin >> interval;
		cin.get();
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "Incorrect input, please enter again~" << endl;
	}

	cout << "Please enter a computer room code (1 to " << c_vec.size() << "): " << endl;
	for (int i = 0; i < c_vec.size(); ++i) {
		cout << "The room with id " << c_vec[i].id << " has a capacity of "
			<< c_vec[i].qty << "." << endl;
	}
	int room = 0;
	while (true) {
		cin >> room;
		cin.get();
		if (room >= 1 && room <= c_vec.size()) {
			break;
		}
		cout << "Incorrect input, please enter again~" << endl;
	}
	
	cout << "Appointment initialized successfully~" << endl
		<< "Your appointment is under review now~" << endl;
	
	//append new appointment into Appointment.txt
	ofstream ofs;
	ofs.open(APPOINTMENTS_FILE, ios::app);
	ofs << "Date:" << date << "    "
		<< "Interval:" << interval << "    "
		<< "StudentId:" << this->student_id << "    "
		<< "StudentName:" << this->student_name << "    "
		<< "RoomId:" << room << "    "
		<< "Status:" << 1 << endl;
	ofs.close();
	
	system("pause");
	system("cls");
}

//check out my appointments
void Student::showMyAppointment() {
	Appointments am;
	
	int qty = am.appointments_qty;
	if (!qty) {
		cout << "No appointment recorded~" << endl;
		system("pause");
		system("cls");
		return;
	}

	int id;
	for (int i = 0; i < qty; ++i) {
		stringstream ss(am.appointments_map[i]["StudentId"]);
		ss >> id;
		//Or use atoi(string.c_str()) to get id
		if (id == this->student_id) {
			cout << "Date: Day" << am.appointments_map[i]["Date"] << endl
				<< "Interval: " << 
				(am.appointments_map[i]["Interval"] == "1" ? "Morning" : "Afternoon") << endl
				<< "RoomId: " << am.appointments_map[i]["RoomId"] << endl
				<< "Status: " << 
				(am.appointments_map[i]["Status"] == "1" ? "Under Reviewing~" :
				(am.appointments_map[i]["Status"] == "2" ? "Appointment Done~" :
				(am.appointments_map[i]["Status"] == "3" ? "Appointment Failed~" : 
				(am.appointments_map[i]["Status"] == "0" ? "Appointment Canceled~" :
					"Unknown"))))
				<< endl << endl;
		}
	}
	system("pause");
	system("cls");
}

//check all appointments
void Student::showAllAppointments() {
	Appointments am;

	int qty = am.appointments_qty;
	if (!qty) {
		cout << "No appointments exists~" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < qty; ++i) {
		cout << "No. " << i + 1 << endl;
		cout << "Date: Day" << am.appointments_map[i]["Date"] << endl
			<< "Interval: " <<
			(am.appointments_map[i]["Interval"] == "1" ? "Morning" : "Afternoon") << endl
			<< "StudentId: " << am.appointments_map[i]["StudentId"] << endl
			<< "StudentName: " << am.appointments_map[i]["StudentName"] << endl
			<< "RoomId: " << am.appointments_map[i]["RoomId"] << endl
			<< "Status: " <<
			(am.appointments_map[i]["Status"] == "1" ? "Under Reviewing~" :
			(am.appointments_map[i]["Status"] == "2" ? "Appointment Done~" :
			(am.appointments_map[i]["Status"] == "3" ? "Appointment Failed~" :
			(am.appointments_map[i]["Status"] == "0" ? "Appointment Canceled~" :
			"Unknown")))) << endl << endl;
	}
	system("pause");
	system("cls");
	return;
}

//cancel an appointment
void Student::cancelOneAppointment() {
	Appointments am;

	int qty = am.appointments_qty;
	if (!qty) {
		cout << "No appointment exists~" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << endl
		<< "Only appointments under reviewing or already finished could be canceled," << endl
		<< "Please enter the code of appointments as below~" << endl;

	int idx = 1;	//indicate the code of appointments could be canceled
	vector<int> vec;	//receive the code of appointments could be canceled

	for (int i = 0; i < qty; ++i) {
		auto record = am.appointments_map[i];
		int id = atoi(record["StudentId"].c_str());
		if (id == this->student_id) {
			int status = atoi(record["Status"].c_str());
			if (status == 1 || status == 2) {
				vec.push_back(idx);
				cout << "No. " << idx++ << endl
				<< "Date: day " << record["Date"] << endl
				<< "Interval: " << 
					(am.appointments_map[i]["Interval"] == "1" ? "Morning" : 
					"Afternoon") << endl
				<< "RoomId: " << am.appointments_map[i]["RoomId"] << endl
				<< "Status: " <<
					(am.appointments_map[i]["Status"] == "1" ? "Under Reviewing~" :
					"Appointment Done~") << endl << endl;
			}
		}
	}

	cout << "Please enter the code of appointment you want to cancel(0 for Exit): ";
	
	int select = 0;

	while (true) {
		cin >> select;
		cin.get();
		
		if (select >= 0 && select < vec.size()) {
			if (!select) {
				break;
			}
			else {
				am.appointments_map[vec[select - 1]]["Status"] = "0";
				am.updateAppointment();
				cout << "Appointment you chose canceled successfully~" << endl;
				break;
			}
		}
		cout << "Something wrong with your selection, please select again~" << endl;
	}

	system("pause");
	system("cls");
	return;
}
