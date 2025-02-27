#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; n--;

    set<int> st;
    string s666 = "666";
    string str[5];
    for (int i = 0; i < 10000; i ++) {
        string s = ("0000" + to_string(i));
        s = s.substr(s.size() - 4, 4);
        // cout << "s: " << s << '\n';

        str[0] = s + s666;
        str[1] = s.substr(0, 3) + s666 + s.substr(3, 1);
        str[2] = s.substr(0, 2) + s666 + s.substr(2, 2);
        str[3] = s.substr(0, 1) + s666 + s.substr(1, 3);
        str[4] = s666 + s;

        for (int i = 0; i < 5; i++) {
            st.insert(atoi(str[i].c_str()));
            // cout << "  str[" << i << "]: " << str[i] << " -> " << atoi(str[i].c_str()) << '\n';
        }
    }

    vector<int> ans;
    // string a;
    cout << "size of set: " << st.size() << '\n'; // 22771
    for (int num : st) {
        ans.push_back(num);
        // a += to_string(num) + '\n';
    }
    // cout << a;
    cout << ans[n];

    // cout << "\n\n=======\n";
    // for (int i = 0; i < 200; i++) {
    //     cout << ans[i] << '\n';
    // }
}