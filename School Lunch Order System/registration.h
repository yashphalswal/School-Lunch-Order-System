#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Parent {
    string fullName;
    string gender;
    string dob;
    string contactNo;
    string childName;
    int roomNo;
    string visaCardNo;
    string expiryDate;
};

struct Staff {
    string fullName;
    string gender;
    string dob;
    string visaCardNo;
    string expiryDate;
};

struct Order {
    int orderNumber;
    string orderDate;
    string itemName;
    string size;
    double price;
    string childName;
    int classroomNo;
    string paymentStatus;
    string issuedStatus;
    string dietaryPref;
};

struct Complaint {
    int complaintNumber;
    string fullName;
    string orderDate;
    string itemOrdered;
    string description;
    string contactNo;
    string email;
    string actionStatus;
};

void readDataFromFile(vector<Parent>& parents, vector<Staff>& staffs) {
    ifstream parentFile("parents.txt");
    ifstream staffFile("staffs.txt");

    if (parentFile.is_open()) {
        string line;
        while (getline(parentFile, line)) {
            stringstream ss(line);
            Parent parent;
            getline(ss, parent.fullName, ',');
            ss >> parent.gender >> parent.dob >> parent.contactNo >> parent.childName >> parent.roomNo >> parent.visaCardNo >> parent.expiryDate;
            parents.push_back(parent);
        }
        parentFile.close();
    }

    if (staffFile.is_open()) {
        string line;
        while (getline(staffFile, line)) {
            stringstream ss(line);
            Staff staff;
            getline(ss, staff.fullName, ',');
            ss >> staff.gender >> staff.dob >> staff.visaCardNo >> staff.expiryDate;
            staffs.push_back(staff);
        }
        staffFile.close();
    }
}

void writeDataToFile(const vector<Parent>& parents, const vector<Staff>& staffs) {
    ofstream parentFile("parents.txt");
    ofstream staffFile("staffs.txt");

    for (const auto& parent : parents) {
        parentFile << parent.fullName << "," << parent.gender << " " << parent.dob << " " << parent.contactNo << " "
            << parent.childName << " " << parent.roomNo << " " << parent.visaCardNo << " " << parent.expiryDate << endl;
    }
    parentFile.close();

    for (const auto& staff : staffs) {
        staffFile << staff.fullName << "," << staff.gender << " " << staff.dob << " " << staff.visaCardNo << " " << staff.expiryDate << endl;
    }
    staffFile.close();
}



void parentRegistration() {
    vector<Parent> parents;
    Parent parent;
    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, parent.fullName);
    cout << "Enter Gender (M/F): ";
    cin >> parent.gender;
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    cin >> parent.dob;
    cout << "Enter Contact Number: ";
    cin >> parent.contactNo;
    cout << "Enter Child's Name: ";
    cin.ignore();
    getline(cin, parent.childName);
    cout << "Enter Room Number: ";
    cin >> parent.roomNo;
    cout << "Enter Visa Card Number: ";
    cin >> parent.visaCardNo;
    cout << "Enter Visa Card Expiry Date (MM/YY): ";
    cin >> parent.expiryDate;

    parents.push_back(parent);

    cout << "Parent registration successful!" << endl;
    writeDataToFile(parents, {});

}

void staffRegistration(vector<Staff>& staffs) {
    Staff staff;
    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, staff.fullName);
    cout << "Enter Gender (M/F): ";
    cin >> staff.gender;
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    cin >> staff.dob;
    cout << "Enter Visa Card Number: ";
    cin >> staff.visaCardNo;
    cout << "Enter Visa Card Expiry Date (MM/YY): ";
    cin >> staff.expiryDate;

    staffs.push_back(staff);

    cout << "Staff registration successful!" << endl;
    writeDataToFile({}, staffs);
}









