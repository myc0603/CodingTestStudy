#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20];
int tailCount, colTailCount[20];

void flipRow(int row) {
    for (int j = 0; j < n; j++) {
        if (a[row][j] == 0) {
            a[row][j] = 1;
            tailCount--;
            colTailCount[j]--;
        } else {
            a[row][j] = 0;
            tailCount++;
            colTailCount[j]++;
        }
    }
}

void flipCol(int col) {
    for (int i = 0; i < n; i++) {
        if (a[i][col] == 0) {
            a[i][col] = 1;
            tailCount--;
            colTailCount[col]--;
        } else {
            a[i][col] = 0;
            tailCount++;
            colTailCount[col]++;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'H') {
                a[i][j] = 1;
            } else {
                tailCount++;
                colTailCount[j]++;
            }
        }
    }

    int minTailCount = tailCount;
    
    int prevRow = (1 << n) - 1;
    for (int curRow = 1; curRow < (1 << n); curRow++) {
        // flip
        int flipRowIdx = prevRow ^ curRow;
        for (int i = 0; flipRowIdx; i++) {
            if (flipRowIdx % 2) {
                flipRow(i);
            }
            flipRowIdx >>= 1;
        }

        for (int col = 0; col < n; col++) {
            if (colTailCount[col] > (n/2)) {
                flipCol(col);
            }
        }
        minTailCount = min(minTailCount, tailCount);

        // int sub = 0;
        // for (int col = 0; col < n; col++) {
        //     if (colTailCount[col] > (n/2)) {
        //         sub = 2 * colTailCount[col] - n;
        //     }
        // }
        // minTailCount = min(minTailCount, tailCount - sub);

        prevRow = curRow;
    }

    cout << minTailCount << '\n';
}