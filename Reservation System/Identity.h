#pragma once
#include <string>
#include <iostream>

using namespace std;


//
class Identity {
public:
	string user_name = "";
	string user_pwd = "";

public:
	//A pure virtual function
	virtual void operMenu() = 0;

};