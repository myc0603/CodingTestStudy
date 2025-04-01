#include <iostream>
using namespace std;

// 너의 평점은
string subject, mark;
double credit, grade, totalGrade, totalCredit;

int main() {
    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> mark;
        if (mark == "A+") grade = 4.5;
        else if (mark == "A0") grade = 4;
        else if (mark == "B+") grade = 3.5;
        else if (mark == "B0") grade = 3;
        else if (mark == "C+") grade = 2.5;
        else if (mark == "C0") grade = 2;
        else if (mark == "D+") grade = 1.5;
        else if (mark == "D0") grade = 1;
        else if (mark == "F") grade = 0;
        else credit = 0;

        totalCredit += credit;
        totalGrade += grade * credit;
    }
    cout << totalGrade / totalCredit << '\n';
}