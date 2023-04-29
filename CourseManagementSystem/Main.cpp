#include"Header.h"
int main() {
	int c;
	cout << "\t\t\t\--------------------------------------------------------------\n\n\n";
	cout << "\t\t\t                       WELLCOME TO SYSTEM                 \n\n\n";
	cout << "\t\t\t-------------------------     MENU    ------------------------\n\n\n";
	cout << endl;
	cout << "\t\t\t\t     | Press 1 to Login                   |\n";
	cout << "\t\t\t\t     | Press 2 to REGISTRATION            |\n";
	cout << "\t\t\t\t     | Press 3 if you fotgot PASSWORD     |\n";
	cout << "\t\t\t\t     | Press 4 to Exit                    |\n";
	cout << "Enter your choice: ";
	cin >> c;
	cout << endl;
	switch (c)
	{
	case 1:
		Login();
		break;
	case 2:
		Registration();
		break;
	case 3:
		ForgotPassword();
		break;
	case 4:
		cout << "You seleted Exit. Thank you!\n";
		break;
	default:
		system("cls");
		cout << "Pleas select choice in MENU!\n";
		main();
		break;
	}
	SINHVIEN sv;
	ifstream filein;
	filein.open("SINHVIEN.txt", ios::in);
	ReadSinhvien(filein, sv);

	Output(sv);
	filein.close();
	system("pause");
	return 0;
}