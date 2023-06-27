#include"Header.h"
int main() {
	string User, Pass;
	Student* S;
    S = nullptr;
	Teacher* T;
    T = nullptr;
	Courses* course;
    course = nullptr;
	Student_Courses* SC;
    SC = nullptr;
	int m =0, n =0, p = 0,t = 0, k = 1;
	ReadStudent(S, n);
	Read_Teacher(T, m);
	Read_File_Courses(course, t);
	Write_Register_Student_Default(course, t, S, n, SC, p);
	Write_To_File_After_Update_Student_Courses(SC, p);
	Classes* Class;
    Class = nullptr;
	Class = new Classes[n - 1];
	string user, password;
	int schoolYear = 0;
	bool check = true;
	int count = 0;
    do {
      //  cout<<"\t\t\tLOGIN"<<endl;
        Input_Account(user, password);
        int pos = -1;
        if (CheckPass_Teacher(T, m, pos, user, password) == true) {
            system("cls");
            int check_temp = true;
            int menu = 0;
            do {
                system("cls");
                Menu_Staff();
                Personal_Infor_Teacher(T[pos]);
                cout << "\n\t\t\t\t\t\tChoose the option you wanna do: ";
                cin >> menu;
                while ((menu < -1) || (menu > 12))
                {
                    cout << "The option you enter isn't suitable\nPlease choose it again: "; cin >> menu;
                }
                switch (menu) {
                case 1:
                {
                    system("cls");
                    cout<< "Change password"<<endl;
                    Change_Pass_Of_Teacher(T, m, user);
                    Write_File_After_Update_of_Teacher(T, m);
                    system("pause");
                }break;
                case 2: {
                    system("cls");
                    Update_Infor_Of_Teacher(T, m, user);
                   Write_File_After_Update_of_Teacher(T, m);
                    system("pause");
                } break;
                case 3: {
                    system("cls");
                    cout<<"Create a school year."<<endl;
                    Create_School_Year(schoolYear);
                    system("pause");
                } break;
                case 4: {
                    system("cls");
                    cout<<"Add new 1st year students to 1st year classes."<<endl;
                    if (schoolYear == 0) {
                        cout << "You need to create a new school year before Add new 1st to classes." << endl;
                    }
                    else {
                        Add_1st_Student_To_Class(schoolYear, S, n);
                    }
                    system("pause");
                } break;
                case 5: {
                    system("cls");
                    cout<<"Register course"<<endl;
                    cout << "\tCourses existed: " << t << endl;
                    Print_Courses(course, t);
                    Register_Courses(course, t);
                    system("pause");
                } break;
                case 6:
                {
                    system("cls");
                    cout<<"Export list of students in a course"<<endl;
                    Export_Student(SC, p);
                    system("pause");
                } break;

                case 7: {
                    system("cls");
                    cout<<"Enter the scoreboard of a course."<<endl;
                    Enter_Scoreboard_Of_Course(SC, p, pos, course, T);
                    Write_To_File_After_Update_Student_Courses(SC, p);
                    count = 7;
                    system("pause");
                } break;

                case 8: {
                    system("cls");
                    if (count != 7) {
                        cout << "You need enter the scoreboard of your course before!" << endl;
                    }
                    else {
                        cout<<"View the scoreboard of a course."<<endl;
                        Print_ElementTeacher(T, pos);
                        View_ScoreBoard(SC, p, pos, course);
                    }
                    system("pause");
                } break;
                case 9:
                {
                    system("cls");
                    if (count != 7) {
                        cout << "You need enter the scoreboard of your course before!" << endl;
                    }
                    else {
                        cout<<"Import the scoreboard of a course."<<endl;
                        Import_ScoreBoard(SC, p, pos, course);
                    }
                    system("pause");
                } break;

                case 10: {
                    system("cls");
                    cout<<"Update a student result."<<endl;
                    View_ScoreBoard(SC, p, pos, course);
                    Update_Student_Result(SC, p);
                    Write_To_File_After_Update_Student_Courses(SC, p);;
                    system("pause");
                } break;

                case 11: {
                    system("cls");
                    cout<<"View the scoreboard of a class.";
                    Score_Board_Class(SC, p);
                    system("pause");
                } break;
                case 12:
                {
                    system("cls");
                    cout<<"View the scoreboard of a course.";
                    Score_Board_Course(SC, p);
                    system("pause");
                } break;
                case 0: {
                    system("cls");
                    cin.ignore();
                    check_temp = false;
                } break;
                case -1: {
                    check_temp = false;
                    check = false;
                } break;
                }
            } while (check_temp);
        }
        else
        {
            if (CheckPass_Student(S, n, pos, user, password) == true) {
                system("cls");
                int check_temp = true;
                int menu = 0;
                do {
                    system("cls");
                    Menu_Student();
                   // Print_One_Student(S[pos]);
                    Personal_Infor_Student(S[pos]);
                    cout << "\n\t\t\t\t\tChoose the option you wanna do: ";
                    cin >> menu;
                    while ((menu < -1) || (menu > 8))
                    {
                        cout << "The option you enter isn't suitable\nPlease choose it again: "; cin >> menu;
                    }
                    switch (menu) {
                    case 1:
                    {
                        system("cls");
                        cout<<"Change password";
                        Change_Pass_Of_Student(S, n, user);
                        Write_File_After_Update_Student(S, n);
                        system("pause");
                    }break;
                    case 2: {
                        system("cls");
                        Update_Infor_Of_Student(S, n, user);
                        Write_File_After_Update_Student(S, n);
                        system("pause");
                    } break;
                    case 3: {
                        system("cls");
                        cout<<"Register course"<<endl;
                        cout <<"Courses existed: " << endl;
                        Print_Courses(course, t);
                        Register_Student_Courses(SC, p, course, t, S, n, user);
                        system("pause");
                    } break;
                    case 4: {
                        system("cls");
                        cout<<"Schedule";
                        int count = 0, day = 0, month = 0;
                        cout << "\n\n\tEnter Current time to view your Courses:" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (Check_Time_Input(day, month) == false);
                        for (int i = 0; i < p; i++)
                        {
                            if (Check_Date_Student_Courses(SC, i, day, month))
                                if (SC[i].StudentID == user)
                                {
                                    Print_Student_Of_Courses(SC, i);
                                    count++;
                                }
                        }
                        if (count == 0) cout << "You haven't registered any courses in this semester\n";
                        system("pause");
                    } break;
                    case 5:
                    {
                        system("cls");
                        cout<<"Scoreboard"<<endl;
                        int count = 0, day = 0, month = 0;
                        cout << "\n\n\tEnter Current time to view your Courses" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (Check_Time_Input(day, month) == false);
                        for (int i = 0; i < p; i++)
                        {
                            if (Check_Date_Student_Courses(SC, i, day, month)) {
                                if (SC[i].StudentID == user) {
                                    View_Score(SC, p, i);
                                }
                            }
                        }
                        system("pause");
                    }break;
                    case 6: {
                        system("cls");
                        cout<<"List students in a course";
                        string ID;
                        int count = 0, day = 0, month = 0;
                        cout << "\tEnter Current time to view your Courses" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (Check_Time_Input(day, month) == false);
                        cout << "\tEnter ID of courses to view list students: ";
                        cin.ignore();
                        getline(cin, ID);
                        for (int i = 0; i < p; i++)
                        {
                            if (Check_Date_Student_Courses(SC, i, day, month)) {
                                if (SC[i].CourseID == ID) {
                                    Print_Student_Of_Courses(SC, i);
                                }
                            }
                        }
                        system("pause");

                    } break;
                    case 7:
                    {
                        system("cls");
                        cout<<"List of classes";
                        View_Classes(Class, k, S, n);
                        for (int i = 0; i < k; i++)
                        {
                            cout << "\n\t Class: " << Class[i].NameClass << " | " << Class[i].Num << " Students " << endl;
                        }
                        system("pause");
                    } break;
                    case 8:
                    {
                        system("cls");
                        cout<<"List student in a class";
                        string ID;
                        cout << "\tEnter ID of class to view list students: ";
                        cin.ignore();
                        getline(cin, ID);
                        cout << ID << endl;
                        for (int i = 0; i < p; i++)
                        {
                            if (SC[i].Class == ID) {
                                Print_One_Student_Of_Courses(SC, i);
                               // Print_Student_Of_Courses(SC, i);
                              //  Print_ElementStudent(S, i);
                            }
                        }

                        system("pause");
                    }break;
                    case 0: {
                        system("cls");
                        cin.ignore();
                        check_temp = false;
                    } break;
                    case -1: {
                        check_temp = false;
                        check = false;
                    } break;
                    }
                } while (check_temp);
            }
            else {
                system("cls");
                cout << "\n\tKhong co tai khoan trong he thong!";
                Sleep(3000);
                cin.ignore();
                system("cls");
            }
        }
    } while (check);
    delete[] S;
    delete[] T;
    delete[] course;
    delete[] Class;
    delete[] SC;
	system("pause");
	return 0;
}