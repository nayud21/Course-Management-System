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
	cout << "\t\t\t\t     || -1. Exit.                                     ||\n";
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
	cout << "\t\t\t\t     || -1. Exit.                                                 ||\n";
	cout << "\t\t\t\t     ||==========================================================||\n";
	cout << "\t\t\t\t                      Enter your choice: ";
}
void Menu_Login() {

}

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
	cout << setw(4) << left << "No "
		<< setw(15) << left << "Student ID "
		<< setw(31) << left << "F & L Name "
		<< setw(8) << left << "Gender"
		<< setw(15) << left << "Date of Birth "
		<< setw(15) << left << "Social ID "
		<< setw(6) << left << "Class" << endl;
	for (int i = 0; i < n; i++) {
		Print_One_Student(S[i]);
	}
}
void Print_One_Student(Student S) {
	cout << setw(4) << left << S.No
		<< setw(15) << left << S.StudentID
		<< setw(20) << left << S.FirstName << " " << setw(10) << left << S.LastName
		<< setw(8) << left << S.Gender
		<< setw(2) << left << S.DateOfBirth.Day <<  "/"<<setw(2) << left << S.DateOfBirth.Month << "/" << setw(9) << left << S.DateOfBirth.Year
		<< setw(15) << left << S.SocialID
		<<setw(6)<<left <<S.Class
		<< endl;
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
	cout << setw(4) << left << "No: " 
		<< setw(15) << left << "Teacher ID: "
		<< setw(30) << left << " F & L Name: " 
		<< setw(8) << left << "Gender " 
		<< setw(15) << left << " SocialID: " 
		<< setw(40) << left << " Fal: " << endl;
	for (int i = 0; i < m; i++) {
		Print_One_Teacher(T[i]);
	}
}
void Print_One_Teacher(Teacher T) {
	cout << setw(4) << left << T.No
		<< setw(15) << left << T.TeacherID
		<< setw(20) << left << T.FirstName << " "<<setw(10)<<left << T.LastName
		<< setw(8)  << left << T.Gender
		<< setw(15) << left << T.SocialID
		<< setw(40) << left << T.Faculty << endl;
}
void Print_ElementTeacher(Teacher* T, int i) {
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
void Input_Account(string& User, string& Pass) {
	cout << "ID of User: ";
	getline(cin, User);
	cout << "Password: ";
	getline(cin, Pass);
}
void Update_Infor_Of_Teacher(Teacher*& T, int m, string ID) {
	Teacher Temp;
	cout<<"Update personal information"<<endl;
	cin.ignore();
	cout << "Input your new personal information:" << endl;
	cout << "ID: ";
	getline(cin, Temp.TeacherID);
	cout << "First name: ";
	getline(cin, Temp.FirstName);
	cout << "Last name: ";
	getline(cin, Temp.LastName);
	cout << "Gender: ";
	getline(cin, Temp.Gender);
	cout << "Faculty: ";
	getline(cin, Temp.Faculty);
	cout << "Social ID: ";
	cin >> Temp.SocialID;
	for (int i = 0; i < m; i++) {
		if (T[i].TeacherID == ID) {
			T[i].TeacherID= Temp.TeacherID;
			T[i].FirstName = Temp.FirstName;
			T[i].LastName = Temp.LastName;
			T[i].Gender = Temp.Gender;
			T[i].Faculty = Temp.Faculty;
			T[i].SocialID = Temp.SocialID;
		}
	}
}
void Update_Infor_Of_Student(Student*& S, int n, string ID) {
	Student Temp;
	cout<<"Update personal information";
	cin.ignore();
	cout << "Input your new personal information." << endl;
	cout << "ID: ";
	getline(cin, Temp.StudentID);
	cout << "First name: ";
	getline(cin, Temp.FirstName);
	cout << "Last name: ";
	getline(cin, Temp.LastName);
	cout << "Gender: ";
	getline(cin, Temp.Gender);
	cout << "Date of birth:\nDay: "; cin >> Temp.DateOfBirth.Day;
	cout << "Month: "; cin >> Temp.DateOfBirth.Month;
	cout << "Year: "; cin >> Temp.DateOfBirth.Year;
	cout << "Social ID : ";
	cin >> Temp.SocialID;
	cin.ignore();
	cout << "Class: ";
	getline(cin, Temp.Class);
	for (int i = 0; i < n; i++) {
		if (S[i].StudentID == ID) {
			S[i].StudentID = Temp.StudentID;
			S[i].FirstName = Temp.FirstName;
			S[i].LastName = Temp.LastName;
			S[i].Gender = Temp.Gender;
			S[i].DateOfBirth.Day = Temp.DateOfBirth.Day;
			S[i].DateOfBirth.Month = Temp.DateOfBirth.Month;
			S[i].DateOfBirth.Year = Temp.DateOfBirth.Year;
			S[i].Class = Temp.Class;
			S[i].SocialID = Temp.SocialID;
		}
	}
}
void Change_Pass_Of_Teacher(Teacher*& T, int m, string ID)
{
	Teacher Temp;
	cin.ignore();
	cout<<"Enter your old password: ";
	getline(cin, Temp.Pass);
	for (int i = 0; i < m; i++)
		if (T[i].TeacherID == ID)
		{
			if (Temp.Pass == T[i].Pass) {
				cout<<"Enter new password: ";
				getline(cin, Temp.Pass);
				T[i].Pass = Temp.Pass;
			}
			else {
				cout << "Your password is wrong.\n";
			}
		}
}

void Change_Pass_Of_Student(Student*& S, int n, string ID)
{
	Student Temp;
	cin.ignore();
	cout<<"Enter your old password: ";
	getline(cin, Temp.Pass);
	for (int i = 0; i < n; i++)
		if (S[i].StudentID == ID)
		{
			if (Temp.Pass == S[i].Pass) {
				cout<<"Enter new password: ";
				getline(cin, Temp.Pass);
				S[i].Pass = Temp.Pass;
			}
			else {
				cout << "Your password is wrong.\n";
			}
		}
}
void Write_File_After_Update_of_Teacher(Teacher* T, int m) {
	ofstream out;
	out.open("Teachers.csv");
	if (!out.is_open()) {
		cout << "Can not open file!" << endl;
		return;
	}
	out << "No" << "," << "Teacher ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Social ID" << "," << "Faculty" << "," << "Password" << endl;
	for (int i = 0; i < m; i++) {
		out << T[i].No << "," << T[i].TeacherID << "," << T[i].FirstName << "," << T[i].LastName << "," << T[i].Gender << "," << T[i].SocialID << "," << T[i].Faculty << "," << T[i].Pass << endl;
	}
	out.close();
}
void Write_File_After_Update_Student(Student* S, int n) {
	ofstream out;
	out.open("Students.csv");
	if (!out.is_open()) {
		cout << "Can not open file" << endl;
		return;
	}
	out << "No" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Date of birth" << "," << "Social ID" << "," << "Class" << "," << "Password" << endl;
	for (int i = 0; i < n; i++) {
		out << S[i].No << "," << S[i].StudentID << "," << S[i].FirstName << "," << S[i].LastName << "," << S[i].Gender << "," << S[i].DateOfBirth.Day << "/" << S[i].DateOfBirth.Month << "/" << S[i].DateOfBirth.Year << "," << S[i].SocialID << "," << S[i].Class << "," << S[i].Pass << endl;
	}
	out.close();
}

int Count_Courses() {
	int cnt = 0;
	ifstream in;
	in.open("course.csv");
	if (!in.is_open()) {
		return 0;
	}
	string temp;
	getline(in, temp);
	while (in) {
		getline(in, temp);
		cnt++;
	}
	in.close();
	return cnt;
}

void Read_File_Courses(Courses*& C, int& t) {
	t = Count_Courses();
	C = new Courses[t];
	ifstream in;
	in.open("course.csv");
	if (!in.is_open()) {
		return;
	}
	int i = 0;
	string temp_s;
	getline(in, temp_s);
	while (in) {
		getline(in, C[i].ID, ',');
		getline(in, C[i].Class_Name, ',');
		getline(in, C[i].Teacher_Name, ',');
		string Temp_Credit;
		getline(in, Temp_Credit, ',');
		C[i].Credits = StringToInteger(Temp_Credit);
		string Temp_Max;
		getline(in, Temp_Max, ',');
		C[i].MaxStudent = StringToInteger(Temp_Max);
		getline(in, C[i].Day_First, ',');
		getline(in, C[i].Session_First, ',');
		getline(in, C[i].Day_Second, ',');
		getline(in, C[i].Session_Second, ',');
		string Temp_DayBegin;
		getline(in, Temp_DayBegin, '/');
		C[i].DayBegin = StringToInteger(Temp_DayBegin);
		string Temp_MonthBegin;
		getline(in, Temp_MonthBegin, ',');
		C[i].MonthBegin = StringToInteger(Temp_MonthBegin);
		string Temp_DayEnd;
		getline(in, Temp_DayEnd, '/');
		C[i].DayEnd = StringToInteger(Temp_DayEnd);
		string Temp_MonthEnd;
		getline(in, Temp_MonthEnd);
		C[i].MonthEnd = StringToInteger(Temp_MonthEnd);
		i++;
	}
	t -= 1;
	in.close();
}

void Print_Courses(Courses* C, int t) {
	for (int i = 0; i < t; i++) {
		cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].Class_Name << ", Course Teacher: " << C[i].Teacher_Name
			<< ", Start: " << C[i].DayBegin << "/" << C[i].MonthBegin << ", End: " << C[i].DayEnd << "/" << C[i].MonthEnd << endl;

	}
}

bool Check_Time_Input(int day, int month) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: {
		if (day > 31 || day < 1)
			return false;
	} break;
	case 4:
	case 6:
	case 9:
	case 11: {
		if (day > 30 || day < 1)
			return false;
	} break;
	case 2: {
		if (day > 29 || day < 1)
			return false;
	} break;
	default: return false;
	}
	return true;
}

bool Check_Date(Courses* C, int i, int day, int month) {
	if (month > C[i].MonthBegin && month < C[i].MonthEnd) {
		return true;
	}
	else {
		if (month == C[i].MonthBegin) {
			if (day >= C[i].DayBegin)
				return true;
			else
				return false;
		}
		if (month == C[i].MonthEnd) {
			if (day <= C[i].DayEnd)
				return true;
			else
				return false;
		}
	}
	return false;
}

bool Check_Date_Student_Courses(Student_Courses* SC, int i, int day, int month) {
	if (month > SC[i].MonthBegin && month < SC[i].MonthEnd) {
		return true;
	}
	else {
		if (month == SC[i].MonthBegin) {
			if (day >= SC[i].DayBegin)
				return true;
			else
				return false;
		}
		if (month == SC[i].MonthEnd) {
			if (day <= SC[i].DayEnd)
				return true;
			else
				return false;
		}
	}
	return false;
}

void Create_School_Year(int& schoolyear) {
	cout << "Input the school year: ";
	cin >> schoolyear;
	cout << "You created new a school year: " << schoolyear << " - " << schoolyear + 1 << endl;
	// tao 1 file csv chua thong tin cua nam hoc, hoc sinh, cua hoc ky moi
	ofstream out;
	out.open("NewSchoolYear.csv");
	if (!out.is_open())
		return;
	out << "School Year" << endl;
	out << schoolyear << "-" << schoolyear + 1 << endl;
	out.close();
}

void Add_1st_Student_To_Class(int schoolYear, Student* S, int n) {
	string New_class;
	cout << "\t List of 1st Student.\n";
	Print_ListStudent(S, n);
	cin.ignore();
	cout << "\t\t************" << endl;
	cout << "Input the name of Class that you add 1st Student to: ";
	getline(cin, New_class);


	ofstream outfile;
	outfile.open("NewSchoolYear.csv");
	if (!outfile.is_open())
		return;
	int no = 1;
	outfile << "No" << "," << "School year" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," <<
		"Gender" << "," << "Date of birth" << "," << "Social ID" << "," << "Class" << "," << endl;
	for (int i = 0; i < n; i++) {
		if (S[i].Class == New_class) {
			outfile << no << "," << schoolYear << "-" << schoolYear + 1 << "," << S[i].StudentID << "," << S[i].FirstName << "," << S[i].LastName << "," << S[i].Gender <<
				"," << S[i].DateOfBirth.Day << "/" << S[i].DateOfBirth.Month << "/" << S[i].DateOfBirth.Year << "," << S[i].SocialID << "," << S[i].Class << endl;
			no++;
		}
	}
	outfile.close();
}

void Create_Course(Courses*& C, int& t) {
	Courses temp;
	cout << "Please, Enter new course's information:" << endl;
	cin.ignore();
	cout << "Course Id: ";
	getline(cin, temp.ID);
	cout << "Course Name: ";
	getline(cin, temp.Class_Name);
	cout << "Teacher Name: ";
	getline(cin, temp.Teacher_Name);
	cout << "Number of Credits: ";
	cin >> temp.Credits;
	cout << "The maximum number of students in the course: ";
	cin >> temp.MaxStudent;
	cin.ignore();
	cout << "Day1 of the week: ";
	getline(cin, temp.Day_First);
	cout << "Session1: ";
	getline(cin, temp.Session_First);
	cout << "Day2 of the week: ";
	getline(cin, temp.Day_Second);
	cout << "Session2: ";
	getline(cin, temp.Session_Second);
	cout << "Start day: ";
	cin >> temp.DayBegin;
	cout << "Start month: ";
	cin >> temp.MonthBegin;
	cout << "End day: ";
	cin >> temp.DayEnd;
	cout << "End month: ";
	cin >> temp.MonthEnd;

	Courses* Cnew = new Courses[t + 1];
	copy(C, C + t, Cnew);
	Cnew[t].ID = temp.ID;
	Cnew[t].Class_Name = temp.Class_Name;
	Cnew[t].Teacher_Name = temp.Teacher_Name;
	Cnew[t].Credits = temp.Credits;
	Cnew[t].MaxStudent = temp.MaxStudent;
	Cnew[t].Day_First = temp.Day_First;
	Cnew[t].Session_First = temp.Session_First;
	Cnew[t].Day_Second = temp.Day_Second;
	Cnew[t].Session_Second = temp.Session_Second;
	Cnew[t].DayBegin = temp.DayBegin;
	Cnew[t].MonthBegin = temp.MonthBegin;
	Cnew[t].DayEnd = temp.DayEnd;
	Cnew[t].MonthEnd = temp.MonthEnd;
	t++;
	delete[]C;
	C = Cnew;
}

void Write_Course_To_File(Courses* C, int t) {
	ofstream outfile;
	outfile.open("course.csv");
	if (!outfile.is_open()) {
		return;
	}
	outfile << "Course id" << "," << "Course name" << "," << "Teacher name" << "," << "Number of credits" << "," << "The maximum number of students in the course" <<
		"," << "Day1 of the week" << "," << "Session1" << "," << "Day2 of the week" << "," << "Session2" << "," << "Start date" << "," << "End date" << endl;
	for (int i = 0; i < t; i++) {
		outfile << C[i].ID << "," << C[i].Class_Name << "," << C[i].Teacher_Name << "," << C[i].Credits << "," << C[i].MaxStudent << "," << C[i].Day_First << "," << C[i].Session_First << "," << C[i].Day_Second << "," <<
			C[i].Session_Second << "," << C[i].DayBegin << "/" << C[i].MonthBegin << "," << C[i].DayEnd << "/" << C[i].MonthEnd << endl;
	}
	outfile.close();
}
// Update courses
void UpdateCourse(Courses*& C, int t) {
	string Courses_ID;
	cin.ignore();
	cout << "Input the Course ID that need to update.";
	getline(cin, Courses_ID);
	int count = 0;
	for (int i = 0; i < t; i++) {
		if (C[i].ID == Courses_ID) {
			count++;
			Courses Temp;
			system("cls");
			cout << "Update Course" << endl;;
			cout << "Input new course's information:" << endl;
			cout << "Course ID: ";
			getline(cin, Temp.ID);
			cout << "Course name: ";
			getline(cin, Temp.Class_Name);
			cout << "Teacher name: ";
			getline(cin, Temp.Teacher_Name);
			cout << "Number of Credits: ";
			cin >> Temp.Credits;
			cout << "The maximum number of students in the course:";
			cin >> Temp.MaxStudent;
			cin.ignore();
			cout << "Day1 of the week:";
			getline(cin, Temp.Day_First);
			cout << "Session1:";
			getline(cin, Temp.Session_First);
			cout << "Day2 of the week:";
			getline(cin, Temp.Day_Second);
			cout << "Session2:";
			getline(cin, Temp.Session_Second);
			cout << "Start day:";
			cin >> Temp.DayBegin;
			cout << "Start month:";
			cin >> Temp.MonthBegin;
			cout << "End day:";
			cin >> Temp.DayEnd;
			cout << "End month:";
			cin >> Temp.MonthEnd;
			C[i].ID = Temp.ID;
			C[i].Class_Name = Temp.Class_Name;
			C[i].Teacher_Name = Temp.Teacher_Name;
			C[i].Credits = Temp.Credits;
			C[i].MaxStudent = Temp.MaxStudent;
			C[i].Day_First = Temp.Day_First;
			C[i].Session_First = Temp.Session_Second;
			C[i].Day_Second = Temp.Day_Second;
			C[i].Session_Second = Temp.Session_Second;
			C[i].DayBegin = Temp.DayBegin;
			C[i].MonthBegin = Temp.MonthBegin;
			C[i].DayEnd = Temp.DayEnd;
			C[i].MonthEnd = Temp.MonthEnd;
		}
	}
	if (count == 0)
		cout << "Course do not exist!" << endl;
}
// delete course
void Delete_Array_Of_Courses(Courses*& C, int& t, int i) {
	for (i; i < t - 1; i++) {
		C[i] = C[i + 1];
	}
	t--;
}
void Delete_Course(Courses*& C, int& t) {
	string Courses_ID;
	cin.ignore();
	cout << "Input the Course's ID that you need to delete: ";
	getline(cin, Courses_ID);
	for (int i = 0; i < t; i++) {
		if (Courses_ID == C[i].ID) {
			char check;
			do {
				cout << "Are you sure you want to permanently delete this Course(y/n)?: ";
				cin >> check;
				if ((int)check == (int)'y') {
					Delete_Array_Of_Courses(C, t, i);
					return;
				}
				else return;
			} while ((check != 'y') && (check != 'n'));
		}
	}
	cout << "Can not find this Course." << endl;
}
void Register_Courses(Courses*& C, int& t)
{
	int day = 0, month = 0, option = 0;
	cout << "\n\n\tEnter Current time to register Course" << endl;
	do {
		cout << "Day: "; cin >> day;
		cout << "Month: "; cin >> month;
	} while (Check_Time_Input(day, month) == false);
	while (true)
	{
		system("cls");
		cout<<"\tCourses Registration"<<endl;
		cout << "\n\t1. View list of courses";
		cout << "\n\t2. Create a new course";
		cout << "\n\t3. Update course's information";
		cout << "\n\t4. Delete a course";
		cout << "\n\t0. Back forward";
		cout << "\n\t**************************************";
		cout << "\n\t Choose the option you wanna do: "; cin >> option;
		while ((option < 0) || (option > 4))
		{
			cout << "The number you enter isn't suitble\nPlease choose it again: "; cin >> option;
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			cout<<"List courses";
			cout << "\t List of courses existing: \n";
			cout << "Current Time: " << day << "/" << month << endl;
			for (int i = 0; i < t; i++) {
				if (Check_Date(C, i, day, month)) {
					cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].Class_Name << ", Time start: " << C[i].DayBegin << "/" << C[i].MonthBegin << ", Time end: " <<
						C[i].DayEnd << "/" << C[i].MonthEnd<< endl;
				}
			}
			system("pause");
		}break;
		case 2:
		{
			system("cls");
			cout<<"List courses"<<endl;
			Create_Course(C, t);
			Write_Course_To_File(C, t);
			system("pause");
		}break;
		case 3:
		{
			system("cls");
			cout<<"Update courses"<<endl;
			UpdateCourse(C, t);
			Write_Course_To_File(C, t);
			system("pause");
		}break;
		case 4:
		{
			system("cls");
			cout << "Delete course" << endl;
			Delete_Course(C, t);
			Write_Course_To_File(C, t);
			system("pause");
		}break;
		case 0:
		{
			return;
		} break;
		}
	}
}

void Write_Register_Student_Default(Courses* C, int t, Student* S, int n, Student_Courses*& SC, int& p) {
	p = n;
	SC = new Student_Courses[p];

	for (int i = 0; i < p; i++) {
		SC[i].No = S[i].No;
		SC[i].StudentID = S[i].StudentID;
		SC[i].FirstName = S[i].FirstName;
		SC[i].LastName = S[i].LastName;
		SC[i].Gender = S[i].Gender;
		SC[i].Class = S[i].Class;


		int j = rand() % t;
		SC[i].CourseID = C[j].ID;
		SC[i].Classname = C[j].Class_Name;
		SC[i].Credits = C[j].Credits;
		SC[i].TeacherName = C[j].Teacher_Name;
		SC[i].Day1 = C[j].Day_First;
		SC[i].Session1 = C[j].Session_First;
		SC[i].Day2 = C[j].Day_Second;
		SC[i].Session2 = C[j].Session_Second;
		SC[i].DayBegin = C[j].DayBegin;
		SC[i].MonthBegin = C[j].MonthBegin;
		SC[i].DayEnd = C[j].DayEnd;
		SC[i].MonthEnd = C[j].MonthEnd;
		SC[i].OtherMark = rand() % 11;
		SC[i].MidtermMark = rand() % 11;
		SC[i].FinalMark = rand() % 11;
		SC[i].TotalMark = (SC[i].OtherMark + SC[i].MidtermMark + 2 * SC[i].FinalMark) / 4;

	}
}


void Write_To_File_After_Update_Student_Courses(Student_Courses* SC, int p) {
	ofstream outfile;
	outfile.open("Stucourses.csv");
	if (!outfile.is_open()) {
		cout << "Can not open file" << endl;
		return;
	}
	outfile << "No" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Class" << "," << "Course ID" << "," << "Course Name" << "," << "Credits" << "," << "Teacher Name" << "," << "day1" << "," << "session1" << "," << "day2" << "," << "session2" << "," << "day start" << "," << "month start" << "," << "day end" << "," << "month end" << "," << "Other mark" << "," << "Midterm mark" << "," << "Final mark" << "," << "Total mark" << endl;
	for (int i = 0; i < p; i++) {
		outfile << SC[i].No << "," << SC[i].StudentID << "," << SC[i].FirstName << "," << SC[i].LastName << "," << SC[i].Gender << "," << SC[i].Class << "," << SC[i].CourseID << "," << SC[i].Classname << "," << SC[i].Credits << "," << SC[i].TeacherName<< "," << SC[i].Day1 << "," << SC[i].Session1 << "," << SC[i].Day2 << "," << SC[i].Session2 << "," << SC[i].DayBegin << "/" << SC[i].MonthBegin << "," << SC[i].DayEnd << "/" << SC[i].MonthEnd << "," << SC[i].OtherMark << "," << SC[i].MidtermMark << "," << SC[i].FinalMark<< "," << SC[i].TotalMark << endl;
	}
	outfile.close();
}


void Register_Student_Courses(Student_Courses*& SC, int& p, Courses* C, int t, Student* S, int n, string ID)
{
	int day = 0, month = 0, option = 0;
	cout << "\n\n\tEnter Current time to register Course" << endl;
	do {
		cout << "Day: "; cin >> day;
		cout << "Month: "; cin >> month;
	} while (Check_Time_Input(day, month) == false);
	while (true)
	{
		system("cls");
		cout<<"\tCourses Registration"<<endl;
		cout << "\n\t1. View list of courses";
		cout << "\n\t2. Register course";
		cout << "\n\t3. List courses you have registered";
		cout << "\n\t4. Delete a course you have registered";
		cout << "\n\t0. Back forward";
		cout << "\n\t**************************************";
		cout << "\n\t Choose the option you wanna do: "; cin >> option;
		while ((option < 0) || (option > 4))
		{
			cout << "The number you enter isn't suitble\nPlease choose it again: "; cin >> option;
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			cout<<"List courses"<<endl;
			cout << "\t List of courses existing: \n";
			cout << "Current Time: " << day << "/" << month << endl;
			for (int i = 0; i < t; i++) {
				if (Check_Date(C, i, day, month)) {
					cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].Class_Name << ", Time start: " << C[i].DayBegin << "/" << C[i].MonthBegin << ", Time end: " <<
						C[i].DayEnd << "/" << C[i].MonthEnd << endl;
				}
			}
			system("pause");
		}break;
		case 2:
		{
			system("cls");
			cout<<"Register course"<<endl;
			cout << "The courses is existing: " << endl;
			for (int i = 0; i < t; i++) {
				if (Check_Date(C, i, day, month)) {
					cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].Class_Name << ", Time start: " << C[i].DayBegin << "/" << C[i].MonthBegin << ", Time end: " <<
						C[i].DayEnd << "/" << C[i].MonthEnd << endl;
				}
			}
			int count = 0;
			for (int i = 0; i < p; i++)
			{
				if (Check_Date_Student_Courses(SC, i, day, month))
					if (SC[i].StudentID == ID) count++;
			}
			if (count >= 5)
				cout << "You can't register course because you have registered 5 courses\n";
			else {
				Add_Student_To_Courses(SC, p, C, t, S, n, ID);
			}
			Write_To_File_After_Update_Student_Courses(SC, p);
			system("pause");
		}break;
		case 3:
		{
			system("cls");
			cout<<"List courses"<<endl;
			int count = 0;
			for (int i = 0; i < p; i++)
			{
				if (Check_Date_Student_Courses(SC, i, day, month))
					if (SC[i].StudentID == ID)
					{
						Print_One_Student_Of_Courses(SC, i);
						count++;
					}
			}
			if (count == 0) cout << "You haven't registered any courses in this semester\n";
			system("pause");
		}break;
		case 4:
		{
			system("cls");
			cout<<"Delete course";
			int count = 0;
			for (int i = 0; i < p; i++)
			{
				if (Check_Date_Student_Courses(SC, i, day, month))
					if (SC[i].StudentID == ID)
					{
						Print_One_Student_Of_Courses(SC, i);
						count++;
					}
			}
			if (count == 0) cout << "You haven't registered any courses in this semester\n";
			else Check_Delete_Student_Of_Courses(SC, p, ID, day, month);
			system("pause");
		}break;
		case 0:
		{
			return;
		} break;
		}
	}
}
void Add_Element_To_Arr(Student_Courses*& SC, int& p, int i, Student_Courses temp) {
	Student_Courses* SCnew = new Student_Courses[p + 1];
	copy(SC, SC + p, SCnew);
	SCnew[p] = SC[p - 1];
	delete[]SC;
	SC = SCnew;
	p++;
	for (int j = p - 2; j > i + 1; j--) {
		SC[j] = SC[j - 1];
	}
	SC[i + 1] = temp;
}
void Add_Student_To_Courses(Student_Courses*& SC, int& p, Courses* C, int t, Student* S, int n, string ID)
{
	int position = 0;
	string temp;
	cout << "Please enter exactly the course ID of the course you wanna register: ";
	cin.ignore();
	getline(cin, temp);
	position = Exist_Course(C, t, temp);
	while (position == -1 || Un_Duplicated(SC, p, C, t, ID, position) == false)
	{
		cout << "The course ID doesn't exist or it has duplicated with your schedule this semester\n";
		cout << "Please enter exactly the course ID of the course you wanna register: ";
		getline(cin, temp);
		position = Exist_Course(C, t, temp);
	}
	for (int i = 0; i < p; i++)
		if (SC[i].StudentID == ID)
		{
			Student_Courses SCtemp;
			SCtemp.No = SC[i].No + 1;
			SCtemp.StudentID = SC[i].StudentID;
			SCtemp.FirstName = SC[i].FirstName;
			SCtemp.LastName = SC[i].LastName;
			SCtemp.Gender = SC[i].Gender;
			SCtemp.Class = SC[i].Class;
			SCtemp.CourseID = C[position].ID;
			SCtemp.Classname = C[position].Class_Name;
			SCtemp.Credits = C[position].Credits;
			SCtemp.TeacherName = C[position].Teacher_Name;
			SCtemp.Day1 = C[position].Day_First;
			SCtemp.Session1 = C[position].Session_First;
			SCtemp.Day2 = C[position].Day_Second;
			SCtemp.Session2 = C[position].Session_Second;
			SCtemp.DayBegin = C[position].DayBegin;
			SCtemp.MonthBegin = C[position].MonthBegin;
			SCtemp.DayEnd = C[position].DayEnd;
			SCtemp.MonthEnd = C[position].MonthEnd;
			SCtemp.OtherMark = 0;
			SCtemp.MidtermMark = 0;
			SCtemp.FinalMark = 0;
			SCtemp.TotalMark = 0;
			Add_Element_To_Arr(SC, p, i, SCtemp);
			break;
		}
}
bool Un_Duplicated(Student_Courses* SC, int p, Courses* C, int t, string ID, int position)
{
	if (position == -1) return false;
	for (int i = 0; i < p; i++) {
		if ((SC[i].StudentID == ID))
		{
			if (SC[i].CourseID == C[position].ID) {
				return false;
			}
			if (SC[i].Day1 == C[position].Day_First) {
				if (SC[i].Session1 == C[position].Session_First)
					return false;
			}
			if (SC[i].Day1 == C[position].Day_Second) {
				if (SC[i].Session1 == C[position].Session_First)
					return false;
			}
			if (SC[i].Day2 == C[position].Day_First) {
				if (SC[i].Session2 == C[position].Session_First)
					return false;
			}
			if (SC[i].Day2 == C[position].Day_Second) {
				if (SC[i].Session2 == C[position].Session_Second)
					return false;
			}
		}
	}
	return true;
}

int Exist_Course(Courses* C, int t, string ID)
{
	for (int i = 0; i < t; i++)
		if (C[i].ID == ID)
			return i;
	return -1;
}


void Delele_Student_Courses(Student_Courses*& SC, int& p, int i)
{
	for (int j = i; i < (p - 2); i++)
	{
		SC[i] = SC[i + 1];
	}
	Student_Courses* SCnew = new Student_Courses[p - 1];
	copy(SC, SC + p - 1, SCnew);
	delete[]SC;
	SC = SCnew;
	p--;
}

void Check_Delete_Student_Of_Courses(Student_Courses*& SC, int& p, string ID, int day, int month)
{
	string temp;
	cin.ignore();
	cout << "Please enter exactly the course ID of the course you wanna cancel: ";
	getline(cin, temp);
	for (int i = 0; i < p; i++)
	{
		if (Check_Date_Student_Courses(SC, i, day, month))
			if ((SC[i].CourseID == temp) && (SC[i].StudentID == ID))
			{
				char check;

				cout << "Are you sure you want to permanently delete this Course(y / n)?: ";
				cin >> check;
				if ((int)check == (int)'y')
				{
					Delele_Student_Courses(SC, p, i);
					return;
				}
				else
					return;
			}
	}
	cout << "The course ID you enter is wrong\n";
}

void View_Score(Student_Courses* SC, int p, int i)
{
	cout << "Course ID : " << SC[i].CourseID << " | Course : " << SC[i].Classname << " | Total Mark: " << SC[i].TotalMark << " | Final Mark: " << SC[i].FinalMark <<
		" | Midterm Mark: " << SC[i].MidtermMark << " | Other Mark: " << SC[i].OtherMark << endl;
}

void Print_Student_Of_Courses(Student_Courses* SC, int p) {
	for (int i = 0; i < p; i++) {
		cout << "Student ID: " << SC[i].StudentID << " | Name: " << SC[i].FirstName << " " << SC[i].LastName << " | Class: " << SC[i].Class << " | Course ID: " << SC[i].CourseID << " | Course: " << SC[i].Classname << " | Semester: " << SC[i].DayBegin<< "/" << SC[i].MonthBegin<< " - " << SC[i].DayEnd<< "/" << SC[i].MonthEnd << endl;
	}
}

// in hoc sinh trong khoa hoc
void Print_One_Student_Of_Courses(Student_Courses* SC, int i) {
	cout << "Student ID: " << SC[i].StudentID << " | Name: " << SC[i].FirstName << " " << SC[i].LastName << " | Class: " << SC[i].Class << " | Course ID: " << SC[i].CourseID << " | Course: " << SC[i].Classname << " | Semester: " << SC[i].DayBegin << "/" << SC[i].MonthBegin << " - " << SC[i].DayEnd << "/" << SC[i].MonthEnd << endl;
}

bool Check_Export(Student_Courses* SC, int p, string temp)
{
	for (int i = 0; i < p; i++)
	{
		if (SC[i].CourseID == temp) return true;
	}
	return false;
}

void Export_Student(Student_Courses* SC, int p) {
	string ID;
	do {
		cout << "Enter a ID Course that you want to export: ";
		cin.ignore();
		getline(cin, ID);
	} while (Check_Export(SC, p, ID) == false);
	ofstream outfile;
	outfile.open(ID + ".csv");
	outfile << "Student ID" << "," << "Name" << "," << "Class" << "," << "Course ID" << "," << "Course Name" << "," << "Date Start" << "," << "Date end" << endl;
	for (int i = 0; i < p; i++) {
		if (ID == SC[i].CourseID) {
			outfile << SC[i].StudentID << "," << SC[i].FirstName << " " << SC[i].LastName << "," << SC[i].Class << "," << SC[i].CourseID << "," << SC[i].Classname << "," << SC[i].DayBegin << "/" << SC[i].MonthBegin << " - " << SC[i].DayEnd << "/" << SC[i].MonthEnd << endl;
		}
	}
	outfile.close();
}

void Enter_Scoreboard_Of_Course(Student_Courses*& SC, int p, int pos, Courses* C, Teacher* T) {
	for (int i = 0; i < p; i++) {
		if (C[pos].ID == SC[i].CourseID) {
			Print_ElementTeacher(T, pos);
			cout << "\t\tEnter Score for student:" << endl;
			Print_Student_Of_Courses(SC, i);
			cout << "Final mark: ";
			cin >> SC[i].FinalMark;
			cout << "Midterm mark: ";
			cin >> SC[i].MidtermMark;
			cout << "Other mark: ";
			cin >> SC[i].OtherMark;
			SC[i].TotalMark = (SC[i].OtherMark + SC[i].MidtermMark + 2 * SC[i].FinalMark) / 4;
			system("cls");
		}
	}
}

void View_ScoreBoard(Student_Courses* SC, int p, int pos, Courses* C) {
	for (int i = 0; i < p; i++) {
		if (C[pos].ID == SC[i].CourseID) {
			cout << "Student ID: " << SC[i].StudentID << " | Name: " << SC[i].FirstName << " " << SC[i].LastName << " | Class: " << SC[i].Class << " | Course ID: "<< SC[i].CourseID << "," << SC[i].Classname << "," << SC[i].DayBegin << "/" << SC[i].MonthBegin << " - " << SC[i].DayEnd << "/" << SC[i].MonthEnd
				<< " | Total Mark: " << SC[i].TotalMark << " | Final Mark: " << SC[i].FinalMark <<
				" | Midterm Mark: " << SC[i].MidtermMark << " | Other Mark: " << SC[i].OtherMark << endl;
		}
	}
}

void Import_ScoreBoard(Student_Courses* SC, int p, int pos, Courses* C) {
	ofstream outfile;
	outfile.open("Score_" + C[pos].ID + ".csv");
	outfile << "Student ID" << "," << "Name" << "," << "Class" << "," << "Course ID" << "," << "Course Name" << "," << "Teacher Name" << "," << "Date Start" << "," << "Date end" << ","
		<< "Total Mark" << "," << "Final Mark" << "," << "Midterm Mark" << "," << "Other Mark" << endl;
	for (int i = 0; i < p; i++) {
		if (C[pos].ID == SC[i].CourseID) {
			outfile << SC[i].StudentID << "," << SC[i].FirstName << " " << SC[i].LastName << "," << SC[i].Class << "," << SC[i].CourseID << "," << SC[i].Class << "," << SC[i].TeacherName << ","
				<< SC[i].DayBegin << "/" << SC[i].MonthBegin << "," << SC[i].DayEnd << "/" << SC[i].MonthEnd << "," << SC[i].TotalMark << "," << SC[i].FinalMark << "," << SC[i].MidtermMark << "," << SC[i].OtherMark << endl;
		}
	}
	outfile.close();
}
void Update_Student_Result(Student_Courses*& SC, int p) {
	string ID;
	cin.ignore();
	cout << "Enter the ID of student that you need to update: ";
	getline(cin, ID);
	for (int i = 0; i < p; i++) {
		if (ID == SC[i].StudentID) {
			cout << "Name: " << SC[i].FirstName << " " << SC[i].LastName << " | ID: " << SC[i].StudentID << endl;
			cout << "Final Mark: ";
			cin >> SC[i].FinalMark;
			cout << "Midterm Mark: ";
			cin >> SC[i].MidtermMark;
			cout << "Other Mark: ";
			cin >> SC[i].OtherMark;
			SC[i].TotalMark = (SC[i].OtherMark + SC[i].MidtermMark + 2 * SC[i].FinalMark) / 4;
		}
	}
}
void Score_Board_Course(Student_Courses* SC, int p) {
	string ID;
	cin.ignore();
	cout << "Enter ID of a course that you want to see it: ";
	getline(cin, ID);
	for (int i = 0; i < p; i++) {
		if (ID == SC[i].CourseID)
		{
			cout << "Student ID: " << SC[i].StudentID << " | Name: " << SC[i].FirstName << " " << SC[i].LastName << " | Class: " << SC[i].Class << " | Course ID: " << SC[i].CourseID << " | Course: " << SC[i].Classname << " | Semester: " << SC[i].DayBegin << "/" << SC[i].MonthBegin << " - " << SC[i].DayEnd << "/" << SC[i].MonthEnd <<
				" | Total Mark: " << SC[i].TotalMark << " | Final Mark: " << SC[i].FinalMark <<
				" | Midterm Mark: " << SC[i].MidtermMark << " | Other Mark: " << SC[i].OtherMark << endl;
		}
	}
}

void Score_Board_Class(Student_Courses* SC, int p) {
	string ID;
	cin.ignore();
	cout << "Enter ID of a class that you want to see it: ";
	getline(cin, ID);
	for (int i = 0; i < p; i++) {
		if (ID == SC[i].Class)
		{
			cout << "Student ID: " << SC[i].StudentID << " | Name: " << SC[i].FirstName << " " << SC[i].LastName << " | Class: " << SC[i].Class << " | Course ID: " << SC[i].CourseID << " | Course: " << SC[i].Classname << " | Semester: " << SC[i].DayBegin << "/" << SC[i].MonthBegin << " - " << SC[i].DayEnd << "/" << SC[i].MonthEnd <<
				" | Total Mark: " << SC[i].TotalMark << " | Final Mark: " << SC[i].FinalMark <<
				" | Midterm Mark: " << SC[i].MidtermMark << " | Other Mark: " << SC[i].OtherMark << endl;
		}
	}
}

void View_Classes(Classes*& Clas, int& k, Student* S, int n)
{
	int count = 0;

	Clas[k - 1].NameClass = S[0].Class; //k=1
	Clas[k - 1].NameClass = 1;
	for (int i = 0; i < n; i++)
		if (S[i].Class != Clas[k].NameClass)
		{
			count = 0;
			for (int j = 0; j < k; j++)
			{
				if (S[i].Class == Clas[j].NameClass)count++;
			}
			if (count == 0)
			{
				Clas[k].NameClass = S[i].Class;
				k++;
			}
		}
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			if (Clas[i].NameClass == S[j].Class) Clas[i].Num++;
}