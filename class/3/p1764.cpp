#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_set<string> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while (n--) {
        string s; cin >> s;
        st.insert(s);
    }

    int cnt = 0;
    vector<string> v;
    while (m--) {
        string s; cin >> s;
        if (st.find(s) != st.end()) {
            cnt++;
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    string ans;
    for (string s : v) {
        ans += s + '\n';
    }
    cout << cnt << '\n' << ans;
}