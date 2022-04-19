#include "Appointments.h"


Appointments::Appointments() {
	string date;	//date of appointment(Mon to Fri)
	string interval;	//interval of appointment(A.M. or P.M)
	string stu_id;	//student id of initiator
	string stu_name;	//student name of initiator
	string room_id;	//room id of appointment
	string status;	//status of appointment

	//initialize the size of map: representing the quantity of all appointments
	this->appointments_qty = 0;

	ifstream ifs;
	ifs.open(APPOINTMENTS_FILE, ios::in);
	while (ifs >> date && ifs >> interval && ifs >> stu_id && ifs >> stu_name
		&& ifs >> room_id && ifs >> status) {
		/*
		cout << date << ", " << interval << ", " << stu_id << ", "
			<< stu_name << ", " << room_id << ", " << status << endl << endl;
		*/
		string key;
		string val;
		unordered_map<string, string> m;
		//1.serialize date
		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			val = date.substr(pos + 1, date.length() - pos - 1);
			m.insert(make_pair(key, val));
			//cout << key << ": " << val << endl;
		}
		//2. serialize interval
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			val = interval.substr(pos + 1, interval.length() - pos - 1);
			m.insert(make_pair(key, val));
			//cout << key << ": " << val << endl;
		}
		//3. serialize stu_id
		pos = stu_id.find(":");
		if (pos != -1) {
			key = stu_id.substr(0, pos);
			val = stu_id.substr(pos + 1, stu_id.length() - pos - 1);
			m.insert(make_pair(key, val));
			//cout << key << ": " << val << endl;
		}
		//4. serialize stu_name
		pos = stu_name.find(":");
		if (pos != -1) {
			key = stu_name.substr(0, pos);
			val = stu_name.substr(pos + 1, stu_name.length() - pos - 1);
			m.insert(make_pair(key, val));
			//cout << key << ": " << val << endl;
		}
		//5. serialize room_id
		pos = room_id.find(":");
		if (pos != -1) {
			key = room_id.substr(0, pos);
			val = room_id.substr(pos + 1, room_id.length() - pos - 1);
			m.insert(make_pair(key, val));
			//cout << key << ": " << val << endl;
		}
		//6. serialize status
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			val = status.substr(pos + 1, status.length() - pos - 1);
			m.insert(make_pair(key, val));
			//cout << key << ": " << val << endl;
		}
		this->apppointments_map.insert(make_pair(this->appointments_qty, m));
		++this->appointments_qty;
	}
	ifs.close();
	
	for (auto &i : this->apppointments_map) {
		cout << "No." << i.first << endl;
		for (auto& j : i.second) {
			cout << "key: " << j.first << ", value: " << j.second << endl;
		}
		cout << endl;
	}
}

void Appointments::updateAppointment() {
	int qty = this->appointments_qty;

	//no appointment exists
	if (qty == 0) {
		return;
	}

	//appointments exist
	ofstream ofs(APPOINTMENTS_FILE, ios::out | ios::trunc);
	for (int i = 0; i < qty; ++i) {
		for (auto& j : this->apppointments_map[i]) {
			ofs << j.first << ":" << j.second << endl;
		}
	}
	ofs.close();
}