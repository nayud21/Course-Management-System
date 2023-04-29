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
