#include <bits/stdc++.h>
using namespace std;

string mkSuffix(int r) {
    if (6 <= r && r <= 15) {
        return "666" + to_string(r-6);
    }
    if (r < 6) {
        return to_string(r) + "666";
    }
    return to_string(r - 9) + "666";
}

void nth666(int n) {
    n--;
    string pre = n < 19 ? "" : to_string(n / 19);
    string suf = n == 0 ? "666" : mkSuffix(n % 19);
    cout << pre + suf << '\n';
}

int main() {
    // int n; cin >> n;

    // for (int i = 1; i <= 200; i++) {
    //     nth666(i);
    // }

    set<int> st;
    string s1 = "1";
    string s3 = "3";
    string s2 = "2";
    st.insert(atoi(s1.c_str()));
    st.insert(atoi(s2.c_str()));
    st.insert(atoi(s3.c_str()));
    for (auto s : st) {
        cout << s << '\n';
    }
}