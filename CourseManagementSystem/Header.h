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
	int SocialID;
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
	int MaxStudent;
	int DayBegin;
	int MonthBegin;
	int DayEnd;
	int MonthEnd;
	string ID;
	string Class_Name;
	string Teacher_Name;
	string Day_First;
	string Session_First;
	string Day_Second;
	string Session_Second;
};
struct Student_Courses {
	int No;
	string StudentID;
	string FirstName;
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
int Count_Student();
void ReadStudent(Student*& S, int& n);
void Print_ListStudent(Student* S, int n);
void Print_ElementStudent(Student* S, int i);
void Print_One_Teacher(Teacher T);
void Print_One_Student(Student S);
//
int Count_Teacher();
void Read_Teacher(Teacher*& T, int& n);
void Print_ListTeacher(Teacher* T, int m);
void Print_ElementTeacher(Teacher* T, int i);
//
bool CheckPass_Teacher(Teacher* T, int m, int& pos, string user, string Pass);
bool CheckPass_Student(Student* S, int n, int& pos, string user, string Pass);
//

void Input_Account(string& User, string& Pass);
//
void Change_Pass_Of_Student(Student*& S, int n, string ID);
void Change_Pass_Of_Teacher(Teacher*& T, int m, string ID);
void Update_Infor_Of_Student(Student*& S, int n, string ID);
void Update_Infor_Of_Teacher(Teacher*& T, int m, string ID);
//
//Courses
void Read_File_Courses(Courses*& C, int& t);
void Create_Course(Courses*& C, int& t);
void Update_Course(Courses*& C, int t);
void Print_Courses(Courses* C, int t);
void Delete_Array_Of_Courses(Courses*& C, int& t, int i);
void Delete_Course(Courses*& C, int& t);
void Register_Courses(Courses*& C, int& t);
int Count_Courses();
void Write_To_File_After_Update_Student_Courses(Student_Courses* SC, int p);
void Register_Student_Courses(Student_Courses*& SC, int& p, Courses* C, int t, Student* S, int n, string ID);
int Exist_Course(Courses* C, int t, string ID);
void Add_Student_To_Courses(Student_Courses*& SC, int& p, Courses* C, int t, Student* S, int n, string ID);
void Print_One_Student_Of_Courses(Student_Courses* SC, int i);
void Check_Delete_Student_Of_Courses(Student_Courses*& SC, int& p, string ID, int day, int month);
void Delele_Student_Courses(Student_Courses*& SC, int& p, int i);
void Check_Delete_Student_Of_Courses(Student_Courses*& SC, int& p, string ID, int day, int month);
void Print_Student_Of_Courses(Student_Courses* SC, int p);
void Print_One_Student_Of_Courses(Student_Courses* SC, int i);

void Menu_Staff();
void Menu_Student();









void Write_File_After_Update_of_Teacher(Teacher* T, int m);
void Write_File_After_Update_Student(Student* S, int n);
bool Check_Time_Input(int day, int month);
bool Check_Date(Courses* C, int i, int day, int month);
bool Check_Date_Student_Courses(Student_Courses* SC, int i, int day, int month);
void Create_School_Year(int& schoolyear);
void Add_1st_Student_To_Class(int schoolYear, Student* S, int n);
void Write_Course_To_File(Courses* C, int t);
void Write_Register_Student_Default(Courses* C, int t, Student* S, int n, Student_Courses*& SC, int& p);
void Add_Element_To_Arr(Student_Courses*& SC, int& p, int i, Student_Courses temp);
bool Un_Duplicated(Student_Courses* SC, int p, Courses* C, int t, string ID, int position);
void View_Score(Student_Courses* SC, int p, int i);
bool Check_Export(Student_Courses* SC, int p, string temp);


//ScoreBoard
void Export_Student(Student_Courses* SC, int p);
void Enter_Scoreboard_Of_Course(Student_Courses*& SC, int p, int pos, Courses* C, Teacher* T);
void View_ScoreBoard(Student_Courses* SC, int p, int pos, Courses* C);
void Import_ScoreBoard(Student_Courses* SC, int p, int pos, Courses* C);
void Update_Student_Result(Student_Courses*& SC, int p);
void Score_Board_Course(Student_Courses* SC, int p);
void Score_Board_Class(Student_Courses* SC, int p);

//ViewClass
void View_Classes(Classes*& Clas, int& k, Student* S, int n);


void Personal_Infor_Teacher(Teacher T);