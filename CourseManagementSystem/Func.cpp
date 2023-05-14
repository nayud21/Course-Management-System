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
//void khoitaodanhsach(list& l) {
//	l.pHEAD = NULL;
//	l.pTAIL = NULL;
//}
//NODE* KhoitaoNODE(SINHVIEN x) {
//	NODE* p = new NODE;
//	if (p == 0) {
//		cout << "\nCap phat du lieu that bai!";
//		return 0;
//	}
//	p->data= x;
//	p->pNext = NULL;
//	return p;
//}
//void ThemDau(list& l, NODE* p) {
//	if (l.pHEAD = NULL) {
//		l.pHEAD = l.pTAIL = p;
//	}
//	else {
//		p->pNext = l.pHEAD;
//		l.pHEAD = p;
//	}
//}
//void ThemCuoi(list& l, NODE* p) {
//	if (l.pHEAD == 0) {
//		l.pHEAD = l.pTAIL = p;
//	}
//	else
//	{
//		l.pTAIL->pNext = p;
//		l.pTAIL = p;
//	}
//}
void ReadDate(ifstream &filein,Date &date) {
	filein >> date.Day;
	filein.seekg(1, 1);//dich sang phai 1 byte
	filein >> date.Month;
	filein.seekg(1, 1);//dich sang phai 1 byte
	filein >> date.Year;
}
void ReadSinhvien(ifstream &filein, SINHVIEN &sv) {
	getline(filein, sv.Name, ',');
	//filein.seekg(1, 1);
	getline(filein, sv.StudentID, ',');
	//filein.seekg(1, 1);
	ReadDate(filein, sv.ngaysinh);
}
void Output(SINHVIEN sv) {
	cout << "\nHo ten: " << sv.Name;
	cout << "\nMSSV: " << sv.StudentID;
	cout << "\nNgay sinh: " << sv.ngaysinh.Day << "/" << sv.ngaysinh.Month << "/" << sv.ngaysinh.Year<<endl;
}
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
