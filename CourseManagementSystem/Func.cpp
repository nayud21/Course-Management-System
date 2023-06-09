#include"Header.h"
void Menu_Student() {
	cout << "\t\t\t\t     ||==================MENU OF STUDENT==================||\n";
	cout << "\t\t\t\t     ||===================================================||\n";
	cout << "\t\t\t\t     || 1. Change the password.                           ||\n";
	cout << "\t\t\t\t     || 2. Update your profile info.                      ||\n";
	cout << "\t\t\t\t     || 3. Register for the course.                       ||\n";
	cout << "\t\t\t\t     || 4. View your schedule.                            ||\n";
	cout << "\t\t\t\t     || 5. View your scoreboard.                          ||\n";
	cout << "\t\t\t\t     || 6. View list of students in a course.             ||\n";
	cout << "\t\t\t\t     || 7. View of classes.                               ||\n";
	cout << "\t\t\t\t     || 8. View list of students in a class.              ||\n";
	cout << "\t\t\t\t     || 0. Log out.                                       ||\n";
	cout << "\t\t\t\t     || -1. Exit.                                         ||\n";
	cout << "\t\t\t\t     ||===================================================||\n";
	cout << endl;
}
void Menu_Staff() {
	cout << "\t\t\t\t     ||=======================MENU OF STAFF======================||\n";
	cout << "\t\t\t\t     ||==========================================================||\n";
	cout << "\t\t\t\t     || 1. Change the password.                                  ||\n";
	cout << "\t\t\t\t     || 2. Update your profile info.                             ||\n";
	cout << "\t\t\t\t     || 3. Creat a school year.                                  ||\n";
	cout << "\t\t\t\t     || 4. Add new 1st year students to 1st-year classes.        ||\n";
	cout << "\t\t\t\t     || 5. Create a course registration session.                 ||\n";
	cout << "\t\t\t\t     || 6. Export list of students in a course.                  ||\n";
	cout << "\t\t\t\t     || 7. Enter and view the scoreboard of a course.            ||\n";
	cout << "\t\t\t\t     || 8. View the scoreboard of a course.                      ||\n";
	cout << "\t\t\t\t     || 9. Import the scoreboard of a course.                    ||\n";
	cout << "\t\t\t\t     || 10. Update a student result.                             ||\n";
	cout << "\t\t\t\t     || 11. View the scoreboard of a class.                      ||\n";
	cout << "\t\t\t\t     || 12. View the scoreboard of a course.                     ||\n";
	cout << "\t\t\t\t     || 0. Log out.                                              ||\n";
	cout << "\t\t\t\t     || -1. Exit.                                                ||\n";
	cout << "\t\t\t\t     ||==========================================================||\n";
	cout << endl;
}
int Count_Student() {
	int count = 0;
	ifstream infile;
	infile.open("Student.csv");
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
int Count_Element(string s) {
	int count = 0;
	ifstream infile;
	infile.open(s+".csv");
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
int StringToInteger(string temp) {
	int n = temp.length();
	int result = 0;
	for (int i = 0; i < n; i++) {
		switch (temp[n - 1 - i]) {
		case '0': result += 0 * pow(10, i); break;
		case '1': result += 1 * pow(10, i); break;
		case '2': result += 2 * pow(10, i); break;
		case '3': result += 3 * pow(10, i); break;
		case '4': result += 4 * pow(10, i); break;
		case '5': result += 5 * pow(10, i); break;
		case '6': result += 6 * pow(10, i); break;
		case '7': result += 7 * pow(10, i); break;
		case '8': result += 8 * pow(10, i); break;
		case '9': result += 9 * pow(10, i); break;
		}
	}
	return result;
}
void ReadStudent(Student*& S, int& number_of_student) {
	S = new Student[Count_Student()];
	ifstream file("Student.csv");
	if (!file.is_open()) {
		cout << "Cann't open file!" << endl;
		return;
	}
	string temp_line;
	string temp_No;
	string temp_SocialID;
	string temp_day;
	string temp_month;
	string temp_year;
	int temp = 0;
	getline(file, temp_line);
	while (file) {
		getline(file, temp_No, ',');
		getline(file, S[temp].StudentID, ',');
		getline(file, S[temp].FirstName, ',');
		getline(file, S[temp].LastName, ',');
		getline(file, S[temp].Gender, ',');
		getline(file, temp_day, '/');
		getline(file, temp_month, '/');
		getline(file, temp_year, ',');
		getline(file, temp_SocialID, ',');
		getline(file, S[temp].Class, ',');
		getline(file, S[temp].Pass);
		S[temp].No = StringToInteger(temp_No);
		S[temp].DateOfBirth.Day = StringToInteger(temp_day);
		S[temp].DateOfBirth.Month = StringToInteger(temp_month);
		S[temp].DateOfBirth.Year = StringToInteger(temp_year);
		S[temp].SocialID = StringToInteger(temp_SocialID);
		temp++;
	}
	number_of_student = temp - 1;
	file.close();
}
void Print_ListStudent(Student* S, int number_of_student) {
	cout << setw(4)  << left << "No "
		 << setw(15) << left << "Student ID "
		 << setw(31) << left << "First & Last Name "
		 << setw(8)  << left << "Gender"
		 << setw(15) << left << "Date of Birth "
		 << setw(15) << left << "Social ID "
		 << setw(6)  << left << "Class" << endl;
	for (int i = 0; i < number_of_student; i++) {
		Print_One_Student(S[i]);
	}
}
void Print_One_Student(Student S) {
	cout << setw(4)  << left << S.No
		 << setw(15) << left << S.StudentID
		 << setw(20) << left << S.LastName << " " << setw(10) << left << S.FirstName
		 << setw(8)  << left << S.Gender
		 << setw(2)  << left << S.DateOfBirth.Day <<  "/"<<setw(2) << left << S.DateOfBirth.Month << "/" << setw(9) << left << S.DateOfBirth.Year
		 << setw(15) << left << S.SocialID
		 << setw(6)  << left << S.Class
		 << endl;
}
void Print_ElementStudent(Student* student, int position) {
	cout << setw(4)  << left << "No "
		 << setw(15) << left << "Student ID "
		 << setw(31) << left << "F & L Name "
		 << setw(8)  << left << "Gender"
		 << setw(15) << left << "Date of Birth "
		 << setw(15) << left << "Social ID "
		 << setw(6)  << left << "Class" << endl;
	cout << setw(4) << left << student[position].No
		<< setw(15) << left << student[position].StudentID
		<< setw(20) << left << student[position].LastName << " " << setw(10) << left << student[position].FirstName
		<< setw(8) << left << student[position].Gender
		<< setw(2) << left << student[position].DateOfBirth.Day << "/" << setw(2) << left << student[position].DateOfBirth.Month << "/" << setw(9) << left << student[position].DateOfBirth.Year
		<< setw(15) << left << student[position].SocialID
		<< setw(6) << left << student[position].Class
		<< endl;
	/*cout << "No: " << student[position].No << endl;
	cout << "StudentID: " << student[position].StudentID << ". F & L Name: " << student[position].LastName << " " << student[position].FirstName << endl;
	cout << "Gender: " << student[position].Gender << ". Date of Birth: " << student[position].DateOfBirth.Day << "/" << student[position].DateOfBirth.Month << "/" << student[position].DateOfBirth.Year << endl;
	cout << "Social ID: " << student[position].SocialID << ". Class: " << student[position].Class << endl;*/
}
int Count_Teacher() {
	int count = 0;
	ifstream infile;
	infile.open("Teacher.csv");
	if (!infile.is_open()) {
		cout << "Cann't open file!\n";
		return 0;
	}
	string temp_line;
	getline(infile, temp_line);
	while (infile) {
		getline(infile, temp_line);
		count++;
	}
	infile.close();
	return count;
}
void Read_Teacher(Teacher*& teacher, int& number_of_teacher) {
	teacher = new Teacher[Count_Teacher()];
	ifstream file("Teacher.csv");
	if (!file.is_open()) {
		cout << "Cannot open file." << endl;
		return;
	}
	string temp_line;
	string temp_No;
	string temp_SocialID;
	int temp = 0;
	getline(file, temp_line);
	while (file) {
		getline(file, temp_No, ',');
		getline(file, teacher[temp].TeacherID, ',');
		getline(file, teacher[temp].LastName, ',');
		getline(file, teacher[temp].FirstName, ',');
		getline(file, teacher[temp].Gender, ',');
		getline(file, temp_SocialID, ',');
		getline(file, teacher[temp].Faculty, ',');
		getline(file, teacher[temp].Pass);

		teacher[temp].No = StringToInteger(temp_No);
		teacher[temp].SocialID = StringToInteger(temp_SocialID);
		temp++;
	}
	number_of_teacher = temp - 1;
	file.close();
}
void Print_ListTeacher(Teacher* teacher, int number_of_teacher) {
	cout << setw(4)  << left << "No: " 
		 << setw(15) << left << "Teacher ID: "
		 << setw(30) << left << "F & L Name: " 
		 << setw(8)  << left << "Gender " 
		 << setw(15) << left << "SocialID: " 
		 << setw(40) << left << "Fal: " << endl;
	for (int i = 0; i < number_of_teacher; i++) {
		Print_One_Teacher(teacher[i]);
	}
}
void Print_One_Teacher(Teacher teacher) {
	cout << setw(4)  << left << "No: "
		 << setw(15) << left << "Teacher ID: "
		 << setw(30) << left << "F & L Name: "
		 << setw(8)  << left << "Gender "
		 << setw(15) << left << "SocialID: "
		 << setw(40) << left << "Fal: " << endl;
	cout << setw(4)  << left << teacher.No
		 << setw(15) << left << teacher.TeacherID
		 << setw(20) << left << teacher.LastName << " "
		 << setw(10) << left << teacher.FirstName
		 << setw(8)  << left << teacher.Gender
		 << setw(15) << left << teacher.SocialID
		 << setw(40) << left << teacher.Faculty << endl;
}
void Personal_Infor_Student(Student S) {
	cout << "************************************************\n";
	cout << "*               YOUR INFORMATION               *\n";
	cout << "" << setw(2)  << left << "* No"         << setw(12) << right << ":" << " " << setw(30) << left << S.No << "*" << endl;
	cout << "" << setw(10) << left << "* Student ID" << setw(4)  << right << ":" << " " << setw(30) << left << S.StudentID << "*" << endl
		 << "" << setw(9)  << left << "* Last Name"  << setw(5)  << right << ":" << " " << setw(30) << left << S.LastName << "*" << endl
		 << "" << setw(10) << left << "* First Name" << setw(4)  << right << ":" << " " << setw(30) << left << S.FirstName << "*" << endl;
	cout << "" << setw(6)  << left << "* Gender"     << setw(8)  << right << ":" << " " << setw(30) << left << S.Gender << "*" << endl
		 << "" << setw(14) << left << "* Date of Birth:" << setw(3) << right << S.DateOfBirth.Day << "/" << setw(2) << left << S.DateOfBirth.Month << "/" << setw(24) << left << S.DateOfBirth.Year << "*" << endl
		 << "" << setw(9)  << left << "* Social ID"  << setw(5)  << right << ":" << " " << setw(30) << left << S.SocialID << "*" << endl
		 << "" << setw(5)  << left << "* Class"      << setw(9)  << right << ":" << " " << setw(30) << left << S.Class << "*" << endl;
	cout << "************************************************\n";
}
void Personal_Infor_Teacher(Teacher T) {
	cout << "************************************************\n";
	cout << "*               YOUR INFORMATION               *\n";
	cout <<"" << setw(2)  << left << "* No"         <<setw(12)<<right<<':'<<' '<<setw(30)<<left << T.No       <<'*' << endl;
	cout <<"" << setw(10) << left << "* Teacher ID" <<setw(4) <<right<<':'<<' '<<setw(30)<<left << T.TeacherID<<'*' << endl
		 <<"" << setw(9)  << left << "* Last Name"  <<setw(5) <<right<<':'<<' '<<setw(30)<<left << T.LastName <<'*' << endl;
	cout<< "" << setw(10) << left << "* First Name" <<setw(4) <<right<<':'<<' '<<setw(30)<<left << T.FirstName<<'*' << endl;
	cout <<"" << setw(6)  << left << "* Gender"     <<setw(8) <<right<<':'<<' '<<setw(30)<<left << T.Gender   <<'*' << endl
		 <<"" << setw(9)  << left << "* Social ID"  <<setw(5) <<right<<':'<<' '<<setw(30)<<left << T.SocialID <<'*' << endl
		 <<"" << setw(8)  << left << "* Faculty"    <<setw(7) <<right<<':'<<' '<<setw(30)<<left << T.Faculty  <<'*' << endl;
	cout << "************************************************\n";
}
void Print_ElementTeacher(Teacher* T, int i) {
	cout << "No: " << T[i].No << endl;
	cout << "Teacher: " << T[i].TeacherID << ". F & L Name: " << T[i].LastName << " " << T[i].FirstName << endl;
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
	cout << "\t\t\t\t\t***********_LOGIN_************\n";
	cout << "\t\t\t\t\t    ID User : ";
	getline(cin, User);
	cout << "\t\t\t\t\t    Password: ";
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
			T[i].TeacherID = Temp.TeacherID;
			T[i].FirstName = Temp.FirstName;
			T[i].LastName  = Temp.LastName;
			T[i].Gender    = Temp.Gender;
			T[i].Faculty   = Temp.Faculty;
			T[i].SocialID  = Temp.SocialID;
		}
	}
}
void Update_Infor_Of_Student(Student*& S, int n, string ID) {
	Student Temp;
	cout<<"Update personal information"<<endl;
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
	cout<<"\nEnter your old password: ";
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
	cout<<"\nEnter your old password: ";
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
	ofstream fileout;
	fileout.open("Teacher.csv");
	if (!fileout.is_open()) {
		cout << "can not open file!" << endl;
		return;
	}
	fileout << "No" << "," << "Teacher ID" << "," << "First Name" << "," << "Last Name"
		<< "," << "Gender" << "," << "Social ID" << "," << "Faculty" << "," << "Password" << endl;
	for (int i = 0; i < m; i++) {
		fileout << T[i].No << "," << T[i].TeacherID << "," << T[i].FirstName << "," 
			<< T[i].LastName << "," << T[i].Gender << "," << T[i].SocialID << "," << T[i].Faculty << "," << T[i].Pass << endl;
	}
	fileout.close();
}
void Write_File_After_Update_Student(Student* S, int n) {
	ofstream out;
	out.open("Student.csv");
	if (!out.is_open()) {
		cout << "Can not open file" << endl;
		return;
	}
	out << "No" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," 
		<< "Gender" << "," << "Date of birth" << "," << "Social ID" << "," << "Class" << "," << "Password" << endl;
	for (int i = 0; i < n; i++) {
		out << S[i].No << "," << S[i].StudentID << "," << S[i].FirstName << "," << S[i].LastName << "," 
			<< S[i].Gender << "," << S[i].DateOfBirth.Day << "/" << S[i].DateOfBirth.Month << "/" 
			<< S[i].DateOfBirth.Year << "," << S[i].SocialID << "," << S[i].Class << "," << S[i].Pass << endl;
	}
	out.close();
}
int Count_Courses() {
	int cnt = 0;
	ifstream in;
	in.open("Course.csv");
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
	in.open("Course.csv");
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
		C[i].MonthEnd = StringToInteger(Temp_MonthEnd)/10;
		i++;
	}
	t -= 1;
	in.close();
}
void Print_Courses(Courses* C, int t) {
	cout << setw(13) << left << "Course ID" << setw(30) << left << "Course Name" << setw(18) << left << "Course Teacher" << setw(10) << left << "Day Begin" << setw(10) << "Day End" << endl;
	for (int i = 0; i < t; i++) {
		cout<< setw(13) << left << C[i].ID << setw(30) << left << C[i].Class_Name 
			<< setw(18) << left << C[i].Teacher_Name 
			<< setw(2) << left << C[i].DayBegin << "/" << setw(7) << left << C[i].MonthBegin 
			<< setw(2)<<left << C[i].DayEnd<<"/"<<setw(7)<<left<<C[i].MonthEnd << endl;

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
	ofstream out;
	out.open("NewStudent.csv");
	if (!out.is_open())
		return;
	out << "School Year" << endl;
	out << schoolyear << "-" << schoolyear + 1 << endl;
	out.close();
}
void get_infor_student(Student& student,string s) {
	cout << "No:";
	cin >> student.No;
	cin.ignore();
	cout << "Student ID: ";
	getline(cin,student.StudentID);
	cout << "First Name: ";
	getline(cin, student.FirstName);
	cout << "Last Name: ";
	getline(cin, student.LastName);
	cout << "Gender: ";
	getline(cin, student.Gender);
	cout << "Date Of Birth :";
	cin >> student.DateOfBirth.Day >> student.DateOfBirth.Month >> student.DateOfBirth.Year;
	cout << "Social ID: ";
	cin >> student.SocialID;
	student.Class = s;
	cout << "Pass: ";
	cin >> student.Pass;
}
void Add_1st_Student_To_Class(int schoolYear, Student* S, int n) {
	string New_class;
	cout << "\t List of 1st Student.\n";
	cin.ignore();
	cout << "\t\t************" << endl;
	cout << "Input the name of Class that you add 1st Student to: ";
	getline(cin, New_class);
	cout << "Are you have a file of 1st student?(y/n): ";
	string temp;
	getline(cin, temp);
	Student* s;
	if (temp == "n") {
		cout << "Number of 1st student: ";
		int number;
		cin >> number;
		s = new Student[number];
		for (int i = 0; i < number; i++) {
			get_infor_student(s[i],New_class);
		}
		ofstream outfile;
		outfile.open("NewStudent.csv");
		if (!outfile.is_open())
			return;
		int no = 1;
		outfile << "No" << "," << "School year" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," <<
			"Gender" << "," << "Date of birth" << "," << "Social ID" << "," << "Class" << "," << endl;
		for (int i = 0; i < number; i++) {
				outfile << no << "," << schoolYear << "-" << schoolYear + 1 << "," << s[i].StudentID << "," << s[i].FirstName << "," << s[i].LastName << "," << s[i].Gender <<
					"," << s[i].DateOfBirth.Day << "/" << s[i].DateOfBirth.Month << "/" << s[i].DateOfBirth.Year << "," << s[i].SocialID << "," << s[i].Class << endl;
				no++;
		}
	}
	else {
		cout << "Enter name file of 1st year student: ";
		string temp;
		getline(cin, temp);
		ifstream infile;
		infile.open(temp+".csv");
		Student* s;
		int number_student = 0;
		s = new Student[Count_Element(temp)];
		if (!infile.is_open()) {
			cout << "Cann't open file!" << endl;
			return;
		}
		string temp_line;
		string temp_No;
		string temp_SocialID;
		string temp_day;
		string temp_month;
		string temp_year;
		int temp_count = 0;
		getline(infile, temp_line);
		while (infile) {
			getline(infile, temp_No, ',');
			getline(infile, s[temp_count].StudentID, ',');
			getline(infile, s[temp_count].FirstName, ',');
			getline(infile, s[temp_count].LastName, ',');
			getline(infile, s[temp_count].Gender, ',');
			getline(infile, temp_day, '/');
			getline(infile, temp_month, '/');
			getline(infile, temp_year, ',');
			getline(infile, temp_SocialID, ',');
			s[temp_count].Class = New_class;
			getline(infile, s[temp_count].Pass);
			s[temp_count].No = StringToInteger(temp_No);
			s[temp_count].DateOfBirth.Day = StringToInteger(temp_day);
			s[temp_count].DateOfBirth.Month = StringToInteger(temp_month);
			s[temp_count].DateOfBirth.Year = StringToInteger(temp_year);
			s[temp_count].SocialID = StringToInteger(temp_SocialID);
			temp_count++;
		}
		number_student = temp_count - 1;
		infile.close();
		Print_ListStudent(s, number_student);
		int new_number = number_student + n;
		Student* new_student = new Student[new_number];
		for (int i = 0; i < number_student; i++) {
			new_student[i].No = i + 1;
			new_student[i].StudentID = s[i].StudentID;
			new_student[i].FirstName = s[i].FirstName;
			new_student[i].LastName = s[i].LastName;
			new_student[i].Gender = s[i].Gender;
			new_student[i].DateOfBirth.Day = s[i].DateOfBirth.Day;
			new_student[i].DateOfBirth.Month = s[i].DateOfBirth.Month;
			new_student[i].DateOfBirth.Year = s[i].DateOfBirth.Year;
			new_student[i].SocialID = s[i].SocialID;
			new_student[i].Class = s[i].Class;
			new_student[i].Pass = s[i].Pass;
		}
		int temp_to_get = 0;
		for (int i = number_student; i < new_number; i++) {
			new_student[i].No = i;
			new_student[i].StudentID = S[temp_to_get].StudentID;
			new_student[i].FirstName = S[temp_to_get].FirstName;
			new_student[i].LastName = S[temp_to_get].LastName;
			new_student[i].Gender = S[temp_to_get].Gender;
			new_student[i].DateOfBirth.Day = S[temp_to_get].DateOfBirth.Day;
			new_student[i].DateOfBirth.Month = S[temp_to_get].DateOfBirth.Month;
			new_student[i].DateOfBirth.Year = S[temp_to_get].DateOfBirth.Year;
			new_student[i].SocialID = S[temp_to_get].SocialID;
			new_student[i].Class = S[temp_to_get].Class;
			new_student[i].Pass = S[temp_to_get].Pass;
			temp_to_get++;
		}
		Print_ListStudent(new_student, new_number);
		Write_File_After_Update_Student(new_student, new_number);
		ofstream outfile;
		outfile.open("NewStudent.csv");
		if (!outfile.is_open())
			return;
		int no = 1;
		outfile << "No" << "," << "School year" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," <<
			"Gender" << "," << "Date of birth" << "," << "Social ID" << "," << "Class" << "," << endl;
		for (int i = 0; i < number_student; i++) {
			outfile << no << "," << schoolYear << "-" << schoolYear + 1 << "," << s[i].StudentID << "," << s[i].FirstName << "," << s[i].LastName << "," << s[i].Gender <<
				"," << s[i].DateOfBirth.Day << "/" << s[i].DateOfBirth.Month << "/" << s[i].DateOfBirth.Year << "," << s[i].SocialID << "," << s[i].Class << endl;
			no++;
		}
	}
}
void Create_Course(Courses*& C, int& t) {
	Courses temp;
	cout << "Please, Enter new course's information:" << endl;
	cin.ignore();
	cout << "Course ID: ";
	getline(cin, temp.ID);
	cout << "Course Name: ";
	getline(cin, temp.Class_Name);
	cout << "Teacher Name: ";
	getline(cin, temp.Teacher_Name);
	cout << "Number of Credits: ";
	cin >> temp.Credits;
	cout << "Max Member: ";
	cin >> temp.MaxStudent;
	cin.ignore();
	cout << "Day 1st of the week: ";
	getline(cin, temp.Day_First);
	cout << "Session 1st: ";
	getline(cin, temp.Session_First);
	cout << "Day 2nd of the week: ";
	getline(cin, temp.Day_Second);
	cout << "Session 2nd: ";
	getline(cin, temp.Session_Second);
	cout << "Day Begin: ";
	cin >> temp.DayBegin;
	cout << "Month Begin: ";
	cin >> temp.MonthBegin;
	cout << "Day End: ";
	cin >> temp.DayEnd;
	cout << "Month End: ";
	cin >> temp.MonthEnd;

	Courses* new_course = new Courses[t + 1];
	copy(C, C + t, new_course);
	new_course[t].ID = temp.ID;
	new_course[t].Class_Name = temp.Class_Name;
	new_course[t].Teacher_Name = temp.Teacher_Name;
	new_course[t].Credits = temp.Credits;
	new_course[t].MaxStudent = temp.MaxStudent;
	new_course[t].Day_First = temp.Day_First;
	new_course[t].Session_First = temp.Session_First;
	new_course[t].Day_Second = temp.Day_Second;
	new_course[t].Session_Second = temp.Session_Second;
	new_course[t].DayBegin = temp.DayBegin;
	new_course[t].MonthBegin = temp.MonthBegin;
	new_course[t].DayEnd = temp.DayEnd;
	new_course[t].MonthEnd = temp.MonthEnd;
	t++;
	delete[]C;
	C = new_course;
}
void Write_Course_To_File(Courses* C, int t) {
	ofstream outfile;
	outfile.open("Course.csv");
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
void Update_Course(Courses*& C, int t) {
	string Courses_ID;
	cin.ignore();
	cout << "Input the Course ID that need to update:";
	getline(cin, Courses_ID);
	int check = 0;
	for (int i = 0; i < t; i++) {
		if (C[i].ID == Courses_ID) {
			check++;
			Courses Temp;
			system("cls");
			cout << "UPDATE COURSE" << endl;;
			cout << "Input new course's information:" << endl;
			cout << "Course ID: ";
			getline(cin, Temp.ID);
			cout << "Course Name: ";
			getline(cin, Temp.Class_Name);
			cout << "Teacher Name: ";
			getline(cin, Temp.Teacher_Name);
			cout << "Number of Credits: ";
			cin >> Temp.Credits;
			cout << "Max Member:";
			cin >> Temp.MaxStudent;
			cin.ignore();
			cout << "Day 1st of the week:";
			getline(cin, Temp.Day_First);
			cout << "Session 1st:";
			getline(cin, Temp.Session_First);
			cout << "Day 2nd of the week:";
			getline(cin, Temp.Day_Second);
			cout << "Session 2nd:";
			getline(cin, Temp.Session_Second);
			cout << "Day Begin:";
			cin >> Temp.DayBegin;
			cout << "Month Begin:";
			cin >> Temp.MonthBegin;
			cout << "Day End:";
			cin >> Temp.DayEnd;
			cout << "Month End:";
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
	if (check == 0)
		cout << "Course do not exist!" << endl;
}
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
				cout << "Are you sure you want to delete this Course(y/n)?: ";
				cin >> check;
				if ((int)check == (int)'y') {
					Delete_Array_Of_Courses(C, t, i);
					return;
				}
				else return;
			} while ((check != 'y') && (check != 'n'));
		}
	}
	cout << "Cann't find this Course." << endl;
}
void Register_Courses(Courses*& C, int& t)
{
	int day = 0, month = 0, option = 0;
	cout << "\n\n\tCurrent time" << endl;
	do {
		cout << "Day: "; cin >> day;
		cout << "Month: "; cin >> month;
	} while (Check_Time_Input(day, month) == false);
	while (true)
	{
		system("cls");
		cout<<"\tCourses Registration"<<endl;
		cout << "\n\t1. View list's courses.";
		cout << "\n\t2. Create new course.";
		cout << "\n\t3. Update infor's course.";
		cout << "\n\t4. Delete course.";
		cout << "\n\t0. Back forward.";
		cout << "\n\t*******************************";
		cout << "\n\t Choose the option you wanna do: "; cin >> option;
		while ((option < 0) || (option > 4))
		{
			cout << "Your option isn't suitble\nPlease choose it again: "; cin >> option;
		}
		switch (option)
		{
		case 1:
		{
			system("cls");
			cout<<"List courses";
			cout << "\t List of courses existing: \n";
			cout << "Current Time: " << day << "/" << month << endl;
			cout << setw(13) << left << "Course ID" << setw(30) << left << "Course Name"  << setw(10) << left << "Day Begin" << setw(10) << "Day End" << endl;
			for (int i = 0; i < t; i++) {
				if (Check_Date(C, i, day, month)) {
					cout << setw(13) << left << C[i].ID << setw(30) << left << C[i].Class_Name
						 << setw(2) << left << C[i].DayBegin << "/" << setw(7) << left << C[i].MonthBegin
						 << setw(2) << left << C[i].DayEnd << "/" << setw(7) << left << C[i].MonthEnd << endl;
				}
			}
			system("pause");
		}break;
		case 2:
		{
			system("cls");
			cout<<"CREATE COURSE"<<endl;
			Create_Course(C, t);
			Write_Course_To_File(C, t);
			system("pause");
		}break;
		case 3:
		{
			system("cls");
			cout<<"UPDATE COURSE"<<endl;
			Update_Course(C, t);
			Write_Course_To_File(C, t);
			system("pause");
		}break;
		case 4:
		{
			system("cls");
			cout << "DELETE COURSE" << endl;
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
	outfile.open("StudentCourses.csv");
	if (!outfile.is_open()) {
		cout << "Cann't open file" << endl;
		return;
	}
	outfile << "No" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Class" << "," << "Course ID" << "," << "Course Name" << "," << "Credits" << "," << "Teacher Name" << "," << "day1" << "," << "session1" << "," << "day2" << "," << "session2" << "," << "day start" << "," << "month start" << "," << "day end" << "," << "month end" << "," << "Other mark" << "," << "Midterm mark" << "," << "Final mark" << "," << "Total mark" << endl;
	for (int i = 0; i < p; i++) {
		outfile << SC[i].No << "," << SC[i].StudentID << "," << SC[i].FirstName << "," << SC[i].LastName << "," << SC[i].Gender << "," << SC[i].Class << "," << SC[i].CourseID << "," << SC[i].Classname << "," << SC[i].Credits << "," << SC[i].TeacherName<< "," << SC[i].Day1 << "," << SC[i].Session1 << "," << SC[i].Day2 << "," << SC[i].Session2 << "," << SC[i].DayBegin << "," << SC[i].MonthBegin << "," << SC[i].DayEnd << "," << SC[i].MonthEnd << "," << SC[i].OtherMark << "," << SC[i].MidtermMark << "," << SC[i].FinalMark<< "," << SC[i].TotalMark << endl;
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
		cout << "\n\t3. List courses you registered";
		cout << "\n\t4. Delete a course you registered";
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
			cout<<"LIST COURSES"<<endl;
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
			cout<<"REGISTER COURSE"<<endl;
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
				cout << "You registered 5 courses!\n";
			else {
				Add_Student_To_Courses(SC, p, C, t, S, n, ID);
			}
			Write_To_File_After_Update_Student_Courses(SC, p);
			system("pause");
		}break;
		case 3:
		{
			system("cls");
			cout<<"LIST COURSES"<<endl;
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
			cout<<"DELETE COURSE";
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
			SCtemp.No          = SC[i].No + 1;
			SCtemp.StudentID   = SC[i].StudentID;
			SCtemp.FirstName   = SC[i].FirstName;
			SCtemp.LastName    = SC[i].LastName;
			SCtemp.Gender      = SC[i].Gender;
			SCtemp.Class       = SC[i].Class;
			SCtemp.CourseID    = C[position].ID;
			SCtemp.Classname   = C[position].Class_Name;
			SCtemp.Credits     = C[position].Credits;
			SCtemp.TeacherName = C[position].Teacher_Name;
			SCtemp.Day1        = C[position].Day_First;
			SCtemp.Session1    = C[position].Session_First;
			SCtemp.Day2        = C[position].Day_Second;
			SCtemp.Session2    = C[position].Session_Second;
			SCtemp.DayBegin    = C[position].DayBegin;
			SCtemp.MonthBegin  = C[position].MonthBegin;
			SCtemp.DayEnd      = C[position].DayEnd;
			SCtemp.MonthEnd    = C[position].MonthEnd;
			SCtemp.OtherMark   = 0;
			SCtemp.MidtermMark = 0;
			SCtemp.FinalMark   = 0;
			SCtemp.TotalMark   = 0;
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
	cout << "Please enter exactly the course ID of the course you wanna delete: ";
	getline(cin, temp);
	for (int i = 0; i < p; i++)
	{
		if (Check_Date_Student_Courses(SC, i, day, month))
			if ((SC[i].CourseID == temp) && (SC[i].StudentID == ID))
			{
				char check;

				cout << "Are you sure you wanna delete this Course(y / n)?: ";
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
	cout << "Course ID : " << SC[i].CourseID << " || Course : " << SC[i].Classname << " || Total Mark: " << SC[i].TotalMark << " || Final Mark: " << SC[i].FinalMark <<
		" || Midterm Mark: " << SC[i].MidtermMark << " || Other Mark: " << SC[i].OtherMark << endl;
}
void Print_Student_Of_Courses(Student_Courses* SC, int p) {
	
		cout << "Student ID: " << SC[p].StudentID << " || Name: " << SC[p].FirstName << " " << SC[p].LastName << " || Class: " << SC[p].Class << " || Course ID: " << SC[p].CourseID << " || Course: " << SC[p].Classname << " || Semester: " << SC[p].DayBegin<< "/" << SC[p].MonthBegin<< " - " << SC[p].DayEnd<< "/" << SC[p].MonthEnd << endl;

}
void Print_Schedule(Student_Courses* SC, int p) {

	cout << "Course ID: " << SC[p].CourseID << " || Course: " << SC[p].Classname << " || Semester: " << SC[p].DayBegin << "/" << SC[p].MonthBegin << " - " << SC[p].DayEnd << "/" << SC[p].MonthEnd << endl;

}
void Print_One_Student_Of_Courses(Student_Courses* SC, int i) {
	cout << setw(12) << left << "Student ID"
		 << setw(20) << left << "Last Name"
		 << setw(15) << left << "First Name"
		 << setw(10) << left << "Class"
		 << setw(15) << left << "Course ID"
		 << setw(30) << left << "Class Name"
		 << setw(15) << left << "Date Begin"
		 << setw(5)  << left << "Date End" << endl;
	cout << setw(12) << left << SC[i].StudentID 
		 << setw(20) << left << SC[i].LastName 
		 << setw(15) << left << SC[i].FirstName 
		 << setw(10) << left << SC[i].Class 
		 << setw(15) << left << SC[i].CourseID 
		 << setw(30) << left << SC[i].Classname 
		 << setw(2)  << left << SC[i].DayBegin  << "/"<<setw (12) << left << SC[i].MonthBegin 
		 << setw(2)  << left << SC[i].DayEnd    << "/"<<setw (13) << left << SC[i].MonthEnd   << endl;
}
void Print_A_Student_Of_Courses(Student_Courses* SC, int i) {
	cout << setw(12) << left << SC[i].StudentID
		<< setw(20) << left << SC[i].LastName
		<< setw(15) << left << SC[i].FirstName
		<< setw(10) << left << SC[i].Class
		<< setw(15) << left << SC[i].CourseID
		<< setw(30) << left << SC[i].Classname
		<< setw(2) << left << SC[i].DayBegin << "/" << setw(12) << left << SC[i].MonthBegin
		<< setw(2) << left << SC[i].DayEnd << "/" << setw(13) << left << SC[i].MonthEnd << endl;
}
void print_title_student_of_course() {
	cout << setw(12) << left << "Student ID" << setw(20) << left << "Last Name" << setw(15) << left << "First Name" << setw(10) << left << "Class" << setw(15) << left << "Course ID" << setw(30) << left << "Course" << setw(15) << left << "Day Begin" << setw(15) << left << "Day End" << endl;
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
			cout << C[pos].ID << endl;
			cout << SC[i].CourseID << endl;
			Print_One_Teacher(T[pos]);
			cout << "\t\tEnter Score for student:" << endl;
			Print_Student_Of_Courses(SC, i);
			cout << "Final mark: ";
			cin >> SC[i].FinalMark;
			cout << "Midterm mark: ";
			cin >> SC[i].MidtermMark;
			cout << "Other mark: ";
			cin >> SC[i].OtherMark;
			SC[i].TotalMark = (SC[i].OtherMark + SC[i].MidtermMark + 2 * SC[i].FinalMark) / 4;
			cout << i << endl;
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
	cout << "Enter ID of a course: ";
	getline(cin, ID);
	int temp = 1;
	for (int i = 0; i < p; i++) {
		if (ID == SC[i].CourseID)
		{
			cout << "No:" << temp<<endl;
			cout << "ID: " << SC[i].StudentID << " || Name: " << SC[i].FirstName << " " << SC[i].LastName << " || Class: " << SC[i].Class << " || Course ID: " << SC[i].CourseID << " || Course: " << SC[i].Classname << " || Semester: " << SC[i].DayBegin << "/" << SC[i].MonthBegin << " - " << SC[i].DayEnd << "/" << SC[i].MonthEnd <<endl
				<<"Total Mark: " << SC[i].TotalMark << " || Final Mark: " << SC[i].FinalMark <<
				" || Midterm Mark: " << SC[i].MidtermMark << " || Other Mark: " << SC[i].OtherMark << endl;
			temp++;
		}
	}
}
void Score_Board_Class(Student_Courses* SC, int p) {
	string ID;
	cin.ignore();
	cout << "Enter ID of a class: ";
	getline(cin, ID);
	int temp = 1;
	for (int i = 0; i < p; i++) {
		if (ID == SC[i].Class)
		{
			cout << "No:" << temp << endl;
			cout << "ID: " << SC[i].StudentID << " || Name: " << SC[i].FirstName << " " << SC[i].LastName << " || Course ID: " << SC[i].CourseID << " || Course: " << SC[i].Classname << " || Semester: " << SC[i].DayBegin << "/" << SC[i].MonthBegin << " - " << SC[i].DayEnd << "/" << SC[i].MonthEnd <<
				endl<<	"Total Mark: " << SC[i].TotalMark << " || Final Mark: " << SC[i].FinalMark <<
				" || Midterm Mark: " << SC[i].MidtermMark << " || Other Mark: " << SC[i].OtherMark << endl;
			temp++;
		}
	}
}
void View_Classes(Classes*& Clas, int& k, Student* S, int n)
{
	int count = 0;

	Clas[k - 1].NameClass = S[0].Class; //k=1
	Clas[k - 1].Num = 1;
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
	for (int i = 0; i < k; i++)
	{
		cout << "\n\t Class: " << Clas[i].NameClass << " | " << Clas[i].Num << " Students " << endl;
	}
}
