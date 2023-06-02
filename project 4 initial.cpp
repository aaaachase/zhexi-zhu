﻿#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

class Object
{
public:
    string number;
    string name;
};

class Student :public Object// Student class
{
public:
    string sex;
};

class Course :public Object// Class course
{
public:
    double credit; // Credits
};

class Selection// Select a class
{
public:
    Selection();
    string stuId; // Student number
    string courseId; // Course number
    int score; // Score
};
Selection::Selection()
{
    score = -1;
}

class Manager// Management class
{
public:
    Student students[100]; // Studentdent structure
    int studentsSize; // Number of students
    Course courses[100]; // Course structure
    int coursesSize; // Number of courses
    Selection courseSelections[100]; // Course selection structure
    int courseselectionsSize;

    Manager(); // constructor
    ~Manager(); // constructor

    void rolemenu(); // Main menu
    void roleOperation(); // Main operation

    void managerMenu(); // Administrator operation menu
    void managerOperation(); // Administrator operation interface

    void studentMenu(); // Student operation menu
    void studentOperation(); // Student operation interface


    void browseCourse(); // Display course information
    void browseStudent(); // Display student information

    void addCourse(); // Add course information
    void addStudent(); // Add student information

    void modifyCourse(); // Modify the course information
    void modifyStudent(); // Modify student information

    void deleteCourse(); // Delete the course information
    void deleteStudent(); // Delete student information

    void searchCourceInfo();
    void searchStudentInfo(); // View personal information by student ID
    void searchSelectInfoByStudentNumber(string id); // Check the course selection information by student ID

    void studentChooseCourse(); // Choose courses

    bool courseIdHasBeenAdded(string id); // Whether the course number already exists
    bool courseNameHasBeenAdded(string name); // Whether the course name already exists
    bool stuIdHaveBeenAdded(string id); // Check whether the student ID already exists
    bool courseHasBeenSelected(Selection se); // Student ID Indicates whether the course ID already exists

    string getCourseNameByCourseId(string id); // Obtain the course name by course number

    void saveAllInfo(); // Save the course information
    void readAllInfo(); // Read the course file information to the program

};



//main function
int main()
{
    Manager manager;
    manager.roleOperation();

    return 0;
}



Manager::Manager()
{
    studentsSize = coursesSize = courseselectionsSize = 0;
    readAllInfo(); // Read the course file information to the program
}
Manager::~Manager()
{
    saveAllInfo(); // Save the course information
}
void Manager::rolemenu()//Main menu
{
    std::cout << "------------------------------------------------" << endl;
    std::cout << "|     University Student Management System     |" << endl;
    std::cout << "------------------------------------------------" << endl;
    std::cout << "|1: Administrator        |2: Student           |" << endl;
    std::cout << "------------------------------------------------" << endl;
    std::cout << "|3: exits the system                           |" << endl;
    std::cout << "------------------------------------------------" << endl;
    std::cout << "Please enter your permissions: ";
}

void Manager::roleOperation()//Master operation
{
    int choice;
    bool loop = true;
    while (loop)
    {
        rolemenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            managerOperation();
            break;
        case 2:
            studentOperation();
            break;
        case 3:
            loop = false;
            break;
        default:
            std::cout << "Input error, please re-enter!" << endl;
            break;
        }
    }
}

void Manager::managerMenu()// Administrator operation menu, browse, add, modify, delete course information and student information;
{
    std::cout << "--------------------------------------------------------------" << endl;
    std::cout << "|            University Student Management System             |" << endl;
    std::cout << "--------------------------------------------------------------" << endl;
    std::cout << "|1: Browse course information  |2: Browse student information |" << endl;
    std::cout << "--------------------------------------------------------------" << endl;
    std::cout << "|3: Add course information     |4: Add student information    |" << endl;
    std::cout << "--------------------------------------------------------------" << endl;
    std::cout << "|5: Modify course information  |6: Modify student information |" << endl;
    std::cout << "--------------------------------------------------------------" << endl;
    std::cout << "|7: Delete course information  |8: Delete student information |" << endl;
    std::cout << "--------------------------------------------------------------" << endl;
    std::cout << "|9: search course information |10: search student information |" << endl;
    std::cout << "--------------------------------------------------------------" << endl;
    std::cout << "|11: Return to the previous menu                              |" << endl;
    std::cout << "--------------------------------------------------------------" << endl;
    std::cout << "Please enter your choice:" << endl;
}

void Manager::managerOperation()//Administrator operation interface
{
    int choice;
    bool loop = true;
    while (loop)
    {
        managerMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            browseCourse(); // Display course information
            break;
        case 2:
            browseStudent(); // Display student information
            break;
        case 3:
            addCourse(); // Add course information
            break;
        case 4:
            addStudent(); // Add student information
            break;
        case 5:
            modifyCourse(); // Modify the course information
            break;
        case 6:
            modifyStudent(); // Modify student information
            break;
        case 7:
            deleteCourse(); // Delete the course information
            break;
        case 8:
            deleteStudent(); // Delete student information
            break;
        case 9:
            searchCourceInfo();
            break;
        case 10:
            searchStudentInfo();
            break;
        case 11:
            loop = false;
            break;
        default:
            std::cout << "Input error, please re-enter!" << endl;
            break;
        }
    }
}

void Manager::studentMenu()// Student action menu
{
    std::cout << "--------------------------------------------------------" << endl;
    std::cout << "|        University Student Management System          |" << endl;
    std::cout << "--------------------------------------------------------" << endl;
    std::cout << "|1: search personal information |2: select new courses |" << endl;
    std::cout << "--------------------------------------------------------" << endl;
    std::cout << "|3: Return to the previous menu                        |" << endl;
    std::cout << "--------------------------------------------------------" << endl;
    std::cout << "Please enter your choice:" << endl;
}

void Manager::studentOperation()// Student operation interface
{
    int choice;
    bool loop = true;
    while (loop)
    {
        studentMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            searchStudentInfo();
            break;
        case 2:
            studentChooseCourse(); // Choose courses
            break;
        case 3:
            loop = false;
            break;
        default:
            std::cout << "Input error, please re-enter!" << endl;
            break;
        }
    }
}

bool Manager::courseIdHasBeenAdded(string id)// Indicates whether the course number exists
{
    for (int i = 0; i < coursesSize; i++)
    {
        if (courses[i].number == id)
            return true;
    }
    return false;
}

bool Manager::courseNameHasBeenAdded(string name)
{
    for (int i = 0; i < coursesSize; i++)
    {
        if (courses[i].name == name)
            return true;
    }
    return false;
}

void Manager::addCourse()// Add course information
{
    string id;
    string name;
    std::cout << "Please enter the course number :";
    std::cin >> id;
    if (courseIdHasBeenAdded(id))
    {
        std::cout << "The course number has been added!" << endl;
        return;
    }
    std::cout << "Please enter the course name :";
    std::cin >> name;
    if (courseNameHasBeenAdded(name))
    {
        std::cout << "The course name has been added!" << endl;
        return;
    }
    std::cout << "Please enter course credit :";
    std::cin >> this->courses[coursesSize].credit;
    this->courses[coursesSize].number = id;
    this->courses[coursesSize].name = name;
    coursesSize++;
    std::cout << "The course was added successfully!" << endl;
}

void Manager::browseCourse()// Displays course information
{
    std::cout << "Course number " << setw(20) << "Course name"
        << setw(20) << "Course credit" << endl;
    for (int i = 0; i < coursesSize; i++)
    {
        std::cout << courses[i].number << setw(20) << courses[i].name
            << setw(20) << courses[i].credit << endl;
    }
}

void Manager::deleteCourse()// Deletes course information
{
    string id;
    bool falg = false;
    std::cout << "Please enter the course number you want to delete: ";
    std::cin >> id;
    if (!courseIdHasBeenAdded(id))
    {
        std::cout << "The course number does not exist!" << endl;
        return;
    }
    for (int i = 0; i < coursesSize; i++)
    {
        if (id == courses[i].number)
        {
            for (; i < coursesSize - 1; i++)
            {
                courses[i] = courses[i + 1];
            }
            coursesSize--;
            falg = true;
            break;
        }
    }
    if (falg)
        std::cout << "The course deletion was successful!" << endl;
}

void Manager::searchCourceInfo()
{
    string id;
    std::cout << "Please enter the course number: ";
    std::cin >> id;
    if (!courseIdHasBeenAdded(id))
    {
        std::cout << "The course number does not exist!" << endl;
        return;
    }
    for (int i = 0; i < coursesSize; i++)
    {
        if (id == courses[i].number)
        {
            std::cout << "Course number " << setw(20) << " Course name"
                << setw(20) << " Course credit" << endl;
            std::cout << courses[i].number << setw(20) << courses[i].name
                << setw(20) << courses[i].credit << endl;
            break;
        }
    }
}

void Manager::modifyCourse()// Modify course information
{
    string id;
    int choice;
    std::cout << "Please enter the course number: ";
    std::cin >> id;
    if (!courseIdHasBeenAdded(id))
    {
        std::cout << "The course number does not exist!" << endl;
        return;
    }
    for (int i = 0; i < coursesSize; i++)
    {
        if (id == courses[i].number)
        {
            std::cout << "Would you like to change the course number? (1- yes  2- No) : ";
            std::cin >> choice;
            if (choice == 1)
            {
                std::cout << "Please enter the revised course number: ";
                while (true)
                {
                    std::cin >> id;
                    if (courseIdHasBeenAdded(id))
                    {
                        std::cout << "The course number already exists, please re-enter:" << endl;
                    }
                    else
                    {
                        courses[i].number = id;
                        break;
                    }
                }
            }
            std::cout << "Would you like to change the course name? (1- yes  2- No) : ";
            std::cin >> choice;
            if (choice == 1)
            {
                std::cout << "Please enter the revised course name: ";
                std::cin >> courses[i].name;
            }
            std::cout << "Would you like to change the course credit? (1- yes  2- No) : ";
            std::cin >> choice;
            if (choice == 1)
            {
                std::cout << "Please enter the revised course credit: ";
                std::cin >> courses[i].credit;
            }
            std::cout << "Modified successfully!" << endl;
            break;
        }
    }
}

bool Manager::stuIdHaveBeenAdded(string id)// Whether the student ID exists
{
    int i;
    for (i = 0; i < studentsSize; i++)
    {
        if (students[i].number == id)
            return true;
    }
    return false;
}

void Manager::addStudent()// Add student information
{
    string id;
    int choice;
    std::cout << "Please enter the student number you want to add: ";
    std::cin >> id;
    if (stuIdHaveBeenAdded(id))
    {
        std::cout << "Student number already exists!" << endl;
        return;
    }

    this->students[studentsSize].number = id;
    std::cout << "Please enter the student name you want to add : ";
    std::cin >> this->students[studentsSize].name;
    std::cout << "Please enter the student sex you want to add : ";
    std::cin >> this->students[studentsSize].sex;
    studentsSize++;

    std::cout << "Whether to add grades for courses taken? (1- yes  2- No) : ";
    std::cin >> choice;
    if (choice == 2)
        return;
    Selection st;
    st.stuId = id;
    while (1)
    {
        std::cout << "Please enter the number of the course you have taken: ";
        std::cin >> st.courseId;
        if (!courseIdHasBeenAdded(st.courseId))
            std::cout << "Course number does not exist!" << endl;
        else if (courseHasBeenSelected(st))
            cout << "You have enrolled in the course!" << endl;
        else
        {
            std::cout << "Please enter the score of the course you have taken: ";
            std::cin >> st.score;
            courseSelections[courseselectionsSize] = st;
            courseselectionsSize++;
        }
        std::cout << "Whether to add more? (1- yes  2- No) : ";
        std::cin >> choice;
        if (choice == 2)
            break;
    }
    std::cout << "Student information added successfully!" << endl;
}

void Manager::browseStudent()// Displays student information
{
    std::cout << "Student number" << setw(20) << "Student name" << setw(20) << "Student sex" << endl;
    for (int i = 0; i < studentsSize; i++)
    {
        std::cout << students[i].number << setw(20) << students[i].name <<
            setw(20) << students[i].sex << endl;
    }
}

void Manager::deleteStudent()// Deletes student information
{
    string id;
    std::cout << "Please enter the student number you want to delete: ";
    std::cin >> id;
    if (!stuIdHaveBeenAdded(id))
    {
        cout << "Student number does not exist!" << endl;
        return;
    }
    for (int i = 0; i < studentsSize; i++)
    {
        if (id == students[i].number)
        {
            for (; i < studentsSize - 1; i++)
            {
                students[i] = students[i + 1];
            }
            studentsSize--;
            std::cout << "Student information deleted successfully!" << endl;
            break;
        }
    }
}

void Manager::modifyStudent()// Modify student information
{
    string id;
    std::cout << "Please enter student number: ";
    std::cin >> id;
    int ch;
    for (int i = 0; i < studentsSize; i++)
    {
        if (id == students[i].number)
        {
            std::cout << "Do you want to change the student number? (1- yes, 2- No) : ";
            std::cin >> ch;
            if (ch == 1)
            {
                while (1)
                {
                    std::cout << "Please enter the revised student number: ";
                    std::cin >> id;
                    if (stuIdHaveBeenAdded(id))
                    {
                        std::cout << "Student number already exists! Please retype!" << endl;
                    }
                    else
                    {
                        students[i].number = id;
                        break;
                    }
                }
            }
            std::cout << "Do you want to change your name? (1- yes, 2- No) : ";
            std::cin >> ch;
            if (ch == 1)
            {
                std::cout << "Please enter the modified name: ";
                std::cin >> students[i].name;
            }
            std::cout << "Do you want to change your sex? (1- yes, 2- No) : ";
            std::cin >> ch;
            if (ch == 1)
            {
                std::cout << "Please enter the modified sex: ";
                std::cin >> students[i].sex;
            }
            std::cout << "Modified successfully!" << endl;
            return;
        }
    }
    std::cout << "Not found!" << endl;
}

void Manager::studentChooseCourse()//Choose courses
{
    Selection st;
    string id;
    int choice;
    std::cout << "Please enter your student number: ";
    std::cin >> id;
    if (!stuIdHaveBeenAdded(id))
    {
        cout << "The student number does not exist!" << endl;
        return;
    }
    st.stuId = id;
    for (int i = 0; i < studentsSize; i++)
    {
        if (st.stuId == students[i].number)// If the student ID is the same
        {
            while (true)
            {
                while (true)
                {
                    std::cout << "Please enter the course number: ";
                    std::cin >> st.courseId;
                    if (courseIdHasBeenAdded(st.courseId))// Whether the course number already exists
                    {
                        if (courseHasBeenSelected(st)) {// If the student number and course number exist
                            std::cout << "Sorry, you can't repeat the course!" << endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        std::cout << "Course number does not exist!" << endl;
                    }
                    std::cout << "Do you want to continue taking courses? (1- yes  2- No):";
                    std::cin >> choice;
                    if (choice == 2)
                        return;
                }
                courseSelections[courseselectionsSize] = st;
                courseselectionsSize++;
                std::cout << "Do you want to continue taking courses? (1- yes  2- No):";
                std::cin >> choice;
                if (choice == 2)
                    break;
            }
            break;
        }
    }
}

void Manager::searchStudentInfo()
{
    std::cout << "Please enter student number: ";
    string id;
    std::cin >> id;
    std::cout << "student number " << setw(20) << "student name" << endl;
    for (int i = 0; i < studentsSize; i++)
    {
        if (students[i].number == id)
        {
            std::cout << students[i].number << setw(20) << students[i].name << endl;
            break;
        }
    }
    searchSelectInfoByStudentNumber(id);
}

string Manager::getCourseNameByCourseId(string id)//Get the course name by course number
{
    for (int i = 0; i < coursesSize; i++)
    {
        if (id == courses[i].number)
            return courses[i].name;
    }
    return "";
}

void Manager::searchSelectInfoByStudentNumber(string id)//View course selection information by student ID
{
    std::cout << "course number " << setw(20)
        << "course name " << setw(20) << "course score" << endl;
    for (int i = 0; i < courseselectionsSize; i++)
    {
        if (courseSelections[i].stuId == id)//If the student numbers are equal
        {
            std::cout << courseSelections[i].courseId << setw(20)
                << getCourseNameByCourseId(courseSelections[i].courseId) << setw(20);
            if (courseSelections[i].score == -1)
                std::cout << "untested";
            else
                std::cout << courseSelections[i].score;
            cout << endl;
        }
    }
}

bool Manager::courseHasBeenSelected(Selection se)
{
    for (int i = 0; i < courseselectionsSize; i++)
    {
        if (se.stuId == courseSelections[i].stuId && se.courseId == courseSelections[i].courseId)//If the student number has already taken the course
        {
            return true;
        }
    }
    return false;
}

void Manager::saveAllInfo()//Save  information
{
    ofstream out("allCourse.txt");
    for (int i = 0; i < coursesSize; i++)
    {
        out << courses[i].number << setw(20) << courses[i].name << setw(20) << courses[i].credit << endl;
    }
    out.close();
    out.open("student.txt");
    for (int i = 0; i < studentsSize; i++)
    {
        out << students[i].number << setw(20) << students[i].name << setw(20) << students[i].sex << endl;
    }
    out.close();
    out.open("courseSelection.txt");
    for (int i = 0; i < courseselectionsSize; i++)
    {
        out << courseSelections[i].stuId << setw(20) << courseSelections[i].courseId << setw(20) << courseSelections[i].score << endl;
    }
    out.close();
}

void Manager::readAllInfo()//Read the  file information to the program
{
    ifstream in("allCourse.txt");
    if (in)
    {
        while (true)
        {
            in >> courses[coursesSize].number;
            if (in.eof())
                break;
            in >> courses[coursesSize].name >> courses[coursesSize].credit;
            coursesSize++;
        }
        in.close();
    }
    in.open("student.txt");
    if (in)
    {
        while (true)
        {
            in >> students[studentsSize].number;
            if (in.eof())
                break;
            in >> students[studentsSize].name >> students[studentsSize].sex;
            studentsSize++;
        }
        in.close();
    }
    in.open("courseSelection.txt");
    if (in)
    {
        while (true)
        {
            in >> courseSelections[courseselectionsSize].stuId;
            if (in.eof())
                break;
            in >> courseSelections[courseselectionsSize].courseId >> courseSelections[courseselectionsSize].score;
            courseselectionsSize++;
        }
        in.close();
    }
}
