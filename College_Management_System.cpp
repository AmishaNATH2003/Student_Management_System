#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

class College {
private:
    string Name, RollNo, Subject, Trade, Address;

public:
    College(): Name(" "), RollNo(""), Subject(""), Trade(" "), Address(""){}

    void setName(string name) {
        Name = name;
    }

    void setRollNo(string rollno) {
        RollNo = rollno;
    }

    void setSubject(string subject) {
        Subject = subject;
    }

    void setTrade(string trade) {
        Trade = trade;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getName() {
        return Name;
    }

    string getRollNo() {
        return RollNo;
    }

    string getSubject() {
        return Subject;
    }

    string getTrade() {
        return Trade;
    }

    string getAddress() {
        return Address;
    }
};

void add(College student) {
    string name, rollNo, subject, trade, address;

    cout << "Enter Name of student: ";
    cin >> name;
    student.setName(name);

    cout << "Enter Roll No of student: ";
    cin >> rollNo;
    student.setRollNo(rollNo);

    cout << "Enter Subject of student: ";
    cin >> subject;
    student.setSubject(subject);

    cout << "Enter Trade of student: ";
    cin >> trade;
    student.setTrade(trade);

    cout << "Enter Address of student: ";
    cin >> address;
    student.setAddress(address);

    ofstream out("F:/CollegeManagement.txt", ios::app);
    if(!out) {
        cout << "Error: File can't open" << endl;
    } else {
        out << student.getName() << " : " << student.getRollNo() << " : " << student.getSubject() << " : " << student.getTrade() << " : " << student.getAddress() << endl;
        cout << "Student added Successfully!" << endl;
    }
    out.close();
}

void search() {
    string rollNo;
    cout << "Enter RollNo of Student: ";
    cin >> rollNo;

    ifstream in("F:/CollegeManagement.txt");
    if(!in) {
        cout << "Error: File can't open!" << endl;
        return;
    }

    string line;
    bool found = false;
    while(getline(in, line)) {
        int data = line.find(rollNo);
        if(data != string::npos) {
            cout << line << endl;
            found = true;
            break;  // Exit the loop once the student is found
        }
    }
    if(!found) {
        cout << "Student not found" << endl;
    }
    in.close();
}

void update(College student) {
    string rollNo;
    cout << "Enter RollNo of Student: ";
    cin >> rollNo;

    ifstream infile("F:/CollegeManagement.txt");
    ofstream outfile("F:/CollegeManagement_2nd.txt");
    if(!infile || !outfile) {
        cout << "Error: File can't open!" << endl;
        return;
    }

    string line;
    bool found = false;
    while(getline(infile, line)) {
        int pos = line.find(rollNo);
        if(pos != string::npos) {
            string address;
            cout << "Enter new address: ";
            cin >> address;
            student.setAddress(address);

            int newpos = line.find_last_of(':');
            line.replace(newpos + 2, string::npos, student.getAddress());
        }
        outfile << line << endl;
        found = true;
    }
    if(!found) {
        cout << "Student not found!" << endl;
    }
    outfile.close();
    infile.close();
    remove("F:/CollegeManagement.txt");
    rename("F:/CollegeManagement_2nd.txt", "F:/CollegeManagement.txt");
    cout << "Data updated!" << endl;
}

int main() {
    College student;
    bool exit = false;

    while(!exit) {
        system("cls");
        int val;
        cout << "Welcome to College Management System: " << endl;
        cout << "##################################### " << endl;
        cout << "1. Add Student: " << endl;
        cout << "2. Search Student: " << endl;
        cout << "3. Update Date of Student: " << endl;
        cout << "4. Exit: " << endl;
        cout << "Enter Your Choice: ";
        cin >> val;

        switch(val) {
            case 1:
                system("cls");
                add(student);
                Sleep(2000); // Sleep for 2 seconds
                break;
            case 2:
                system("cls");
                search();
                Sleep(2000);
                break;
            case 3:
                system("cls");
                update(student);
                Sleep(2000);
                break;
            case 4:
                system("cls");
                exit = true;
                cout<<"Good Luck!"<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                Sleep(2000); // Sleep for 2 seconds
                break;
        }
    }

    return 0;
}
