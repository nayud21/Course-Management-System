#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct DateOfBirth {
	int Day;
	int Month;
	int Year;
};
typedef DateOfBirth Date;
struct SINHVIEN {
	int No;
	string StudentID;
	string Name;
	char Gender[4];
	Date ngaysinh;
	char* SocialId;
};
//struct node {
//	SINHVIEN data;
//	NODE *pNext;
//};
//typedef struct node NODE;
//struct list {
//	NODE* pHEAD;
//	NODE* pTAIL;
//};
//void khoitaodanhsach(list& l);
//NODE* KhoitaoNODE(SINHVIEN x);
//void ThemCuoi(list& l, NODE* p);
//void ThemDau(list& l, NODE* p);
void Login();
void Registration();
void ForgotPassword();
void ReadDate(ifstream& filein, Date& date);
void ReadSinhvien(ifstream& filein, SINHVIEN& sv);
void Output(SINHVIEN sv);
void Menu_Student();
void Menu_Staff();
void Menu_Login();
