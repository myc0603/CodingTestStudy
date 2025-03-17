#include <bits/stdc++.h>
using namespace std;

const int n = 4;
string a[n] = {"사과", "딸기", "포도", "배"};

void go(int num) {
    string result;
    for (int i = 0; i < 4; i++) {
        if (num & (1 << i)) {
            result += a[i] + ' ';
        }
    }
    cout << result << '\n';
}

int main() {
    for (int i = 0; i < (1 << n); i++) {
        string result;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                result += a[j] + " ";
            }
        }
        cout << result << '\n';
    }

    cout << "============\n";

    for (int i = 0; i < n; i++) {
        go(1 | (1 << i));
    }
}