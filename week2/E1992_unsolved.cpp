#include <bits/stdc++.h>
using namespace std;

string compress(vector<int> a[]) {
    int n = a[0].size();

    cout << "call compress(), print input a of size: " << n << "\n";
    for (int i = 0; i < n; i++) {
        for (int num : a[i]) {
            cout << num;
        }
        cout << '\n';
    }

    if (n == 0) return "";
    if (n == 1) {
        char c = a[0][0] + '0';
        string s = string(1, c);
        return s;
    }

    vector<int> v1[n/2], v2[n/2], v3[n/2], v4[n/2];
    for (int i = 0; i < n; i++) {
        auto start1 = a[i].begin();
        auto start2 = start1 + n/2;
        if (i < n/2) {
            v1[i].assign(start1, start2);
            v2[i].assign(start2, a[i].end());
        } else {
            v3[i-n/2].assign(start1, start2);
            v4[i-n/2].assign(start2, a[i].end());
        }
    }

    // 디버깅용 v1 ~ v4 print
    cout << "print v1\n";
    for (auto v : v1) {
        for (int num : v) {
            cout << num;
        }
        cout << '\n';
    }
    cout << "print v2\n";
    for (auto v : v2) {
        for (int num : v) {
            cout << num;
        }
        cout << '\n';
    }
    cout << "print v3\n";
    for (auto v : v3) {
        for (int num : v) {
            cout << num;
        }
        cout << '\n';
    }
    cout << "print v4\n";
    for (auto v : v4) {
        for (int num : v) {
            cout << num;
        }
        cout << '\n';
    }

    string s1 = compress(v1);
    string s2 = compress(v2);
    string s3 = compress(v3);
    string s4 = compress(v4);
    if (s1 == s2 && s2 == s3 && s3 == s4) {
        return s1;
    }
    return "(" + s1 + s2 + s3 + s4 + ")";

}

int main() {
    int n; cin >> n;

    vector<int> a[n];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s) {
            a[i].push_back(c-'0');
        }
    }

    cout << compress(a) << '\n';
}