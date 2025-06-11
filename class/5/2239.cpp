#include <iostream>
using namespace std;

int a[9][9], filled[9][9];

void printA() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) cout << a[i][j];
        cout << '\n';
    }
}

void update(int i, int j) {
    int possible[10];
    fill(possible, possible + 10, 1);

    for (int row = 0; row < 9; ++row) {
        if (filled[row][j]) {
            possible[a[row][j]] = 0;
        }
    }
    for (int col = 0; col < 9; ++col) {
        if (filled[i][col]) {
            possible[a[i][col]] = 0;
        }
    }
    // i, j가 포함된 3 X 3 정사각형
    int rowStart = i - (i % 3);
    int colStart = j - (j % 3);
    for (int row = rowStart; row <= rowStart + 2; ++row) {
        for (int col = colStart; col <= colStart + 2; ++col) {
            if (filled[row][col]) {
                possible[a[row][col]] = 0;
            }
        }
    }

    for (int val = 1; val <= 9; ++val) {
        if (possible[val]) {
            a[i][j] = val;
            filled[i][j] = 1;
            
            // 다음꺼 찾아서 업데이트
            int ni = -1, nj = -1;
            bool allCompleted = true;
            for (int next = i * 9 + j + 1; next < 81; ++next) {
                if (!filled[next / 9][next % 9]) {
                    ni = next / 9;
                    nj = next % 9;
                    allCompleted = false;
                    break;
                }
            }
            if (allCompleted) {
                printA();
                exit(0);
            } else {
                update(ni, nj);
                a[ni][nj] = 0;
                filled[ni][nj] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; ++i) {
        string s; cin >> s;
        for (int j = 0; j < 9; ++j) {
            a[i][j] = s[j] - '0';
            if (a[i][j]) filled[i][j] = 1;
        }
    }

    bool flag = false;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!filled[i][j]) {
                flag = true;
                update(i, j);
                break;
            }
        }
        if (flag) break;
    }
}