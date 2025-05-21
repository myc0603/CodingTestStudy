#include <iostream>
#include <cstring>
using namespace std;

int n, from[102], to[102], dp[102][10][10][10][4];

int cal(int x) {
    return ((x < 0) ? x + 10 : x) % 10;
}

// dir -1, 1
int dfs(int idx, int dx, int dy, int dz, int dir) {
    if (idx == n) return 0;

    int &result = dp[idx][dx][dy][dz][dir+1];
    if (result != -1) return result;

    if (cal(from[idx] + dx) == to[idx]) {
        result = min(dfs(idx + 1, dy, dz, 0, 1), dfs(idx + 1, dy, dz, 0, -1));
        return result;
    }

    result = 1e9;
    for (int cnt = 1; cnt <= 3; ++cnt) {
        int rot = cnt * dir;
        result = min(result, dfs(idx, cal(dx + rot), dy, dz, dir) + 1);
        result = min(result, dfs(idx, cal(dx + rot), cal(dy + rot), dz, dir) + 1);
        result = min(result, dfs(idx, cal(dx + rot), cal(dy + rot), cal(dz + rot), dir) + 1);
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; ++i) {
        from[i] = s1[i] - '0';
        to[i] = s2[i] - '0';
    }

    memset(dp, -1, sizeof(dp));
    cout << min(dfs(0, 0, 0, 0, 1), dfs(0, 0, 0, 0, -1));
}