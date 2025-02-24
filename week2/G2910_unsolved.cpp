#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    int n, c;
    cin >> n >> c;
    
    // -> 벡터로 바꿔야 될거 같기도
    // n ~1000 n^2 ~100만 -> 이중 for문 괜찮을듯?
    vector<pair<int, int>> freq; // 숫자, 숫자가 나온 횟수
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        bool find = false;
        cout << "input num: " << num << '\n';
        for (auto p : freq) {
            if (p.first == num) {
                p.second++; // 이거 왜 안되지?
                find = true;
                cout << "    find, p.first: " << p.first << ", p.second: " << p.second << '\n';
                break;
            }
        }
        // cout << "find: " << find << '\n';
        if (!find) {
            freq.push_back({num, 1});
            cout << "    not found. num: " << num << '\n';
        }
    }

    for (auto p : freq) {
        cout << p.first << ':' << p.second << '\n';
    }

    stable_sort(freq.begin(), freq.end(), comp);
    string ans = "";
    for (auto p : freq) {
        int cnt = p.second;
        while (cnt--) {
            ans += p.first + '0';
            ans += ' ';
        }
    }
    cout << ans << '\n';
}
// 1 1 2 2 / 2 2 1 1