#include"Header.h"
int main() {
	string User, Pass;
	Student* list_student=nullptr;
	Teacher* list_teacher=nullptr;
	Courses* list_course=nullptr;
	Student_Courses* list_student_course=nullptr;
	int number_of_teacher =0,
        number_of_student =0, 
        number_of_student_course = 0,
        number_of_course = 0,
        temp_to_view_class=1;
	ReadStudent(list_student, number_of_student);
	Read_Teacher(list_teacher, number_of_teacher);
	Read_File_Courses(list_course, number_of_course);
	Write_Register_Student_Default(list_course, number_of_course, list_student, number_of_student, list_student_course, number_of_student_course);
	Write_To_File_After_Update_Student_Courses(list_student_course, number_of_student_course);
	Classes* list_class=nullptr;
	list_class = new Classes[number_of_student - 1];
	string user, password;
	int schoolYear = 0;
	bool check_menu = true;
	int count = 0;
    do {
        Input_Account(user, password);
        int pos = -1;
        if (CheckPass_Teacher(list_teacher, number_of_teacher, pos, user, password) == true) {
            system("cls");
            int check_temp = true;
            int menu = 0;
            do {
                system("cls");
                Menu_Staff();
                Personal_Infor_Teacher(list_teacher[pos]);
                cout << "\n\t\t\t\t\t\tChoose the option you wanna do: ";
                cin >> menu;
                while ((menu < -1) || (menu > 12))
                {
                    cout << "Your option isn't suitable\nPlease choose again: ";
                    cin >> menu;
                }
                switch (menu) {
                case 1:
                {
                    system("cls");
                    cout<< "\tCHANGE PASSWORD"<<endl;
                    Change_Pass_Of_Teacher(list_teacher, number_of_teacher, user);
                    Write_File_After_Update_of_Teacher(list_teacher, number_of_teacher);
                    system("pause");
                }break;
                case 2: {
                    system("cls");
                    Update_Infor_Of_Teacher(list_teacher, number_of_teacher, user);
                   Write_File_After_Update_of_Teacher(list_teacher, number_of_teacher);
                    system("pause");
                } break;
                case 3: {
                    system("cls");
                    cout<<"\tCREATE A SCHOOL YEAR."<<endl;
                    Create_School_Year(schoolYear);
                    system("pause");
                } break;
                case 4: {
                    system("cls");
                    cout<<"ADD 1ST YEAR STUDENT TO 1ST YEAR CLASS ."<<endl;
                    if (schoolYear == 0) {
                        cout << "YOU MUST CREATE A NEW SCHOOL YEAR!." << endl;
                    }
                    else {
                        Add_1st_Student_To_Class(schoolYear, list_student, number_of_student);
                    }
                    system("pause");
                } break;
                case 5: {
                    system("cls");
                    cout<<"\tREGISTER COURSE"<<endl;
                    cout << "\tCourses existed: " << number_of_course << endl;
                    Print_Courses(list_course, number_of_course);
                    Register_Courses(list_course, number_of_course);
                    system("pause");
                } break;
                case 6:
                {
                    system("cls");
                    cout<<"\tEXPORT LIST STUDENT IN A COURSE"<<endl;
                    Export_Student(list_student_course, number_of_student_course);
                    system("pause");
                } break;

                case 7: {
                    system("cls");
                    cout<<"\tENTER SOCREBOARD COURSE."<<endl;
                    Enter_Scoreboard_Of_Course(list_student_course, number_of_student_course, pos, list_course, list_teacher);
                    Write_To_File_After_Update_Student_Courses(list_student_course, number_of_student_course);
                    count = 7;
                    system("pause");
                } break;

                case 8: {
                    system("cls");
                    if (count != 7) {
                        cout << "YOU MUST ENTER THE SCOREBOARD OF COURSE BEFORE!" << endl;
                    }
                    else {
                        cout<<"SCOREBOARD OF COURSE."<<endl;
                        Print_ElementTeacher(list_teacher, pos);
                        View_ScoreBoard(list_student_course, number_of_student_course, pos, list_course);
                    }
                    system("pause");
                } break;
                case 9:
                {
                    system("cls");
                    if (count != 7) {
                        cout << "YOU MUST ENTER THE SCOREBOARD BEFORE!" << endl;
                    }
                    else {
                        cout<<"IMPORT SCOREBOARD OF COURSE."<<endl;
                        Import_ScoreBoard(list_student_course, number_of_student_course, pos, list_course);
                    }
                    system("pause");
                } break;

                case 10: {
                    system("cls");
                    cout<<"\tUPDATE RESULT'S STUDENT."<<endl;
                    View_ScoreBoard(list_student_course, number_of_student_course, pos, list_course);
                    Update_Student_Result(list_student_course, number_of_student_course);
                    Write_To_File_After_Update_Student_Courses(list_student_course, number_of_student_course);;
                    system("pause");
                } break;

                case 11: {
                    system("cls");
                    cout<<"\tSCOREBOARD OF CLASS.";
                    Score_Board_Class(list_student_course, number_of_student_course);
                    system("pause");
                } break;
                case 12:
                {
                    system("cls");
                    cout<<"\tTHE SCOREBOARD OF COURSE.";
                    Score_Board_Course(list_student_course, number_of_student_course);
                    system("pause");
                } break;
                case 0: {
                    system("cls");
                    cin.ignore();
                    check_temp = false;
                } break;
                case -1: {
                    check_temp = false;
                    check_menu = false;
                } break;
                }
            } while (check_temp);
        }
        else
        {
            if (CheckPass_Student(list_student, number_of_student, pos, user, password) == true) {
                system("cls");
                int check_temp = true;
                int menu = 0;
                do {
                    system("cls");
                    Menu_Student();
                   // Print_One_Student(S[pos]);
                    Personal_Infor_Student(list_student[pos]);
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
                        cout<<"\tCHANGE PASWORD";
                        Change_Pass_Of_Student(list_student, number_of_student, user);
                        Write_File_After_Update_Student(list_student, number_of_student);
                        system("pause");
                    }break;
                    case 2: {
                        system("cls");
                        Update_Infor_Of_Student(list_student, number_of_student, user);
                        Write_File_After_Update_Student(list_student, number_of_student);
                        system("pause");
                    } break;
                    case 3: {
                        system("cls");
                        cout<<"\tREGISTER COURSE"<<endl;
                        cout <<"Courses existed: " << endl;
                        Print_Courses(list_course, number_of_course);
                        Register_Student_Courses(list_student_course, number_of_student_course, list_course, number_of_course, list_student, number_of_student, user);
                        system("pause");
                    } break;
                    case 4: {
                        system("cls");
                        cout<<"\tSCHEDULE";
                        int count = 0, day = 0, month = 0;
                        cout << "\n\n\tEnter Current time to view your Courses:" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (Check_Time_Input(day, month) == false);
                        for (int i = 0; i < number_of_student_course; i++)
                        {
                            if (Check_Date_Student_Courses(list_student_course, i, day, month))
                                if (list_student_course[i].StudentID == user)
                                {
                                    Print_Student_Of_Courses(list_student_course, i);
                                    count++;
                                }
                        }
                        if (count == 0) cout << "You haven't registered any courses in this semester\n";
                        system("pause");
                    } break;
                    case 5:
                    {
                        system("cls");
                        cout<<"\tSCOREBOARD"<<endl;
                        int count = 0, day = 0, month = 0;
                        cout << "\n\n\tEnter Current time to view your Courses" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (Check_Time_Input(day, month) == false);
                        for (int i = 0; i < number_of_student_course; i++)
                        {
                            if (Check_Date_Student_Courses(list_student_course, i, day, month)) {
                                if (list_student_course[i].StudentID == user) {
                                    View_Score(list_student_course, number_of_student_course, i);
                                }
                            }
                        }
                        system("pause");
                    }break;
                    case 6: {
                        system("cls");
                        cout<<"\tLIST STUDENT IN A COURSE";
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
                        for (int i = 0; i < number_of_student_course; i++)
                        {
                            if (Check_Date_Student_Courses(list_student_course, i, day, month)) {
                                if (list_student_course[i].CourseID == ID) {
                                    Print_Student_Of_Courses(list_student_course, i);
                                }
                            }
                        }
                        system("pause");

                    } break;
                    case 7:
                    {
                        system("cls");
                        cout<<"LIST CLASSES";
                        View_Classes(list_class, temp_to_view_class, list_student, number_of_student);
                        for (int i = 0; i < temp_to_view_class; i++)
                        {
                            cout << "\n\t Class: " << list_class[i].NameClass << " | " <<list_class[i].Num << " Students " << endl;
                        }
                        system("pause");
                    } break;
                    case 8:
                    {
                        system("cls");
                        cout<<"\t* LIST STUDENT IN A CLASS"<<endl;
                        string ID;
                        cout << "\tID of class you want to view: ";
                        cin.ignore();
                        getline(cin, ID);
                        cout << "\t************************************\n";
                        print_title_student_of_course();
                        for (int i = 0; i < number_of_student_course; i++)
                        {
                            if (list_student_course[i].Class == ID) {
                                Print_One_Student_Of_Courses(list_student_course, i);
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
                        check_menu = false;
                    } break;
                    }
                } while (check_temp);
            }
            else {
                system("cls");
                system("color C");
                cout << "\t\t\t\t\t\tWARNING";
                cout << "\n\t\t\t\t\tID or Password is wrong!";
               // Sleep(3000);
                cin.ignore();
                system("cls");
                system("color 7");
            }
        }
    } while (check_menu);
    delete[] list_student;
    delete[] list_teacher;
    delete[] list_course;
    delete[] list_class;
    delete[] list_student_course;
	system("pause");
	return 0;
}