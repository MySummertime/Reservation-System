#include "Admin.h"


Admin::Admin() {}


Admin::Admin(string _name, string _pwd) {
	//initialize admin info
	this->admin_name = _name;
	this->admin_pwd = _pwd;
	//initialize vector
	this->initVector();
	this->initComputerRoom();
}


void Admin::operMenu() {
	cout << "Welcome~" << endl;
	cout << "Administrator " << this->admin_name << " log in~" << endl;
	cout << "\t\t****************************************************\n";
	cout << "\t\t|                                                  |\n";
	cout << "\t\t|               1. Create account                  |\n";
	cout << "\t\t|                                                  |\n";
	cout << "\t\t|               2. Show account                    |\n";
	cout << "\t\t|                                                  |\n";
	cout << "\t\t|               3. Show computer room              |\n";
	cout << "\t\t|                                                  |\n";
	cout << "\t\t|               4. Clear all appointment           |\n";
	cout << "\t\t|                                                  |\n";
	cout << "\t\t|               0. Sign out                        |\n";
	cout << "\t\t|                                                  |\n";
	cout << "\t\t****************************************************\n";
	cout << "Please choose your operation: ";
}


void Admin::createAccount() {
	cout << "Please select the type of account you want to create: " << endl;
	cout << "1. Create a student account" << endl;
	cout << "2. Create a teacher account" << endl;

	string file_name;
	string id_tip;	//cue id: student id || teacher id
	string type_tip;	//cue type: student identity || teacher identity

	int select = 0;
	cin >> select;
	//create a student account
	if (select == 1) {
		file_name = STUDENT_FILE;
		id_tip = "Please create a student id: ";
		type_tip = "Duplicate student id, please check another id";
	}
	else if (select == 2) {
		file_name = TEACHER_FILE;
		id_tip = "Please create a teacher id: ";
		type_tip = "Duplicate teacher id, please check another id";
	}

	ofstream ofs;
	ofs.open(file_name, ios::out | ios::app);
	cout << id_tip << endl;

	int id;
	while (true) {
		cin >> id;
		cin.get();
		bool flag = checkDuplicate(id, select);
		//id we want to create is duplicate
		if (flag) {
			cout << type_tip << endl;
		}
		else {
			break;
		}
	}

	string name;
	string pwd;
	cout << "Please create a name: " << endl;
	cin >> name;
	cin.get();
	cout << "Please create a password " << endl;
	cin >> pwd;
	cin.get();

	ofs << id << "    " << name << "    " << pwd << "    " << endl;
	cout << "Create Successfully~";

	system("pause");
	system("cls");

	ofs.close();

	//after create an account, initialize vectors immediately
	this->initVector();
}


void printStudentInfo(Student &s) {
	cout << "Student id: " << s.student_id << ", Student name: " << s.student_name
		<< ", Student password: " << s.student_pwd << endl;
}

void printTeacherInfo(Teacher &t) {
	cout << "Teacher id: " << t.emp_id << ", Teacher name: " << t.emp_name <<
		", Teacher password: " << t.emp_pwd << endl;
}


void Admin::showAllAccounts() {
	cout << "Please choose the type of accounts you want to check~" << endl;
	cout << "1. Student Accounts" << endl;
	cout << "2. Teacher Accounts" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "There are all of the studentsaccounts info:" << endl;
		for_each(s_vec.begin(), s_vec.end(), printStudentInfo);
	}
	else {
		for_each(t_vec.begin(), t_vec.end(), printTeacherInfo);
	}
	system("pause");
	system("cls");
}


void printComputerRoomInfo(ComputerRoom &r) {
	cout << "Computer Room id: " << r.id << ", Computer Room quantity: " << r.qty 
		<< endl;
}

void Admin::showComputerRoom() {
	cout << "The info of Computerroom is as below:" << endl;
	for_each(c_vec.begin(), c_vec.end(), printComputerRoomInfo);
	system("pause");
	system("cls");
}


void Admin::clearAppointments() {
	cout << "Are you sure to clear all appointments?" << endl;
	cout << "1. Sure" << endl << "2. Not exactly" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(APPOINTMENTS_FILE, ios::trunc);
		ofs.close();
	}
	else {
		return;
	}

	cout << "All appointments clear~" << endl;
	system("pause");
	system("cls");
}


/*
* initialize the vector
* get the student info && teacher info from student.txt && teacher.txt
*/
void Admin::initVector() {
	//make sure the vectors are clean
	s_vec.clear();
	t_vec.clear();

	//read student info from student.txt
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "Read operation failed~" << endl;
		return;
	}
	Student s;
	while(ifs >> s.student_id && ifs >> s.student_name && ifs >> s.student_pwd) {
		s_vec.push_back(s);
	}
	cout << "The number of students is: " << s_vec.size() << endl;
	ifs.close();

	//read teacher info from teacher.txt
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "Read operation failed~" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.emp_id && ifs >> t.emp_name && ifs >> t.emp_pwd) {
		t_vec.push_back(t);
	}
	cout << "The number of teachers is: " << t_vec.size() << endl;
	ifs.close();
}


void Admin::initComputerRoom() {
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);

	ComputerRoom croom;
	while (ifs >> croom.id && ifs >> croom.qty) {
		c_vec.push_back(croom);
	}
	ifs.close();
	cout << "The number of Class Room is: " << c_vec.size() << endl;
}


/*
check if there're some duplicates(id) within student.txt || teacher.txt
1. id: student id || teacher id
2. type: student identity || teacher identity
0. if return false, then no duplicates;
	if return true, then exist duplicates;
*/
bool Admin::checkDuplicate(int id, int type) {
	//chose to check vector of student
	if (type == 1) {
		for (Student &i : s_vec) {
			if (id == i.student_id) {
				return true;
			}
		}
	}
	//chose to check vector of teacher
	else {
		for (Teacher &i : t_vec) {
			if (id == i.emp_id) {
				return true;
			}
		}
	}
	return false;
}