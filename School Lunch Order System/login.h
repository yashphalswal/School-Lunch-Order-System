#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

bool IsLoggedIn() {
	string username, password, un, pw;
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read("data\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) {

		return true;
	}
	else {

		return false;
	}
}
