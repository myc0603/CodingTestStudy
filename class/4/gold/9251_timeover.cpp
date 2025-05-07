#include <iostream>
#include <vector>
using namespace std;

string s1, s2;
vector<int> a[1002];
size_t ans;

void dfs(int idx, vector<int> &lis) {
    if (idx == s2.size()) {
        ans = max(ans, lis.size());
        return;
    }

    while (idx < s2.size() && a[idx].size() < 2) {
        if (a[idx].size() == 1) {
            int x = a[idx][0];
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) lis.push_back(x);
            else *it = x;
        }
        ++idx;
    }

    // 없어도 성능상 차이 없을 듯
    if (idx == s2.size()) {
        ans = max(ans, lis.size());
        return;
    }

    for (int x : a[idx]) {
        vector<int> lisCopy = lis;
        auto it = lower_bound(lisCopy.begin(), lisCopy.end(), x);
        if (it == lisCopy.end()) lisCopy.push_back(x);
        else *it = x;
        dfs(idx + 1, lisCopy);
    }
}

int main() {
    cin >> s1 >> s2;
    for (int i = 0; i < s2.size(); ++i) {
        auto idx = s1.find(s2[i]);
        while (idx != string::npos) {
            a[i].push_back(idx + 1);
            idx = s1.find(s2[i], idx + 1);
        }
    }

    vector<int> lis;
    dfs(0, lis);
    cout << ans;
}