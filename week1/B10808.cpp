#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    cin >> a;
    int num[26] = {};
    for (int i = 0; i < a.length(); i++) {
        int index = a[i] - 'a';
        num[index]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << num[i] <<' ';
    }
    return 0;
}