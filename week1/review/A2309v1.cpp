#include <bits/stdc++.h>
using namespace std;

void printAns(int* a, int i, int j) {
    for (int k = 0; k < 9; k++) {
        if (k == i || k == j) {
            continue;
        }
        cout << a[k] << '\n';
    }
}

int main() {
    int a[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+9);
    for (int i = 0; i < 9; i++) {
        for (int j= 0; j < 9; j++) {
            if (sum - a[i] - a[j] == 100) {
                printAns(a, i, j);
                return 0;
            }
        }
    }
}