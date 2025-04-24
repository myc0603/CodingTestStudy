#include <iostream>
#include <algorithm>
using namespace std;

int t, w, tree[1003], dp[1003][2][31];

int jadu(int sec, int pos, int moveCnt) {
    if (moveCnt > w) return -1e9;
    if (sec == t) return pos == tree[sec];

    int &result = dp[sec][pos][moveCnt];
    if (result != -1) return result;

    int moving = jadu(sec + 1, pos, moveCnt);
    int staying = jadu(sec + 1, pos ^ 1, moveCnt + 1);
    result = max(moving, staying) + (pos == tree[sec]);
    return result;
}

int main() {
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        cin >> tree[i];
        tree[i]--;
    }

    fill(&dp[0][0][0], &dp[0][0][0] + 1003 * 2 * 31, -1);
    cout << max(jadu(1, 0, 0), jadu(1, 1, 1));
}