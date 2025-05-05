#include <iostream>
using namespace std;

int requiredSticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string minDp[102], maxDp[102];

bool operator<(const string &s1, const string &s2) {
    if (s1.size() == s2.size()) {
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) continue;
            return s1[i] < s2[i];
        }
        return false; // s1, s2가 똑같은 경우: 생략 가능
    }
    return s1.size() < s2.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(minDp, minDp + 102, string(50, '9'));
    for (int i = 1; i <= 9; ++i) {
        int cnt = requiredSticks[i];
        minDp[cnt] = min(minDp[cnt], to_string(i));
    }

    for (int j = 2; j <= 100; ++j) {
        for (int i = 0; i <= 9; ++i) {
            int cnt = requiredSticks[i];
            if (j < cnt) continue;

            string s = minDp[j-cnt] + to_string(i);
            if (s < minDp[j]) minDp[j] = s;

            s = maxDp[j-cnt] + to_string(i);
            if (maxDp[j] < s) maxDp[j] = s;
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << minDp[n] << ' ' << maxDp[n] << '\n';
    }
}