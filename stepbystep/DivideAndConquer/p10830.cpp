#include <bits/stdc++.h>
using namespace std;

int n;
long long b;

void printMatrix(const vector<vector<int>> &matrix) {
    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += to_string(matrix[i][j]) + ' ';
        }
        s += '\n';
    }
    cout << s;
}

vector<vector<int>> productMatrix(const vector<vector<int>> &m1, const vector<vector<int>> &m2) {
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
            result[i][j] %= 1000;
        }
    }
    return result;
}

int main() {
    cin >> n >> b;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int t = 1;
    vector<vector<int>> temp = a;
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        ans[i][i] = 1;
    }
    while (b) {
        if (b % 2) {
            ans = productMatrix(ans, temp);
            // cout << "plus ans: t= " << t << '\n';
            // printMatrix(ans); cout << '\n';
        }
        temp = productMatrix(temp, temp);
        t <<= 1;
        // cout << "squared temp: t= " << t << "\n";
        // printMatrix(temp); cout << '\n';
        b >>= 1;
    }
    printMatrix(ans);
}