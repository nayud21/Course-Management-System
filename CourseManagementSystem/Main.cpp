#include"Header.h"
int main() {
	string User, Pass;
	Student* S;
	Teacher* T;
	Courses* course;
	Student_Courses* SC;
	int m =0, n =0, p = 0,t = 0, k = 1;
	ReadStudent(S, n);
	Read_Teacher(T, m);
	Print_ListTeacher(T, m);
	//Print_ListStudent(S, n);
	system("pause");
	return 0;
}