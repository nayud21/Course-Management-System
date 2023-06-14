#pragma once
#include <iostream>
#include<iomanip>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
struct DateOfBirth {
	int Day;
	int Month;
	int Year;
};
typedef DateOfBirth Date;
struct Student {
	int No;
	string StudentID;
	string FirstName;
	string LastName;
	string Gender;
	Date DateOfBirth;
	string SocialID;
	string Class;
	string Pass;

};
struct Teacher {
	int No;
	string TeacherID;
	string FirstName;
	string LastName;
	string Gender;
	int SocialID;
	string Faculty;
	string Pass;
};
struct Courses {
	int Credits;
	int MaxStu;
	int DayBegin;
	int MonthBegin;
	int DayEnd;
	int MonthEnd;
	string ID;
	string Class_Name;
	string Teacher_Name;
	string Day1;
	string Session1;
	string Day2;
	string Session2;
};
struct Student_Courses {
	int No;
	string StudentID;
	string Firstname;
	string LastName;
	string Gender;
	string Class;
	string CourseID;
	string Classname;
	int Credits;
	string TeacherName;
	string Day1;
	string Session1;
	string Day2;
	string Session2;
	int DayBegin;
	int MonthBegin;
	int DayEnd;
	int MonthEnd;
	float OtherMark;
	float MidtermMark;
	float FinalMark;
	float TotalMark;
};
struct Classes {
	string NameClass;
	int Num;
};



//
int StringToInteger(string s);
int CountStudent();
void ReadStudent(Student*& S, int& n);
void Print_ListStudent(Student* S, int n);
void Print_ElementStudent(Student* S, int i);
void Print_One_Teacher(Teacher T);
//
int CountTeacher();
void Read_Teacher(Teacher*& T, int& n);
void Print_ListTeacher(Teacher* T, int m);
void Print_ElementTeacher(Teacher* T, int i);
//
bool CheckPass_Teacher(Teacher* T, int m, int& pos, string user, string Pass);
bool CheckPass_Student(Student* S, int n, int& pos, string user, string Pass);
//

void Input_Account(string& User, string& Pass);
//



void Login();
void Registration();
void ForgotPassword();
void ReadDate(ifstream& filein, Date& date);
void ReadSinhvien(ifstream& filein, Student& sv);
void Output(Student sv);
void Menu_Student();
void Menu_Staff();
void Menu_Login();
