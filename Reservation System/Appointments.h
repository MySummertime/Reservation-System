#pragma once
#include "globalFile.h"
#include "Student.h"
#include <fstream>
#include <unordered_map>

using namespace std;


class Appointments {
public:
	int appointments_qty;
	unordered_map<int, unordered_map<string, string>> apppointments_map;
	
public:
	Appointments();

	void updateAppointment();


};