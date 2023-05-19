#include"Header.h"
void Login() {
	int count;
	string userId, password, id, pass;
	system("cls");
	cout << "LOGIN\n";
	cout << "Username: ";
	cin >> userId;
	cout << "Password: ";
	cin >> password;
	fstream input;
	input.open("records.txt");
	while (input >> id >> pass) {
		if (id == userId && pass == password) {
			count = 1;
			system("cls");
		}
	}
	 }
void ReadDate(ifstream &filein,Date &date) {
	filein >> date.Day;
	filein.seekg(1, 1);//dich sang phai 1 byte
	filein >> date.Month;
	filein.seekg(1, 1);//dich sang phai 1 byte
	filein >> date.Year;
}
//void ReadSinhvien(ifstream &filein, Student &sv) {
//	getline(filein, sv.Name, ',');
//	//filein.seekg(1, 1);
//	getline(filein, sv.StudentID, ',');
//	//filein.seekg(1, 1);
//	ReadDate(filein, sv.ngaysinh);
//}
//void Output(Student sv) {
//	cout << "\nHo ten: " << sv.Name;
//	cout << "\nMSSV: " << sv.StudentID;
//	cout << "\nNgay sinh: " << sv.ngaysinh.Day << "/" << sv.ngaysinh.Month << "/" << sv.ngaysinh.Year<<endl;
//}
void Registration() {

}
void ForgotPassword() {

}
void Menu_Student() {
	cout << "\t\t\t\t     ||==================MENU OF STUDENT=============||\n";
	cout << "\t\t\t\t     ||==============================================||\n";
	cout << "\t\t\t\t     || 1. Change the password.                      ||\n";
	cout << "\t\t\t\t     || 2. Update your profile info.                 ||\n";
	cout << "\t\t\t\t     || 3. View your profile infor.                  ||\n";
	cout << "\t\t\t\t     || 4. Register for the course.                  ||\n";
	cout << "\t\t\t\t     || 5. View your schedule.                       ||\n";
	cout << "\t\t\t\t     || 6. View your scoreboard.                     ||\n";
	cout << "\t\t\t\t     || 7. View your scoreboard.                     ||\n";
	cout << "\t\t\t\t     || 8. View your scoreboard.                     ||\n";
	cout << "\t\t\t\t     || 9. View list of students in a class.         ||\n";
	cout << "\t\t\t\t     || 0. Log out.                                  ||\n";
	cout << "\t\t\t\t     || 1. Exit.                                     ||\n";
	cout << "\t\t\t\t     ||==============================================||\n";
	cout << "\t\t\t\t                   Enter your choice: ";
}
void Menu_Staff() {
	cout << "\t\t\t\t     ||=======================MENU OF STAFF======================||\n";
	cout << "\t\t\t\t     ||==========================================================||\n";
	cout << "\t\t\t\t     || 1. Change the password.                                  ||\n";
	cout << "\t\t\t\t     || 2. Update your profile info.                             ||\n";
	cout << "\t\t\t\t     || 3. View your profile infor.                              ||\n";
	cout << "\t\t\t\t     || 4. Creat a school year.                                  ||\n";
	cout << "\t\t\t\t     || 5. Add new 1st year students to 1st-year classes.        ||\n";
	cout << "\t\t\t\t     || 6. Create a course registration session.                 ||\n";
	cout << "\t\t\t\t     || 7. Export list of students in a course.                  ||\n";
	cout << "\t\t\t\t     || 8. Enter and view the scoreboard of a course.            ||\n";
	cout << "\t\t\t\t     || 9. View the scoreboard of a course.                      ||\n";
	cout << "\t\t\t\t     || 10. Import the scoreboard of a course.                   ||\n";
	cout << "\t\t\t\t     || 11. Update a student result.                             ||\n";
	cout << "\t\t\t\t     || 12. View the scoreboard of a class.                      ||\n";
	cout << "\t\t\t\t     || 13. View the scoreboard of a course.                     ||\n";
	cout << "\t\t\t\t     || 0. Log out.                                              ||\n";
	cout << "\t\t\t\t     || 1. Exit.                                                 ||\n";
	cout << "\t\t\t\t     ||==========================================================||\n";
	cout << "\t\t\t\t                      Enter your choice: ";
}
void Menu_Login() {

}
//
int CountStudent() {
	int count = 0;
	ifstream infile;
	infile.open("Students.csv");
	if (!infile.is_open()) {
		return 0;
	}
	string line;
	getline(infile, line);
	while (infile) {
		getline(infile, line);
		count++;
	}
	infile.close();
	return count;
}
int StringToInteger(string s) {
	int n = s.length();
	int res = 0;
	for (int i = 0; i < n; i++) {
		switch (s[n - 1 - i]) {
		case '0': res += 0 * pow(10, i); break;
		case '1': res += 1 * pow(10, i); break;
		case '2': res += 2 * pow(10, i); break;
		case '3': res += 3 * pow(10, i); break;
		case '4': res += 4 * pow(10, i); break;
		case '5': res += 5 * pow(10, i); break;
		case '6': res += 6 * pow(10, i); break;
		case '7': res += 7 * pow(10, i); break;
		case '8': res += 8 * pow(10, i); break;
		case '9': res += 9 * pow(10, i); break;
		}
	}
	return res;
}
void ReadStudent(Student*& S, int& n) {
	S = new Student[CountStudent()];
	ifstream file("Students.csv");
	if (!file.is_open()) {
		cout << "Cannot open file." << endl;
		return;
	}
	string line;
	string SNo;
	string SSocialID;
	string SDate;
	string day;
	string month;
	string year;
	int i = 0;
	getline(file, line);
	while (file) {
		getline(file, SNo, ',');
		getline(file, S[i].StudentID, ',');
		getline(file, S[i].FirstName, ',');
		getline(file, S[i].LastName, ',');
		getline(file, S[i].Gender, ',');
		getline(file, day, '/');
		getline(file, month, '/');
		getline(file, year, ',');
		getline(file, SSocialID, ',');
		getline(file, S[i].Class, ',');
		getline(file, S[i].Pass);

		S[i].No = StringToInteger(SNo);
		S[i].DateOfBirth.Day = StringToInteger(day);
		S[i].DateOfBirth.Month = StringToInteger(month);
		S[i].DateOfBirth.Year = StringToInteger(year);
		S[i].SocialID = StringToInteger(SSocialID);
		i++;
	}
	n = i - 1;
	file.close();
}
void Print_ListStudent(Student* S, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Student." << endl;
		cout << "No: " << S[i].No << endl;
		cout << "Student ID: " << S[i].StudentID << ". F & L Name: " << S[i].FirstName << " " << S[i].LastName << endl;
		cout << "Gender: " << S[i].Gender << ". Date of Birth: " << S[i].DateOfBirth.Day << "/" << S[i].DateOfBirth.Month << "/" << S[i].DateOfBirth.Year << endl;
		cout << "Social ID: " << S[i].SocialID << ". Class: " << S[i].Class << endl;
	}
}
void Print_ElementStudent(Student* S, int i) {
	cout << "No: " << S[i].No << endl;
	cout << "StudentID: " << S[i].StudentID << ". F & L Name: " << S[i].FirstName << " " << S[i].LastName << endl;
	cout << "Gender: " << S[i].Gender << ". Date of Birth: " << S[i].DateOfBirth.Day << "/" << S[i].DateOfBirth.Month << "/" << S[i].DateOfBirth.Year << endl;
	cout << "Social ID: " << S[i].SocialID << ". Class: " << S[i].Class << endl;
}

int CountTeacher() {
	int count = 0;
	ifstream infile;
	infile.open("Teachers.csv");
	if (!infile.is_open()) {
		return 0;
	}
	string line;
	getline(infile, line);
	while (infile) {
		getline(infile, line);
		count++;
	}
	infile.close();
	return count;
}
void Read_Teacher(Teacher*& T, int& n) {
	T = new Teacher[CountTeacher()];
	ifstream file("Teachers.csv");
	if (!file.is_open()) {
		cout << "Cannot open file." << endl;
		return;
	}
	string line;
	string SNo;
	string SSocialID;
	int i = 0;
	getline(file, line);
	while (file) {
		getline(file, SNo, ',');
		getline(file, T[i].TeacherID, ',');
		getline(file, T[i].FirstName, ',');
		getline(file, T[i].LastName, ',');
		getline(file, T[i].Gender, ',');
		getline(file, SSocialID, ',');
		getline(file, T[i].Faculty, ',');
		getline(file, T[i].Pass);

		T[i].No = StringToInteger(SNo);
		T[i].SocialID = StringToInteger(SSocialID);
		i++;
	}
	n = i - 1;
	file.close();
}
void Print_ListTeacher(Teacher* T, int m) {
	for (int i = 0; i < m; i++) {
		cout << "Teacher." << endl;
		cout << "No: " << T[i].No << endl;
		cout << "Teacher ID: " << T[i].TeacherID << ". F & L Name: " << T[i].FirstName << " " << T[i].LastName << endl;
		cout << "Gender: " << T[i].Gender << ". SocialID: " << T[i].SocialID << ". Fal: " << T[i].Faculty << endl;
	}
}
void Print_ElementTeacher(Teacher* T, int i) {
	cout << "Teacher." << endl;
	cout << "No: " << T[i].No << endl;
	cout << "Teacher: " << T[i].TeacherID << ". F & L Name: " << T[i].FirstName << " " << T[i].LastName << endl;
	cout << "Gender: " << T[i].Gender << ". Social ID: " << T[i].SocialID << ". Fal: " << T[i].Faculty << endl;
}


bool CheckPass_Student(Student* S, int n, int& Pos, string User, string Pass) {
	for (int i = 0; i < n; i++) {
		Pos = i;
		if (S[i].StudentID == User && S[i].Pass == Pass)
			return 1;
	}
	return 0;
}
bool CheckPass_Teacher(Teacher* T, int m, int& Pos, string User, string Pass) {
	for (int i = 0; i < m; i++) {
		Pos = i;
		if (T[i].TeacherID == User && T[i].Pass == Pass)
			return 1;
	}
	return 0;
}
void Paint(int x, int y, string a, int color) {
	Gotoxy(x, y);
	Color(color);
	cout << a;
}
void Color(int i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void Gotoxy(int x, int y) {
	HANDLE color;
	color = GetStdHandle;
	COORD coor = { x,y };
	SetConsoleCursorPosition(color, coor);
}
void Input_Account(string& User, string& Pass) {
	Paint(15, 20, "ID of User: ", 10);
	getline(cin, User);
	Paint(15, 20, "Password: ", 10);
	getline(cin, Pass);
}