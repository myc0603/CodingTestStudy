#include <iostream>
#include <map>
using namespace std;

// 너의 평점은
string subject, mark;
double credit, grade, totalGrade, totalCredit;

int main() {
    map<string, double> gradeMap;
    gradeMap["A+"] = 4.5;
    gradeMap["A0"] = 4;
    gradeMap["B+"] = 3.5;
    gradeMap["B0"] = 3;
    gradeMap["C+"] = 2.5;
    gradeMap["C0"] = 2;
    gradeMap["D+"] = 1.5;
    gradeMap["D0"] = 1;
    gradeMap["F"] = 0;
    gradeMap["P"] = 0;
    
    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> mark;
        grade = gradeMap[mark];
        if (mark == "P") credit = 0;

        totalCredit += credit;
        totalGrade += grade * credit;
    }
    cout << totalGrade / totalCredit << '\n';
}