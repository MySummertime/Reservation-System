#pragma once
#include "Identity.h"
#include <iostream>

using namespace std;


class Student : public Identity {
public:
	int student_id;
	string student_name;
	string student_pwd;

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