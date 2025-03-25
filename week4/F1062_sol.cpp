#include <bits/stdc++.h>
using namespace std;

int n, k, words[50];
int ans;

int count(int learnedChars) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((words[i] | learnedChars) == learnedChars) cnt++;
    }
    return cnt;
}

void combi(int idx, int learnedChars, int cnt) {
    if (cnt > k || idx > 26) return;
    if (cnt == k) {
        ans = max(ans, count(learnedChars));
        return;
    }

    combi(idx + 1, learnedChars | (1 << idx), cnt + 1);
    if (idx != 'a'-'a' && idx != 'c'-'a' && idx != 'i'-'a' && idx != 'n'-'a' && idx != 't'-'a') {
        combi(idx + 1, learnedChars, cnt);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s) {
            int charIdx = c - 'a';
            words[i] |= (1 << charIdx);
        }
    }

    combi(0, 0, 0);

    cout << ans << '\n';
}