#include <iostream>
#include <queue>
using namespace std;

struct State {
    int i, a, b, c;
};

const int INF = 1e9;
int n, dp[102][10][10][10], ans = INF;
string from, to;

int mod(int x) {
    return (x + 10) % 10;
}

int main() {
    cin >> n >> from >> to;

    fill(&dp[0][0][0][0], &dp[0][0][0][0] + 102 * 10 * 10 * 10, INF);
    dp[0][0][0][0] = 0;

    queue<State> q;
    q.push( {0, 0, 0, 0} );

    while (q.size()) {
        int cur = q.front().i;
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if (cur == n) {
            ans = min(ans, dp[cur][a][b][c]);
            continue;
        }
        if (mod(from[cur] - '0' + a) == to[cur] - '0') {
            if (dp[cur+1][b][c][0] == INF) {
                dp[cur+1][b][c][0] = dp[cur][a][b][c];
                q.push( {cur + 1, b, c, 0} );
            }
            continue;
        }


        for (int len = 1; len <= 3 && cur + len <= n; ++len) {
            for (int rot = -3; rot <= 3; ++rot) {
                if (rot == 0) continue;

                int na = mod(a + rot);
                int nb = len >= 2 ? mod(b + rot) : b;
                int nc = len >= 3 ? mod(c + rot) : c;

                if (dp[cur][na][nb][nc] == INF) {
                    dp[cur][na][nb][nc] = dp[cur][a][b][c] + 1;
                    q.push( {cur, na, nb, nc} );
                }
         
                // 아래대로 하면 왜 안되는지 모르겠음
                // if (mod(from[cur] - '0' + na) == to[cur] - '0') {
                //     if (dp[cur+1][nb][nc][0] == INF) {
                //         dp[cur+1][nb][nc][0] = dp[cur][a][b][c] + 1;
                //         q.push( {cur + 1, nb, nc, 0} );
                //     }
                // } else {
                //     if (dp[cur][na][nb][nc] == INF) {
                //         dp[cur][na][nb][nc] = dp[cur][a][b][c] + 1;
                //         q.push( {cur, na, nb, nc} );
                //     }
                // }
            }
        }
    }

    cout << ans;
}