#include <iostream>
#include <fstream>
using namespace std;

const string filename = "input.txt";
const int N = 100000, MAX = 500000, MIN = -500000;
// const int N = 100, MAX = 500, MIN = -500; // smallinput.txt

int main() {
    ofstream fout;
    fout.open(filename);

    fout << N << '\n';
    int x1 = 0, y1 = MAX, x2 = 0, y2 = MIN;
    while (x1 < N / 2 && x2 < N / 2) {
        fout << x1 << ' ' << y1 << '\n';
        fout << x2 << ' ' << y2 << '\n';

        ++x2;
        fout << x2 << ' ' << y2 << '\n';

        ++x1; --y1;
        if (x1 == N / 2 - 1) fout << x1 << ' ' << MAX << '\n';
        else fout << x1 << ' ' << y1 << '\n';

        ++x1;
        ++x2; ++y2;
    }

    fout.close();
    
}