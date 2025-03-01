#include <bits/stdc++.h>
using namespace std;

string compress(string a[], int size) {
    
    if (size == 1) {
        return a[0];
    }

    string a1[size/2], a2[size/2], a3[size/2], a4[size/2];
    for (int i = 0; i < size / 2; i++) {
        a1[i] = a[i].substr(0, size / 2);
        a2[i] = a[i].substr(size / 2);
    }
    for (int i = size / 2; i < size; i++) {
        a3[i-size/2] = a[i].substr(0, size / 2);
        a4[i-size/2] = a[i].substr(size / 2);
    }

    string s1 = compress(a1, size / 2);
    string s2 = compress(a2, size / 2);
    string s3 = compress(a3, size / 2);
    string s4 = compress(a4, size / 2);

    if (s1.size() == 1 && s1 == s2 && s2 == s3 && s3 == s4) {
        return s1;
    }

    return "(" + s1 + s2 + s3 + s4 + ")";
}

int main() {
    int n; cin >> n;

    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << compress(a, n) << '\n';
}