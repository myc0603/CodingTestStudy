#include <bits/stdc++.h>
using namespace std;

int n, m, a[8][8], virusVisited[8][8];
vector<pair<int, int>> viruses, blanks;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

// 바이러스 전파
int bfs(int sy, int sx) {
    int area = -1; // 시작점 제외

    queue<pair<int, int>> q;
    q.push({sy, sx});
    virusVisited[sy][sx] = 1;

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        area++;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inMap(ny, nx) && a[ny][nx] == 0 && !virusVisited[ny][nx]) {
                q.push({ny, nx});
                virusVisited[ny][nx] = 1;
            }
        }
    }

    return area;
}

int dfs(int y, int x) {
    int area = 1;

    virusVisited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx] == 0 && !virusVisited[ny][nx]) {
            area += dfs(ny, nx);
        }
    }
    return area;
}

int main() {
    cin >> n >> m;
    int safeArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] == 2) viruses.push_back({i, j});
            else if (a[i][j] == 0) {
                blanks.push_back({i, j});
                safeArea++;
            }
        }
    }
    safeArea -= 3; // 벽 3개 설치

    int ans = 0;

    for (int i = 0; i < blanks.size(); i++) {
        a[blanks[i].first][blanks[i].second] = 1;

        for (int j = i + 1; j < blanks.size(); j++) {
            a[blanks[j].first][blanks[j].second] = 1;

            for (int k = j + 1; k < blanks.size(); k++) {
                a[blanks[k].first][blanks[k].second] = 1;

                // 바이러스 전파되는 넓이를 구해서 safeArea에 빼서 안전영역 넓이 구한다.
                int temp = 0;
                for (auto virus : viruses) {
                    // temp += bfs(virus.first, virus.second);
                    temp += dfs(virus.first, virus.second) - 1;
                }
                ans = max(ans, safeArea - temp);

                memset(virusVisited, 0, sizeof(virusVisited));
                a[blanks[k].first][blanks[k].second] = 0;
            }

            a[blanks[j].first][blanks[j].second] = 0;
        }

        a[blanks[i].first][blanks[i].second] = 0;
    }

    cout << ans;
}