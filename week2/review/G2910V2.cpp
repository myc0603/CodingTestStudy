#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}
int main() {
    int n, c;
    cin >> n >> c;

    vector<pair<int, int>> freq; // val, freq
    while (n--) {
        int num; cin >> num;

        // num이 freq에 저장돼있으면 +1, 없으면 새로 추가
        bool find = false;
        for (auto &p : freq) {
            if (p.first == num) {
                p.second++;
                find = true;
                break;
            }
        }
        if (!find) {
            freq.push_back({num, 1});
        }
    }

    stable_sort(freq.begin(), freq.end(), cmp);

    string ans;
    for (const auto &p : freq) {
        for (int i = 0; i < p.second; i++) {
            ans += to_string(p.first) + ' ';
        }
    }
    cout << ans;
}