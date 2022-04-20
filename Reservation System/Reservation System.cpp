#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
#include "globalFile.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


/*
Interface of Teacher Menu
*/
void teacherMenu(Identity*& _teacher) {
    while (true) {
        //activate the student menu
        _teacher->operMenu();

        //convert the parent class pointer to children class pointer
        Teacher* teacher = (Teacher*)_teacher;

        //receive the specific operation that teacher chose
        int select;
        cin >> select;
        cin.get();
        //1. Show all appointments
        if (select == 1) {
            cout << "Show all appointments" << endl;
            teacher->showAllAppointment();
        }
        //2. Review an appointment
        else if (select == 2) {
            cout << "Review an appointment" << endl;
            teacher->reviewAppointments();
        }
        else {
            delete teacher;
            cout << "Successfully signed out~" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}


/*
Interface of Student Menu
*/
void studentMenu(Identity* &_student) {
    while (true) {
        //activate the student menu
        _student->operMenu();

        //convert the parent class pointer to children class pointer
        Student* student = (Student*)_student;

        //receive the specific operation that student chose
        int select;
        cin >> select;
        cin.get();
        //1. Initialize an appointment
        if (select == 1) {
            cout << "Initialize an appointment" << endl;
            student->initAppointment();
        }
        //2. Show my own appointments
        else if (select == 2) {
            cout << "Show my own appointments" << endl;
            student->showMyAppointment();
        }
        //3. Show all appointments
        else if (select == 3) {
            cout << "Show all appointments" << endl;
            student->showAllAppointments();
        }
        //4. Cancel an appointment
        else if (select == 4) {
            cout << "Cancel an appointment" << endl;
            student->cancelOneAppointment();
        }
        //default: sign out
        else {
            delete student;
            cout << "Successfully signed out~" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}


/*
Interface of Admin Menu
*/
void adminMenu(Identity* &_admin) {
    while (true) {
        //activate the admin menu
        _admin->operMenu();

        //convert the parent class pointer to children class pointer
        Admin* admin = (Admin*)_admin;

        //receive the specific operation that admin chose
        int select = 0;
        cin >> select;
        cin.get();
        //1. create an account
        if (select == 1) {
            //cout << "create an account" << endl;
            admin->createAccount();
        }
        //2. check account info
        else if (select == 2) {
            //cout << "show account info" << endl;
            admin->showAllAccounts();
        }
        //3. check computer room info
        else if (select == 3) {
            //cout << "show computer room info" << endl;
            admin->showComputerRoom();
        }
        //4. clear all appointments
        else if (select == 4) {
            //cout << "clear appointment files" << endl;
            admin->clearAppointments();
        }
        //default: sign out
        else {
            delete admin;
            cout << "Successfully signed out~";
            system("pause");
            system("cls");
            return;
        }
    }
}


/*
loginIn function
1. file_name: the name of file that will operated by user
2. user_type: the identity of user we chose
*/
void loginIn(string file_name, int user_type) {
    //parent class pointer: points to children class object
    Identity* person = nullptr;

    //read file
    ifstream ifs;
    ifs.open(file_name, ios::in);

    //check the file exists or not
    if (!ifs.is_open()) {
        cout << "File doesn't exists~" << endl;
        ifs.close();
        return;
    }

    //receive the user info(id, name, password)
    int id = 0;
    string name = "";
    string pwd = "";

    if (user_type == 1) {   //student
        cout << "Please enter your student id: " << endl;
        cin >> id;
        cin.get();
    }
    else if (user_type == 2) {  //teacher
        cout << "Please enter your employee id: " << endl;
        cin >> id;
        cin.get();
    }
    cout << "Please enter your name: " << endl;
    cin >> name;
    cin.get();
    cout << "Please enter your password: " << endl;
    cin >> pwd;
    cin.get();

    //identitying depending on the received info
    //student identification
    if (user_type == 1) {
        int file_id;
        string file_name;
        string file_pwd;
        while (ifs >> file_id && ifs >> file_name && ifs >> file_pwd) {
            if (file_id == id && file_name == name && file_pwd == pwd) {
                cout << "Student identity was successfully verified~" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                //redirect to student menu
                studentMenu(person);
                return;
            }
        }
    }
    //teacher identification
    else if (user_type == 2) {
        int file_id;
        string file_name;
        string file_pwd;
        while (ifs >> file_id && ifs >> file_name && ifs >> file_pwd) {
            if (file_id == id && file_name == name && file_pwd == pwd) {
                cout << "Teacher identity was successfully verified~" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                //redirect to teacher menu
                teacherMenu(person);
                return;
            }
        }
    }
    //admin identification
    else if (user_type == 3) {
        string file_name;
        string file_pwd;
        while (ifs >> file_name && ifs >> file_pwd) {
            if (file_name == name && file_pwd == pwd) {
                cout << "Admin identity was successfully verified~" << endl;
                system("pause");
                system("cls");
                person = new Admin(name, pwd);
                //redirect to admin menu
                adminMenu(person);
                return;
            }
        }
    }
    cout << "Identity verification failed~" << endl;

    system("pause");
    system("cls");

    return;
}


int main() {

    int select = 0; //store the key user selected

    while (true) {
        cout << endl << "*********************** Welcome to Classroom Reserve System ***********************" << endl;
        cout << endl << "Firstly, choose your identity: " << endl;

        cout << "\t\t*************************************************\n";
        cout << "\t\t|                                               |\n";
        cout << "\t\t|               1. Student                      |\n";
        cout << "\t\t|                                               |\n";
        cout << "\t\t|               2. Teacher                      |\n";
        cout << "\t\t|                                               |\n";
        cout << "\t\t|               3. Administrator                |\n";
        cout << "\t\t|                                               |\n";
        cout << "\t\t|               0. Exit                         |\n";
        cout << "\t\t|                                               |\n";
        cout << "\t\t*************************************************\n";
        cout << endl << "Please enter your key: ";

        cin >> select;
        cin.get();

        //redirect to different interfaces
        switch (select) {
            //Student
        case 1:
            loginIn(STUDENT_FILE, 1);
            break;
            //Teacher
        case 2:
            loginIn(TEACHER_FILE, 2);
            break;
            //Administrator
        case 3:
            loginIn(ADMIN_FILE, 3);
            break;
            //Exit
        case 0:
            cout << endl << "See you next time~" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "There's something wrong with your key, please enter again~" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    system("cls");

    return 0;
}