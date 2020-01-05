#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;
using std::to_string;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0;
         i != students.size(); i++)
    {
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');
             
            try
            {
                double final_grade = grade(students[i]);
                streamsize prec = cout.precision();

                cout << setprecision(3) << final_grade
                     << setprecision(prec);
            }
            catch (domain_error& e)
            {
                cout << e.what();
            }
            cout << endl;
    }

    vector<Student_info> failed = extract_fail(students);

    cout << endl << "Following students failed their exams:" << endl;
    for (vector<Student_info>::size_type i = 0; i != failed.size(); i++)
    {
        cout << "\t" << to_string(i + 1) + ". " << failed[i].name << endl;
    }

    return 0;
}