#pragma once
#include "Identity.h"
#include "globalFile.h"
#include "Appointments.h"
#include "ComputerRoom.h"
#include <vector>
#include <iostream>

using namespace std;


class Student : public Identity {
public:
	int student_id;
	string student_name;
	string student_pwd;
	vector<ComputerRoom> c_vec;

public:
	Student();

	Student(int studnet_id, string name, string pwd);

	virtual void operMenu();

	//init an appointment
	void initAppointment();

	//check out my appointments
	void showMyAppointment();

	//check all appointments
	void showAllAppointments();

	//cancel an appointment
	void cancelOneAppointment();

};