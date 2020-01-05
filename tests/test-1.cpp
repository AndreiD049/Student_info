#include "../Student_info.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_homework(const vector<double>& hw)
{
    vector<double>::const_iterator el = hw.begin();
    while (el != hw.end())
    {
        cout << *el << (el == (hw.end() - 1) ? "" : ", ");
        el++;
    }
    cout << endl;
    return;
}

void print_student(const Student_info& s)
{
    cout << "Name: " << s.name << endl;
    cout << "Midterm: " << s.midterm << endl;
    cout << "Final: " << s.final << endl;
    cout << "Homework: ";
    print_homework(s.homework);
    cout << endl;
}

int main(int argc, char** argv)
{
    Student_info max = {"Max", 10, 20, {10, 20, 30, 40, 50, 60}};
    Student_info john = {"John", 10, 20, {10, 20, 30, 40, 50, 60}};
    Student_info cris = {"Cris", 10, 20, {10, 20, 30, 40, 50, 60}};
    Student_info jane = {"Jane", 10, 20, {10, 20, 30, 40, 50, 60}};
    vector<Student_info> students;
    students.push_back(max);
    students.push_back(john);
    students.push_back(cris);
    students.push_back(jane);

    for(vector<Student_info>::const_iterator el = students.begin();
        el != students.end(); el++)
    {
        cout << el->name << endl;    
        print_student(*el); 
    }
     
    return 0;
}