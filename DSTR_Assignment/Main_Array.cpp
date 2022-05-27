#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// declare functions
void MainMenu_HR();
void MainMenu_Student();
void MainMenu_Admin();
int RoleConvert(string);
void Login();

// convert date
time_t toTimeStamp(string date) {
	struct tm t;
	time_t t_of_day;

	t.tm_year = stoi(date.substr(0, 4)) - 1900;
	t.tm_mon = stoi(date.substr(5, 7)) - 1;
	t.tm_mday = stoi(date.substr(8, 10));
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = 0;
	t_of_day = mktime(&t);

	return t_of_day;
}

// Struct of object
struct Users {
	int UserID;
	string Username;
	string Password;
	string Role;
	int Centre_Code;
};

struct Tutors {
	int TutorID;
	string Name;
	time_t Join_Date;
	time_t Term_Date;
	float Hourly_Rate;
	int Phone;
	string Address;
	int Centre_Code;
	int Subject_Code;
	float Rating;
	int Rating_No;
};

struct Centre {
	int CentreCode;
	string Centre_Name;
	string Address;
	string Region;
};

struct Subject {
	int SubjectCode;
	string Subject_Name;
};

// Class of objects
class UserData {
	Users* users;
	int length;

public:
	UserData() {
		int size = 3;
		users = new Users[size];
		Users data[3] = { {1, "sawchanghau", "sch123", "STUDENT", 1},
						{2, "taihongyi", "thy123", "ADMIN", 1},
						{3, "lau", "lm123", "HR MANAGER", 0} };

		for (int i = 0; i < size; i++) {
			users[i].UserID = data[i].UserID;
			users[i].Username = data[i].Username;
			users[i].Password = data[i].Password;
			users[i].Role = data[i].Role;
			users[i].Centre_Code = data[i].Centre_Code;
		}

		length = size;
	}

	Users* getUserData() {
		return users;
	}

	int getLength() {
		return length;
	}

	int RoleConvert(string role) {
		int no = 0;
		if (role == "STUDENT" || role == "student")
			no = 1;
		else if (role == "ADMIN" || role == "admin")
			no = 2;
		else if (role == "HR MANAGER" || role == "hr manager" || role == "hr" || role == "HR")
			no = 3;

		return no;
	}

	void addUserData(Users nd) {
		length++;
		Users* newUsers = new Users[length];

		for (int i = 0; i < length; i++) {
			if (i != length) {
				newUsers[i].UserID = users[i].UserID;
				newUsers[i].Username = users[i].Username;
				newUsers[i].Password = users[i].Password;
				newUsers[i].Role = users[i].Role;
				newUsers[i].Centre_Code = users[i].Centre_Code;
			}
			else {
				newUsers[i].UserID = nd.UserID;
				newUsers[i].Username = nd.Username;
				newUsers[i].Password = nd.Password;
				newUsers[i].Role = nd.Role;
				newUsers[i].Centre_Code = nd.Centre_Code;
			}
		}

		users = newUsers;
	}
}usersdata;

class TutorsData {
	Tutors* tutors;
	int length;

public:
	TutorsData() {
		int size = 2;
		tutors = new Tutors[size];
		Tutors data[2] = { {1, "James", 1650988800, 0, 100, 01234567, "Jalan Teknologi No. 1", 2, 1, 0},
						{2, "Louis", 1651075200, 0, 200, 07654321, "Jalan Inovasi No. 1", 2, 1, 0} };

		for (int i = 0; i < size; i++) {
			tutors[i].TutorID = data[i].TutorID;
			tutors[i].Name = data[i].Name;
			tutors[i].Join_Date = data[i].Join_Date;
			tutors[i].Term_Date = data[i].Term_Date;
			tutors[i].Hourly_Rate = data[i].Hourly_Rate;
			tutors[i].Phone = data[i].Phone;
			tutors[i].Address = data[i].Address;
			tutors[i].Centre_Code = data[i].Centre_Code;
			tutors[i].Subject_Code = data[i].Subject_Code;
			tutors[i].Rating = data[i].Rating;
		}
		length = size;
	}

	Tutors* getTutorData() {
		return tutors;
	}

	int getLength() {
		return length;
	}

	void addTutorData(Tutors nd) {
		length++;
		Tutors* newData = new Tutors[length];

		for (int i = 0; i < length; i++) {
			if (i != length - 1) {
				newData[i].TutorID = tutors[i].TutorID;
				newData[i].Name = tutors[i].Name;
				newData[i].Join_Date = tutors[i].Join_Date;
				newData[i].Term_Date = tutors[i].Term_Date;
				newData[i].Hourly_Rate = tutors[i].Hourly_Rate;
				newData[i].Phone = tutors[i].Phone;
				newData[i].Address = tutors[i].Address;
				newData[i].Centre_Code = tutors[i].Centre_Code;
				newData[i].Subject_Code = tutors[i].Subject_Code;
				newData[i].Rating = tutors[i].Rating;
			}
			else {
				newData[i].TutorID = nd.TutorID;
				newData[i].Name = nd.Name;
				newData[i].Join_Date = nd.Join_Date;
				newData[i].Term_Date = nd.Term_Date;
				newData[i].Hourly_Rate = nd.Hourly_Rate;
				newData[i].Phone = nd.Phone;
				newData[i].Address = nd.Address;
				newData[i].Centre_Code = nd.Centre_Code;
				newData[i].Subject_Code = nd.Subject_Code;
				newData[i].Rating = nd.Rating;
			}
		}

		tutors = newData;
		cout << "Add new data success!" << endl;
	}

	string convertCentreCode(int centrecode) {
		string name = "";

		return name;
	}

	void display() {
		system("CLS");
		int page = 1, start = 0, end = 10, limit = 10, pages = 1;
		const char separator = ' ';

		if (length > 10) {
			if (length % 10 != 0) {
				pages = length / 10 + 1;
			}
			else {
				pages = length / 10;
			}
		}

		do {
			cout << "======================================================================================" << endl;
			cout << "| Tutor ID" << setw(5) << "| Name" << setw(20) << "| Hourly Rate" << setw(6) << "| Phone" << setw(12)
				<< "| Centre" << setw(15) << "| Subject" << setw(15) << "| Rating" << setw(7) << "|" << endl;

			start = limit * page - limit;

			if (pages == 1 || page * limit - length != 0) {
				end = length % limit;
			}
			else {
				end = limit * page;
			}
			
			for (int i = start; i < end; i++) {
				cout << "| " << tutors[i].TutorID << setw(5) << setfill(separator)
					<< "| " << tutors[i].Name << setw(20) << setfill(separator)
					<< "| " << tutors[i].Hourly_Rate << setw(6) << setfill(separator)
					<< "| " << tutors[i].Phone << setw(12) << setfill(separator)
					<< "| " << tutors[i].Centre_Code << setw(15) << setfill(separator)
					<< "| " << tutors[i].Subject_Code << setw(15) << setfill(separator)
					<< "| " << tutors[i].Rating << setw(7) << setfill(separator) << "|" << endl;
			}

			if (pages > 1) {
				cout << "Enter the page number (1 ~ " << pages << ", 0 - Exit): ";
				cin >> page;
			}

		} while (page < 0 && page > pages);

		if (page)
			return;
	}
}tutorsdata;

class CentreData {
	Centre* centres;
	int length;

public:
	CentreData() {
		int size = 2;
		centres = new Centre[size];
		Centre data[2] = { {1, "HEAD QUARTER", "Jalan Bukit Bintang No. 1", "WP Kuala Lumpur"},
					{2, "Bukit Jalil", "Jalan Taman Teknologi No. 1", "WP Kuala Lumpur"} };

		for (int i = 0; i < size; i++) {
			centres[i].CentreCode = data[i].CentreCode;
			centres[i].Centre_Name = data[i].Centre_Name;
			centres[i].Address = data[i].Address;
			centres[i].Region = data[i].Region;
		}
		length = size;
	}
}centredata;

class SubjectData {
	Subject* subjects;
	int length;

public:
	SubjectData() {
		int size = 1;
		subjects = new Subject[size];
		Subject data[1] = { 1, "Data Structure" };

		for (int i = 0; i < size; i++) {
			subjects[i].SubjectCode = data[i].SubjectCode;
			subjects[i].Subject_Name = data[i].Subject_Name;
		}
		length = size;
	}
}subjectdata;

// functions
void MainMenu_HR() {
	system("CLS");
	int choice;
	
	cout << "============================================== \n";
	cout << "                     MENU\n";
	cout << "============================================== \n";
	cout << " 1. Add Tutor Record\n";
	cout << " 2. Display All Tutor Records\n";
	cout << " 3. Search Tutor by Tutor ID\n";
	cout << " 4. Search Tutors by Overall Performance\n";
	cout << " 5. Sort by Tutors ID\n";
	cout << " 6. Sort by Tutors Hourly Pay Rater\n";
	cout << " 7. Sort by Tutors Overall Performance\n";
	cout << " 8. Modify Tutor Record\n";
	cout << " 9. Delete Tutor Record\n";
	cout << " 10. Add New User\n";
	cout << " 11. Add New Centre\n";
	cout << " 12. Add New Subject\n";
	cout << " 0. Exit\n";
	do {
		cout << "What function your want to process? ";
		cin >> choice;
	} while (choice < 0 || choice > 12);
	
	switch (choice) {
	case 1: {
		do {
			system("CLS");
			cout << "Add Tutor Record\n";
			cout << "----------------------------------------" <<endl;
			Tutors data;
			string date;
			cout << "Enter tutor ID: ";
			cin >> data.TutorID;
			cout << "Enter tutor name: ";
			cin >> data.Name;
			cout << "Enter join date (YYYY-MM-DD): ";
			cin >> date;
			data.Join_Date = toTimeStamp(date);
			cout << "Enter hourly rate: ";
			cin >> data.Hourly_Rate;
			cout << "Enter phone number: ";
			cin >> data.Phone;
			cout << "Enter address: ";
			cin >> data.Address;
			cout << "Enter centre code: ";
			cin >> data.Centre_Code;
			cout << "Enter subject code: ";
			cin >> data.Subject_Code;

			data.Term_Date = 0;
			data.Rating = 0;
			data.Rating_No = 0;

			tutorsdata.addTutorData(data);
			do {
				cout<< endl << "Enter 1 to repit again 0 to EXIT: ";
				cin >> choice;
			} while (choice < 0 || choice > 1);

			if (choice == 0)
				MainMenu_HR();
		} while (choice == 1);
	}
		break;
	case 2:
		cout << " 2. Display All Tutor Records\n";
		tutorsdata.display();
		do {
			cout << endl << "Enter 0 to go back: ";
			cin >> choice;
		} while (choice != 0);

		if (choice == 0)
			MainMenu_HR();
		break;
	case 3:
		cout << " 3. Search Tutor by Tutor ID\n";
		break;
	case 4:
		cout << " 4. Search Tutors by Overall Performance\n";
		break;
	case 5:
		cout << " 5. Sort by Tutors ID\n";
		
		break;
	case 6:
		cout << " 6. Sort by Tutors Hourly Pay Rater\n";
		
		break;
	case 7:
		cout << " 7. Sort by Tutors Overall Performance\n";
		
		break;
	case 8:
		cout << " 8. Modify Tutor Record\n";
		
		break;
	case 9:
		cout << " 9. Delete Tutor Record\n";
		
		break;
	case 10:
		cout << " 10. Add New User\n";
		
		break;
	case 11:
		cout << " 11. Add New Centre\n";
		
		break;
	case 12:
		cout << " 12. Add New Subject\n";
		break;
	case 0:
		Login();
		break;
	default:
		MainMenu_HR();
		break;
	}
}

void MainMenu_Student() {
	system("CLS");
	int choice;
	cout << "============================================== \n";
	cout << "                     MENU\n";
	cout << "============================================== \n";
	cout << " 1. Rate Tutor\n";
	cout << " 2. View Tutor\n";
	cout << " 0. Exit\n";
	do {
		cout << "What function your want to process? ";
		cin >> choice;
	} while (choice < 0 || choice > 2);

	switch (choice) {
	case 1:
		cout << " 1. Rate Tutor\n";
		break;
	case 2:
		cout << " 2. View Tutor\n";
		break;
	case 0:
		Login();
		break;
	default:
		MainMenu_Student();
		break;
	}
}

void MainMenu_Admin() {
	system("CLS");
	int choice;
	cout << "============================================== \n";
	cout << "                     MENU\n";
	cout << "============================================== \n";
	cout << " 1. View Tutor\n";
	cout << " 2. Generate Report\n";
	cout << " 0. Exit\n";
	do {
		cout << "What function your want to process? ";
		cin >> choice;
	} while (choice < 0 || choice > 2);

	switch (choice) {
	case 1:
		cout << " 1. View Tutor\n";
		break;
	case 2:
		cout << " 2. Generate Report\n";
		break;
	case 0:
		Login();
		break;
	default:
		MainMenu_Admin();
		break;
	}
}

void Login() {
	string username, password;
	int role = 0;
	Users* users = usersdata.getUserData();

	system("CLS");
	cout << "WELCOME TO EXCEL TUITION CENTRE MANAGEMEMT SYSTEM\n";
	cout << "--------------------------------------------------\n";
	cout << "                      Login\n";
	cout << "--------------------------------------------------\n";
	
	do {
		cout << "Enter Username (Input '0' to Exit): ";
		cin >> username;
		if (username == "0")
			exit(0);

		cin.ignore();
		cout << "Enter Password: ";
		cin >> password;

		for (int i = 0; i < usersdata.getLength(); i++) {
			if (username == users[i].Username) {
				if (password == users[i].Password) {
					role = usersdata.RoleConvert(users[i].Role);
				}
			}
		}

		if (role == 0)
			cout << "Your Username or Password is incorrect.\n";
	} while (role == 0);

	switch (role) {
	case 1:
		MainMenu_Student();
		break;
	case 2:
		MainMenu_Admin();
		break;
	case 3:
		MainMenu_HR();
		break;
	default:
		Login();
		break;
	}
}

int main() {
	
	//Login();
	MainMenu_HR();

	return 0;
}