#include <iostream>
#include "Course.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void Course::assign_grades()
{
    string course_name, student_name, line, grade;

    cout << "Enter the course: ";
    cin >> course_name;

    string file_name = course_name + "_grade.txt";
    string ipfile = course_name + ".txt";
    ifstream inputFile(ipfile);

    if (!inputFile.is_open())
    {
        cerr << "Error opening list file" << endl;
        return;
    }

    ofstream outputFile(file_name);

    if (!outputFile.is_open())
    {
        cerr << "Error opening output file (" << file_name << ")" << endl;
        inputFile.close();
        return;
    }

    while (getline(inputFile, student_name))
    {
        cout << "Enter grade for " << student_name << " : ";
        cin >> grade;
        outputFile << student_name << '\t' << grade << endl;
    }

    cout << "Grades assigned successfully." << endl;

    inputFile.close();
    outputFile.close();
}

void Course::display_grades()
{
    cout << "Enter the course name" << endl;
    string course_name;
    cin >> course_name;
    string ipfile = course_name + "_grade.txt";
    ifstream ip(ipfile);
    if (!ip.is_open())
    {
        cerr << "grades not updated yet" << endl;
    }
    string line;
    while (getline(ip, line))
    {
        cout << line << endl;
    }
    ip.close();
}