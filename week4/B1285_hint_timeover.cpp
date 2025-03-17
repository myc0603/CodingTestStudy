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

        int prevCol = (1 << n) - 1;
        for (int curCol = 1; curCol < (1 << n); curCol++) {
            // flip
            int flipColIdx = prevCol ^ curCol;
            for (int j = 0; flipColIdx; j++) {
                if (flipColIdx % 2) {
                    flipCol(j);
                }
                flipColIdx >>= 1;
            }

            minTailCount = min(minTailCount, tailCount);

            prevCol = curCol;
        }
        
        prevRow = curRow;
    }

    cout << minTailCount << '\n';
}