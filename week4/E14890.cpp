#include <bits/stdc++.h>
using namespace std;

int n, l, a[100][100];

bool rowCheck(int row) {
    int flatLength[100] = {};
    int tempFlatLength = 1;
    vector<int> v;

    int prev = a[row][0];
    v.push_back(0);
    for (int col = 1; col < n; col++) {
        int cur = a[row][col];
        if (abs(prev - cur) >= 2) return false;
        if (prev == cur) {
            tempFlatLength++;
        }
        else {
            for (int updateIdx : v) {
                flatLength[updateIdx] = tempFlatLength;
            }
            tempFlatLength = 1;
            v.clear();
        }
        v.push_back(col);
        prev = cur;
    }
    for (int updateIdx : v) {
        flatLength[updateIdx] = tempFlatLength;
    }

    bool rampInstalled[100] = {};
    prev = a[row][0];
    for (int col = 1; col < n; col++) {
        int cur = a[row][col];
        if (prev < cur) {
            if (flatLength[col-1] < l) return false;
            for (int i = col - l; i < col; i++) {
                if (rampInstalled[i]) return false;
                rampInstalled[i] = true;
            }
        }
        if (prev > cur) {
            if (flatLength[col] < l) return false;
            for (int i = col; i < col + l; i++) {
                rampInstalled[i] = true;
            }
        }

        prev = cur;
    }

    return true;
}

bool colCheck(int col) {
    int flatLength[100] = {};
    int tempFlatLength = 1;
    vector<int> v;

    int prev = a[0][col];
    v.push_back(0);
    for (int row = 1; row < n; row++) {
        int cur = a[row][col];
        if (abs(prev - cur) >= 2) return false;
        if (prev == cur) {
            tempFlatLength++;
        }
        else {
            for (int updateIdx : v) {
                flatLength[updateIdx] = tempFlatLength;
            }
            tempFlatLength = 1;
            v.clear();
        }
        v.push_back(row);
        prev = cur;
    }
    for (int updateIdx : v) {
        flatLength[updateIdx] = tempFlatLength;
    }

    bool rampInstalled[100] = {};
    prev = a[0][col];
    for (int row = 1; row < n; row++) {
        int cur = a[row][col];
        if (prev < cur) {
            if (flatLength[row-1] < l) return false;
            for (int i = row - l; i < row; i++) {
                if (rampInstalled[i]) return false;
                rampInstalled[i] = true;
            }
        }
        if (prev > cur) {
            if (flatLength[row] < l) return false;
            for (int i = row; i < row + l; i++) {
                rampInstalled[i] = true;
            }
        }

        prev = cur;
    }

    return true;
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int row = 0; row < n; row++) {
        if (rowCheck(row)) cnt++;
    }
    for (int col = 0; col < n; col++) {
        if (colCheck(col)) cnt++;
    }
    cout << cnt << '\n';
}