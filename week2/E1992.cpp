#include <bits/stdc++.h>
using namespace std;

string compress(vector<int> a[]) {
    int n = a[0].size();

    if (n == 0) return ""; // 필요없음
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

    string s1 = compress(v1);
    string s2 = compress(v2);
    string s3 = compress(v3);
    string s4 = compress(v4);
    if (s1 == s2 && s2 == s3 && s3 == s4 && s1.size() == 1) {
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