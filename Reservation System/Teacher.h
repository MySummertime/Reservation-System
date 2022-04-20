#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Identity.h"
#include "Appointments.h"
#include <iostream>

using namespace std;


class Teacher : public Identity {
public:
	int emp_id;
	string emp_name;
	string emp_pwd;

public:
	Teacher();

	Teacher(int emp_id, string name, string pwd);

	virtual void operMenu();

	void showAllAppointment();

	void reviewAppointments();

};