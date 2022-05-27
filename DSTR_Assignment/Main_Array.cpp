#include <iostream>
#include <iomanip>
using namespace std;

// declare functions
void MainMenu_HR();
void MainMenu_Student();
void MainMenu_Admin();
int RoleConvert(string);
void Login();

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

// Declare data
class UserData {
	Users* users;
	int length;

public:
	UserData() {
		int size = 3;
		users = new Users[size];
		Users data[3] = { {1, "sawchanghau", "sch123", "STUDENT", 1},
						{2, "taihongyi", "thy123", "ADMIN", 1},
						{3, "laurentiusmichael", "lm123", "HR MANAGER", 0} };

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

	/*void addUserData(Users nd) {
		length++;
		Users* newUsers = new Users[length];

		for (int i = 0; i < length - 1; i++) {
			newUsers[i].UserID = users[i].UserID;
			newUsers[i].Username = users[i].Username;
			newUsers[i].Password = users[i].Password;
			newUsers[i].Role = users[i].Role;
			newUsers[i].Centre_Code = users[i].Centre_Code;
		}

		newUsers[length] = nd;
	}*/
};

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
		}
		length = size;
	}


Centre centre[2] = { {1, "HEAD QUARTER", "Jalan Bukit Bintang No. 1", "WP Kuala Lumpur"},
					{2, "Bukit Jalil", "Jalan Taman Teknologi No. 1", "WP Kuala Lumpur"} };

Subject subject[1] = { 1, "Data Structure" };
};


void MainMenu_HR() {
	system("CLS");
	cout << "============================================== \n";
	cout << "                     MENU\n";
	cout << "============================================== \n";
	cout << " 1. Add Tutor Record\n";
	cout << " 2. Display All Tutor Record\n";
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
}

void MainMenu_Student() {
	system("CLS");
	cout << "============================================== \n";
	cout << "                     MENU\n";
	cout << "============================================== \n";
	cout << " 1. Rate Tutor\n";
	cout << " 2. View Tutor\n";
	cout << " 0. Exit\n";
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
	cout << "What function your want to process? ";
	cin >> choice;

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

void Login() {
	string username, password;
	int role = 0;
	UserData usersdata;
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
					role = RoleConvert(users[i].Role);
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
	
	Login();

	return 0;
}