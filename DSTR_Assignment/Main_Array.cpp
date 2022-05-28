#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <ctime>
#include <chrono>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace std::chrono;

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

	Centre* getCentreData() {
		return centres;
	}

	int getLength() {
		return length;
	}

	string convertCentreCode(int centrecode) {
		string name = "";

		for (int i = 0; i < length; i++) {
			if (centres[i].CentreCode == centrecode)
				name = centres[i].Centre_Name;
		}

		return name;
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

	Subject* getSubjectData() {
		return subjects;
	}

	int getLength() {
		return length;
	}

	string convertSubjectCode(int code) {
		string name = "";

		for (int i = 0; i < length; i++) {
			if (subjects[i].SubjectCode == code)
				name = subjects[i].Subject_Name;
		}

		return name;
	}
}subjectdata;

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
	// for the display space
	const int s1 = 11, s2 = 20, s3 = 15, s4 = 15, s5 = 20, s6 = 20, s7 = 10;
	int ts = s1 + s2 + s3 + s4 + s5 + s6 + s7 + 2;
	// display content
	string w1 = "Tutor ID";
	string w2 = "Name";
	string w3 = "Hourly Rate";
	string w4 = "Phone";
	string w5 = "Centre";
	string w6 = "Subject";
	string w7 = "Rating";

	// storing temp data
	Tutors* tempdata;

public:
	TutorsData() {
		int size = 2;
		tutors = new Tutors[size];
		Tutors data[2] = { {1, "James", 1650988800, 0, 100, 01234567, "Jalan Teknologi No. 1", 2, 1, 5, 1},
						{2, "Louis", 1651075200, 0, 200, 07654321, "Jalan Inovasi No. 1", 2, 1, 3.5, 1}
		};

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
			tutors[i].Rating_No = data[i].Rating_No;
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
				newData[i].Rating_No = tutors[i].Rating_No;
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
				newData[i].Rating_No = nd.Rating_No;
			}
		}

		tutors = newData;
		cout << "Add new data success!" << endl;
	}

	// normal display
	void display(int mode) {
		// mode 0: normal display with arranged by tutor name
		// mode 1: display by the sorting data
		int page = 1, start = 0, end = 10, limit = 10, pages = 1;
		const char separator = ' ';
		Tutors* dump = (mode == 1) ? tempdata : tutors;

		if (length > 10) {
			if (length % 10 != 0) {
				pages = length / 10 + 1;
			}
			else {
				pages = length / 10;
			}
		}

		do {
			system("CLS");
			cout << string(ts, '=') << endl;
			cout << "| " << w1 << setw(s1 - w1.length()) << setfill(separator) 
				<< "| " << w2 << setw(s2 - w2.length()) << setfill(separator)
				<< "| " << w3 << setw(s3 - w3.length()) << setfill(separator)
				<< "| " << w4 << setw(s4 - w4.length()) << setfill(separator)
				<< "| " << w5 << setw(s5 - w5.length()) << setfill(separator)
				<< "| " << w6 << setw(s6 - w6.length()) << setfill(separator)
				<< "| " << w7 << setw(s7 - w7.length()) << setfill(separator) << "|" << endl;

			start = limit * page - limit;

			if (pages == 1) {
				end = length % limit;
			}
			else if (page * limit - length > 0) {
				end = length % limit + (page - 1) * limit;
			}
			else {
				end = limit * page;
			}
			
			for (int i = start; i < end; i++) {
				string centreName = centredata.convertCentreCode(dump[i].Centre_Code);
				string subName = subjectdata.convertSubjectCode(dump[i].Subject_Code);
				cout << "| " << dump[i].TutorID << setw(s1 - to_string(dump[i].TutorID).length()) << setfill(separator)
					<< "| " << dump[i].Name << setw(s2 - dump[i].Name.length()) << setfill(separator)
					<< "| " << fixed << setprecision(2) << dump[i].Hourly_Rate
					<< setw(s3 - to_string(dump[i].Hourly_Rate).substr(0, 6).length()) << setfill(separator)
					<< "| " << dump[i].Phone << setw(s4 - to_string(dump[i].Phone).length()) << setfill(separator)
					<< "| " << centreName << setw(s5 - centreName.length()) << setfill(separator)
					<< "| " << subName << setw(s6 - subName.length()) << setfill(separator)
					<< "| " << fixed << setprecision(2) << dump[i].Rating << setw(s7 - to_string(dump[i].Rating).substr(0, 4).length())
					<< setfill(separator) << "|" << endl;
			}

			page = 0;
			if (pages > 1) {
				cout << endl << "Enter the page number (1 ~ " << pages << ", 0 - Exit): ";
				cin >> page;
			}

		} while (page > 0 && page <= pages);

		if (page == 0)
			return;
	}

	// searching display
	void display(Tutors* temp, int len) {
		int page = 1, start = 0, end = 10, limit = 10, pages = 1;
		const char separator = ' ';

		if (len > 10) {
			if (len % 10 != 0) {
				pages = len / 10 + 1;
			}
			else {
				pages = len / 10;
			}
		}

		do {
			cout << string(ts, '=') << endl;
			cout << "| " << w1 << setw(s1 - w1.length()) << setfill(separator)
				<< "| " << w2 << setw(s2 - w2.length()) << setfill(separator)
				<< "| " << w3 << setw(s3 - w3.length()) << setfill(separator)
				<< "| " << w4 << setw(s4 - w4.length()) << setfill(separator)
				<< "| " << w5 << setw(s5 - w5.length()) << setfill(separator)
				<< "| " << w6 << setw(s6 - w6.length()) << setfill(separator)
				<< "| " << w7 << setw(s7 - w7.length()) << setfill(separator) << "|" << endl;

			start = limit * page - limit;

			if (pages == 1) {
				end = len % limit;
			}
			else if (page * limit - len > 0) {
				end = len % limit + (page - 1) * limit;
			}
			else {
				end = limit * page;
			}

			for (int i = start; i < end; i++) {
				string centreName = centredata.convertCentreCode(tutors[i].Centre_Code);
				string subName = subjectdata.convertSubjectCode(tutors[i].Subject_Code);
				cout << "| " << temp[i].TutorID << setw(s1 - to_string(temp[i].TutorID).length()) << setfill(separator)
					<< "| " << temp[i].Name << setw(s2 - temp[i].Name.length()) << setfill(separator)
					<< "| " << fixed << setprecision(2) << temp[i].Hourly_Rate
					<< setw(s3 - to_string(temp[i].Hourly_Rate).substr(0, 6).length()) << setfill(separator)
					<< "| " << temp[i].Phone << setw(s4 - to_string(temp[i].Phone).length()) << setfill(separator)
					<< "| " << centreName << setw(s5 - centreName.length())
					<< setfill(separator)
					<< "| " << subName << setw(s6 - subName.length()) << setfill(separator)
					<< "| " << fixed << setprecision(2) << temp[i].Rating << setw(s7 - to_string(temp[i].Rating).substr(0, 4).length())
					<< setfill(separator) << "|" << endl;
			}

			page = 0;
			if (pages > 1) {
				cout << endl << "Enter the page number (1 ~ " << pages << ", 0 - Exit): ";
				cin >> page;
			}

		} while (page > 0 && page <= pages);

		if (page == 0)
			return;
	}

	void LinearSearch(int mode) {
		auto starttime = high_resolution_clock::now();
		// mode: 1 - search tutor id, 2 - search performance
		Tutors* result = NULL;
		if (mode == 1) {
			int search, j = 0, m = 0;
			cout << "Enter tutor ID: ";
			cin >> search;

			for (int i = 0; i < length; i++) {
				Tutors* newResult;
				if (tutors[i].TutorID == search) {
					j++;
					if (result == NULL) {
						result = new Tutors[j];
						result[m].TutorID = tutors[i].TutorID;
						result[m].Name = tutors[i].Name;
						result[m].Join_Date = tutors[i].Join_Date;
						result[m].Term_Date = tutors[i].Term_Date;
						result[m].Hourly_Rate = tutors[i].Hourly_Rate;
						result[m].Phone = tutors[i].Phone;
						result[m].Address = tutors[i].Address;
						result[m].Centre_Code = tutors[i].Centre_Code;
						result[m].Subject_Code = tutors[i].Subject_Code;
						result[m].Rating = tutors[i].Rating;
						result[m].Rating_No = tutors[i].Rating_No;
					}
					else {
						newResult = new Tutors[j];
						for (int k = 0; k < m; k++) {
							newResult[k].TutorID = result[k].TutorID;
							newResult[k].Name = result[k].Name;
							newResult[k].Join_Date = result[k].Join_Date;
							newResult[k].Term_Date = result[k].Term_Date;
							newResult[k].Hourly_Rate = result[k].Hourly_Rate;
							newResult[k].Phone = result[k].Phone;
							newResult[k].Address = result[k].Address;
							newResult[k].Centre_Code = result[k].Centre_Code;
							newResult[k].Subject_Code = result[k].Subject_Code;
							newResult[k].Rating = result[k].Rating;
							newResult[k].Rating_No = result[k].Rating_No;
						}

						newResult[m].TutorID = tutors[i].TutorID;
						newResult[m].Name = tutors[i].Name;
						newResult[m].Join_Date = tutors[i].Join_Date;
						newResult[m].Term_Date = tutors[i].Term_Date;
						newResult[m].Hourly_Rate = tutors[i].Hourly_Rate;
						newResult[m].Phone = tutors[i].Phone;
						newResult[m].Address = tutors[i].Address;
						newResult[m].Centre_Code = tutors[i].Centre_Code;
						newResult[m].Subject_Code = tutors[i].Subject_Code;
						newResult[m].Rating = tutors[i].Rating;
						newResult[m].Rating_No = tutors[i].Rating_No;

						result = newResult;
					}

					m++;
				}
			}

			system("CLS");
			auto stoptime = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stoptime - starttime);
			cout << "Time Used:" << duration.count() << " microseconds" << endl;

			if (j != 0) {
				display(result, j);
			}
			else {
				cout << "The tutors ID not found!" << endl;
			}
			return;
		}
		else if(mode == 2){
			int  j = 0, m = 0;
			float search;
			cout << "Enter overall performance rate: ";
			cin >> search;

			for (int i = 0; i < length; i++) {
				Tutors* newResult;
				if (tutors[i].Rating == search) {
					j++;
					if (result == NULL) {
						result = new Tutors[j];
						result[m].TutorID = tutors[i].TutorID;
						result[m].Name = tutors[i].Name;
						result[m].Join_Date = tutors[i].Join_Date;
						result[m].Term_Date = tutors[i].Term_Date;
						result[m].Hourly_Rate = tutors[i].Hourly_Rate;
						result[m].Phone = tutors[i].Phone;
						result[m].Address = tutors[i].Address;
						result[m].Centre_Code = tutors[i].Centre_Code;
						result[m].Subject_Code = tutors[i].Subject_Code;
						result[m].Rating = tutors[i].Rating;
						result[m].Rating_No = tutors[i].Rating_No;
					}
					else {
						newResult = new Tutors[j];
						for (int k = 0; k < m; k++) {
							newResult[k].TutorID = result[k].TutorID;
							newResult[k].Name = result[k].Name;
							newResult[k].Join_Date = result[k].Join_Date;
							newResult[k].Term_Date = result[k].Term_Date;
							newResult[k].Hourly_Rate = result[k].Hourly_Rate;
							newResult[k].Phone = result[k].Phone;
							newResult[k].Address = result[k].Address;
							newResult[k].Centre_Code = result[k].Centre_Code;
							newResult[k].Subject_Code = result[k].Subject_Code;
							newResult[k].Rating = result[k].Rating;
							newResult[k].Rating_No = result[k].Rating_No;
						}

						newResult[m].TutorID = tutors[i].TutorID;
						newResult[m].Name = tutors[i].Name;
						newResult[m].Join_Date = tutors[i].Join_Date;
						newResult[m].Term_Date = tutors[i].Term_Date;
						newResult[m].Hourly_Rate = tutors[i].Hourly_Rate;
						newResult[m].Phone = tutors[i].Phone;
						newResult[m].Address = tutors[i].Address;
						newResult[m].Centre_Code = tutors[i].Centre_Code;
						newResult[m].Subject_Code = tutors[i].Subject_Code;
						newResult[m].Rating = tutors[i].Rating;
						newResult[m].Rating_No = tutors[i].Rating_No;

						result = newResult;
					}
					
					m++;
				}
			}

			system("CLS");
			auto stoptime = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stoptime - starttime);
			
			cout << "Time Used:" << duration.count() << " microseconds" << endl;

			if (j != 0) {
				display(result, j);
			}
			else {
				cout << "The overall performance rate not found!" << endl;
			}
			return;
		}
	}

	void BinarySearch(int mode) {
		auto starttime = high_resolution_clock::now();
		// mode: 1 - search tutor id, 2 - search performance
		Tutors* result = NULL;

		if (mode == 1) {
			int search, l = 0, r = length - 1;
			int j = 0, m = 0;
			cout << "Enter tutor ID: ";
			cin >> search;

			while (l <= r) {
				Tutors* newResult;
				int i = l + (r - 1) / 2;

				if (tutors[i].TutorID == search) {
					j++;
					if (result == NULL) {
						result = new Tutors[j];
						result[m].TutorID = tutors[i].TutorID;
						result[m].Name = tutors[i].Name;
						result[m].Join_Date = tutors[i].Join_Date;
						result[m].Term_Date = tutors[i].Term_Date;
						result[m].Hourly_Rate = tutors[i].Hourly_Rate;
						result[m].Phone = tutors[i].Phone;
						result[m].Address = tutors[i].Address;
						result[m].Centre_Code = tutors[i].Centre_Code;
						result[m].Subject_Code = tutors[i].Subject_Code;
						result[m].Rating = tutors[i].Rating;
						result[m].Rating_No = tutors[i].Rating_No;
					}
					else {
						newResult = new Tutors[j];
						for (int k = 0; k < m; k++) {
							newResult[k].TutorID = result[k].TutorID;
							newResult[k].Name = result[k].Name;
							newResult[k].Join_Date = result[k].Join_Date;
							newResult[k].Term_Date = result[k].Term_Date;
							newResult[k].Hourly_Rate = result[k].Hourly_Rate;
							newResult[k].Phone = result[k].Phone;
							newResult[k].Address = result[k].Address;
							newResult[k].Centre_Code = result[k].Centre_Code;
							newResult[k].Subject_Code = result[k].Subject_Code;
							newResult[k].Rating = result[k].Rating;
							newResult[k].Rating_No = result[k].Rating_No;
						}

						newResult[m].TutorID = tutors[i].TutorID;
						newResult[m].Name = tutors[i].Name;
						newResult[m].Join_Date = tutors[i].Join_Date;
						newResult[m].Term_Date = tutors[i].Term_Date;
						newResult[m].Hourly_Rate = tutors[i].Hourly_Rate;
						newResult[m].Phone = tutors[i].Phone;
						newResult[m].Address = tutors[i].Address;
						newResult[m].Centre_Code = tutors[i].Centre_Code;
						newResult[m].Subject_Code = tutors[i].Subject_Code;
						newResult[m].Rating = tutors[i].Rating;
						newResult[m].Rating_No = tutors[i].Rating_No;

						result = newResult;
					}
					m++;
				}

				if (tutors[i].TutorID < search)
					l = i + 1;
				else
					r = i - 1;
			}

			system("CLS");
			auto stoptime = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stoptime - starttime);
			cout << "Time Used:" << duration.count() << " microseconds" << endl;

			if (result != NULL) {
				display(result, j); 
			}
			else {
				cout << "The tutors ID not found!" << endl;
			}
			return;
		}
		else if (mode == 2) {
			float search, l = 0, r = length - 1;
			int j = 0, m = 0;
			cout << "Enter overall performance rate: ";
			cin >> search;

			while (l <= r) {
				Tutors* newResult;
				int i = l + (r - 1) / 2;

				if (tutors[i].Rating == search) {
					j++;
					if (result == NULL) {
						result = new Tutors[j];
						result[m].TutorID = tutors[i].TutorID;
						result[m].Name = tutors[i].Name;
						result[m].Join_Date = tutors[i].Join_Date;
						result[m].Term_Date = tutors[i].Term_Date;
						result[m].Hourly_Rate = tutors[i].Hourly_Rate;
						result[m].Phone = tutors[i].Phone;
						result[m].Address = tutors[i].Address;
						result[m].Centre_Code = tutors[i].Centre_Code;
						result[m].Subject_Code = tutors[i].Subject_Code;
						result[m].Rating = tutors[i].Rating;
						result[m].Rating_No = tutors[i].Rating_No;
					}
					else {
						newResult = new Tutors[j];
						for (int k = 0; k < m; k++) {
							newResult[k].TutorID = result[k].TutorID;
							newResult[k].Name = result[k].Name;
							newResult[k].Join_Date = result[k].Join_Date;
							newResult[k].Term_Date = result[k].Term_Date;
							newResult[k].Hourly_Rate = result[k].Hourly_Rate;
							newResult[k].Phone = result[k].Phone;
							newResult[k].Address = result[k].Address;
							newResult[k].Centre_Code = result[k].Centre_Code;
							newResult[k].Subject_Code = result[k].Subject_Code;
							newResult[k].Rating = result[k].Rating;
							newResult[k].Rating_No = result[k].Rating_No;
						}

						newResult[m].TutorID = tutors[i].TutorID;
						newResult[m].Name = tutors[i].Name;
						newResult[m].Join_Date = tutors[i].Join_Date;
						newResult[m].Term_Date = tutors[i].Term_Date;
						newResult[m].Hourly_Rate = tutors[i].Hourly_Rate;
						newResult[m].Phone = tutors[i].Phone;
						newResult[m].Address = tutors[i].Address;
						newResult[m].Centre_Code = tutors[i].Centre_Code;
						newResult[m].Subject_Code = tutors[i].Subject_Code;
						newResult[m].Rating = tutors[i].Rating;
						newResult[m].Rating_No = tutors[i].Rating_No;

						result = newResult;
					}
					m++;
				}

				if (tutors[i].TutorID < search)
					l = i + 1;
				else
					r = i - 1;
			}

			system("CLS");
			auto stoptime = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stoptime - starttime);
			cout << "Time Used:" << duration.count() << " microseconds" << endl;

			if (result != NULL) {
				display(result, j);
			}
			else {
				cout << "The overall performance rate not found!" << endl;
			}
			return;
		}
	}

	void BubbleSort(int mode) {
		// mode: 0 - sort by tutor name, 1 - sort by tutor id, 2 - sort by hourly rate, 3 - sort by overall performance
		// mode 0 call by add data function and normal display function
		auto starttime = high_resolution_clock::now();
		Tutors* result = NULL;

		if (mode == 0) {

		}
		else if (mode == 1) {

		}
		else if (mode == 2) {

		}
		else if (mode == 3) {

		}
	}

	void InsertionSort(int mode) {

	}

}tutorsdata;

// functions
bool isDateNumber(const string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (i != 4 && i != 7) {
			if (isdigit(str[i]) == 0) return false;
		}
	}
	return true;
}

void MainMenu_HR() {
	system("CLS");
	int choice;
	bool flag = true;
	
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
	cout << " 0. Exit\n" << endl;
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
			do {
				cout << "Enter join date (YYYY-MM-DD): ";
				cin >> date;
				if (date.length() != 10 || !isDateNumber(date) || stoi(date.substr(0, 4)) - 1900 < 0 || 
					!(stoi(date.substr(5, 7)) - 1 >= 0 && stoi(date.substr(5, 7)) - 1 < 12) ||
					!(stoi(date.substr(8, 10)) > 0 && stoi(date.substr(8, 10)) <= 31)) {
					cout << "Invalid format try again!" << endl;
					flag = true;
				}
				else {
					flag = false;
				}
			} while (flag);
			
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
				cout<< endl << "Enter 1 to repeat again 0 to EXIT: ";
				cin >> choice;
			} while (choice < 0 || choice > 1);

			if (choice == 0)
				MainMenu_HR();
		} while (choice == 1);
	}
		break;
	case 2: {
		cout << "Display All Tutor Records\n";
		cout << "----------------------------------------" << endl;
		tutorsdata.display(0);
		do {
			cout << endl << "Enter 0 to main menu: ";
			cin >> choice;
		} while (choice != 0);

		if (choice == 0)
			MainMenu_HR();
	}
		break;
	case 3: {
		int method;
		system("CLS");
		cout << "Search Tutor by Tutor ID\n";
		cout << "----------------------------------------" << endl;
		cout << "What kind of searching method you want to use?" << endl;
		cout << " 1. Linear Search" << endl;
		cout << " 2. Binary Search" << endl;
		do {
			cout << "Enter the method: ";
			cin >> method;
		} while (method != 1 && method != 2);

		if(method == 1)
			tutorsdata.LinearSearch(1);
		else
			tutorsdata.BinarySearch(1);

		do {
			cout << endl << "Enter 0 to main menu: ";
			cin >> choice;
		} while (choice != 0);

		if (choice == 0)
			MainMenu_HR();
	}
		break;
	case 4: {
		int method;
		system("CLS");
		cout << "Search Tutors by Overall Performance\n";
		cout << "----------------------------------------" << endl;
		cout << "What kind of searching method you want to use?" << endl;
		cout << " 1. Linear Search" << endl;
		cout << " 2. Binary Search" << endl;
		do {
			cout << "Enter the method: ";
			cin >> method;
		} while (method != 1 && method != 2);

		if (method == 1)
			tutorsdata.LinearSearch(2);
		else
			tutorsdata.BinarySearch(2);

		do {
			cout << endl << "Enter 0 to main menu: ";
			cin >> choice;
		} while (choice != 0);

		if (choice == 0)
			MainMenu_HR();
	}
		break;
	case 5: {
		cout << "Sort by Tutors ID\n";
		cout << "----------------------------------------" << endl;
		cout << "What kind of sorting method you want to use?" << endl;
		cout << " 1. Bubble Sort" << endl;
		cout << " 2. Insertion Sort" << endl;
		int method;
		do {
			cout << "Enter the method: ";
			cin >> method;
		} while (method != 1 && method != 2);

		if (method == 1)
			tutorsdata.BubbleSort(1);
		else
			tutorsdata.InsertionSort(1);

		do {
			cout << endl << "Enter 0 to main menu: ";
			cin >> choice;
		} while (choice != 0);

		if (choice == 0)
			MainMenu_HR();
	}
		break;
	case 6:
		cout << "Sort by Tutors Hourly Pay Rater\n";
		cout << "----------------------------------------" << endl;
		break;
	case 7:
		cout << "Sort by Tutors Overall Performance\n";
		cout << "----------------------------------------" << endl;
		break;
	case 8:
		cout << "Modify Tutor Record\n";
		cout << "----------------------------------------" << endl;
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