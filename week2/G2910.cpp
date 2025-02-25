#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    int n, c;
    cin >> n >> c; // c: 수열 숫자들의 최대 범위...를를 어따쓰지?
    
    // n ~1000 n^2 ~100만 -> 이중 for문 괜찮을듯?
    vector<pair<int, int>> freq; // 숫자, 숫자가 나온 횟수
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        bool find = false;
        cout << "input num: " << num << '\n';

        for (auto &p : freq) { // p는 freq안에 있는 pair를 직접 참조하는게 아니라 복사한 값임 p.second++; 같은거 안됨됨
        // for (int j = 0; j < n; j++) { // out of bounds
            if (p.first == num) {
                p.second++;
                find = true;
                cout << "    find, freq[i].first: " << freq[i].first << ", freq[i].second: " << freq[i].second << '\n';
                break;
            }
        }
        // cout << "find: " << find << '\n';
        if (!find) {
            freq.push_back({num, 1}); // if 안하면 중복
        }
        // cout << "    not found. num: " << num << '\n';
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
            // cout << p.first << ' ';
        }
    }
    cout << ans << '\n';
}
// 1 1 2 2 / 2 2 1 1