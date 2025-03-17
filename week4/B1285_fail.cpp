#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20];
int rowTailCount[20], colTailCount[20];

void printA() {
    cout << "======\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (a[i][j] == 1 ? "H" : "T");
        }
        cout << '\n';
    }
}

void flipRow(int row) {
    // cout << "\nflipRow() row: " << row << '\n';
    for (int j = 0; j < n; j++) {
        if (a[row][j] == 0) {
            a[row][j] = 1;
            rowTailCount[row]--;
            colTailCount[j]--;
        } else {
            a[row][j] = 0;
            rowTailCount[row]++;
            colTailCount[j]++;
        }
    }
    // cout << "after fliprow:\n";
    // printA();
}

void flipCol(int col) {
    // cout << "\nflipCol() col: " << col << '\n';
    for (int i = 0; i < n; i++) {
        if (a[i][col] == 0) {
            a[i][col] = 1;
            rowTailCount[i]--;
            colTailCount[col]--;
        } else {
            a[i][col] = 0;
            rowTailCount[i]++;
            colTailCount[col]++;
        }
    }
    // cout << "after flipCol:\n";
    // printA();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'H') {
                a[i][j] = 1;
            } else {
                rowTailCount[i]++;
                colTailCount[j]++;
            }
        }
    }

    // printA();
    // cout << "rowTailCount:\n";
    // for (int i = 0; i < n; i++) {
    //     cout << rowTailCount[i] << '\n';
    // }
    // cout << "colTailCount:\n";
    // for (int j = 0; j < n; j++) {
    //     cout << colTailCount[j];
    // }
    // cout << '\n';

    bool flip = true;
    while (flip) {
        flip = false;
        // for (int idx = 0; idx < n * n; idx++) {
        //     int i = idx / n; int j = idx % n;
        //     if (rowTailCount[i] > (n/2)) {
        //         flipRow(i);
        //         flip = true;
        //         // break;
        //     }
        //     if (colTailCount[j] > (n/2)) {
        //         flipCol(j);
        //         flip = true;
        //         break;
        //     }
        // }

        for (int i = 0; i < n; i++) {
            if (rowTailCount[i] >= (n/2)) {
                flipRow(i);
                flip = true;
                // break;
            }
        }
        if (flip) {
            // printA();
            // continue;
        }

        for (int j = 0; j < n; j++) {
            if (colTailCount[j] >= (n/2)) {
                flipCol(j);
                flip = true;
                break;
            }
        }
        // printA();
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += rowTailCount[i];
    }
    cout << ans << '\n';
}