#include <iostream>
#include <cassert>
using namespace std;

int a[9][9], cands[9][9][10], cnt = 81, candCnts[9][9];

int getUpdateValue(int y, int x) {
    int c = 0;
    int value = 0;
    for (int i = 1; i <= 9; ++i) {
        if (cands[y][x][i]) {
            value = i;
            ++c;
            if (c > 1) return 0;
        }
    }
    return value;
}

void update(int y, int x, int val) {
    if (val == 0) {
        cout << y << ',' << x << '\n';
        cout << "candCnts[y][x]: " << candCnts[y][x] << '\n';
        cout << "cands: ";
        for (int i = 1; i <= 9; ++i) {
            if (cands[y][x][i]) cout << i << ' ';
        }
        cout << '\n';
    }
    assert(val != 0);
    a[y][x] = val;
    --candCnts[y][x];
    --cnt;
    if (cnt == 0) return;

    for (int i = 0; i < 9; ++i) {
        if (cands[i][x][val] != 0) {
            cands[i][x][val] = 0;
            --candCnts[i][x];
        }
        
    }
    for (int j = 0; j < 9; ++j) {
        if (cands[y][j][val] != 0) {
            cands[y][j][val] = 0;
            -candCnts[y][j];
        }
        
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cands[y+i][x+j][val] != 0) {
                cands[y+i][x+j][val] = 0;
                --candCnts[y+i][x+j];
            }
            
        }
    }
}

int main() {
    fill(&cands[0][0][0], &cands[0][0][0] + 9 * 9 * 10, 1);
    fill(&candCnts[0][0], &candCnts[0][0] + 9 * 9, 9);
    for (int i = 0;i < 9; ++i) {
        string s; cin >> s;
        for (int j = 0; j < 9; ++j) {
            cout << i << ' ' << j << '\n';
            if (s[j] != '0') update(i, j, s[j] - '0');
        }
    }

    cout << "after init\n";
    // 재귀 안하는 버전
    while (cnt) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (a[i][j] == 0 && candCnts[i][j] == 1) update(i, j, getUpdateValue(i, j));
            }
        }
    }
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}