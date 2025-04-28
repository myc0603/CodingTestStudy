#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000007;
int n, m, c, a[51][51], dp[51][51][51][51];

// y,x에서 lastArcade를 마지막으로 지나왔을 때 n,m까지 arcadeCnt만큼 오락실을 지나쳐서 갈 수 있는 경우의 수
int dfs(int y, int x, int lastArcade, int arcadeCnt) {
    if (y > n || x > m) return 0;

    int &result = dp[y][x][lastArcade][arcadeCnt];
    if (result != -1) return result;

    if (a[y][x] && lastArcade > a[y][x]) return 0;
    if (a[y][x]) {
        lastArcade = a[y][x];
        arcadeCnt--;
    }
    if (arcadeCnt < 0) return 0;
    if (y == n && x == m) {
        if (arcadeCnt != 0) return 0;
        return 1;
    }

    
    result = dfs(y + 1, x, lastArcade, arcadeCnt) + dfs(y, x + 1, lastArcade, arcadeCnt);
    result %= MOD;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        int y, x;
        cin >> y >> x;
        a[y][x] = i;
    }

    memset(dp, -1, sizeof(dp));

    for (int cnt = 0; cnt <= c; cnt++) {
        cout << dfs(1, 1, 0, cnt) << ' ';
    }
}