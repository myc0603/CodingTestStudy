#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct State {
    int y, x, dir, val;
};

int r, c, visited[22][22][16];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
char a[22][22];

int main() {
    int t; cin >> t;

    for (int j = 1; j <= t; ++j) {
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));

        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            string s; cin >> s;
            for (int j = 0; j < c; ++j) {
                a[i][j] = s[j];
            }
        }

        bool end = false;

        queue<State> q;
        q.push( {0, 0, 0, 0} );
        visited[0][0][0] = 1;

        while (q.size()) {
            auto cur = q.front();
            q.pop();

            bool qm = false;
            char order = a[cur.y][cur.x];
            if (order == '@') {
                end = true;
                break;
            } else if (order == '<') cur.dir = 2;
            else if (order == '>') cur.dir = 0;
            else if (order == '^') cur.dir = 1;
            else if (order == 'v') cur.dir = 3;
            else if (order == '_') cur.dir = cur.val == 0 ? 0 : 2;
            else if (order == '|') cur.dir = cur.val == 0 ? 3 : 1;
            else if (order == '?') qm = true;
            else if (order == '.');
            else if ('0' <= order && order <= '9') cur.val = order - '0';
            else if (order == '+') cur.val = (cur.val + 1) % 16;
            else if (order == '-') cur.val = (cur.val + 15) % 16;
            

            if (qm) {
                for (int i = 0; i < 4; ++i) {
                    int ny = (cur.y + dy[i] + r) % r;
                    int nx = (cur.x + dx[i] + c) % c;
                    if (visited[ny][nx][cur.val]) continue;
                    q.push( {ny, nx, i, cur.val} );
                    visited[ny][nx][cur.val] = 1;
                }
            } else {
                int ny = (cur.y + dy[cur.dir] + r) % r;
                int nx = (cur.x + dx[cur.dir] + c) % c;
                if (!visited[ny][nx][cur.val]) {
                    q.push( {ny, nx, cur.dir, cur.val} );
                    visited[ny][nx][cur.val] = 1;
                }
            }
        }

        if (end) cout << '#' << j << " YES\n";
        else cout << '#' << j << " NO\n";
    }
}