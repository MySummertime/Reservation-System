#pragma once
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"
#include "globalFile.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;


class Admin : public Identity {
public:
	string admin_name;
	string admin_pwd;
	vector<Student> s_vec;
	vector<Teacher> t_vec;
	vector<ComputerRoom> c_vec;

public:
	Admin();

	Admin(string _name, string _pwd);

	virtual void operMenu();

	void createAccount();

	void showAllAccounts();

	void showComputerRoom();

	void clearAppointments();

	void initVector();

	void initComputerRoom();

	bool checkDuplicate(int id, int type);
};