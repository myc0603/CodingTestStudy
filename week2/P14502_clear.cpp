#include <bits/stdc++.h>
using namespace std;

int a[8][8], aCopy[8][8];
int n, m;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
vector<pair<int, int>> zeros, virus;

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inMap(ny, nx) && aCopy[ny][nx] == 0) {
                q.push({ny, nx});
                aCopy[ny][nx] = 2;
            }
        }
    }
}

void dfs(pair<int, int> p) {

    aCopy[p.first][p.second] = 2;

    for (int i = 0; i < 4; i++) {
        int ny = p.first + dy[i];
        int nx = p.second + dx[i];
        if (inMap(ny, nx) && aCopy[ny][nx] == 0) {
            dfs({ny, nx});
        }
    }
}

int tryBfs(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    copy(&a[0][0], &a[0][0] + 64, &aCopy[0][0]);

    // aCopy에 벽추가
    aCopy[p1.first][p1.second] = 1;
    aCopy[p2.first][p2.second] = 1;
    aCopy[p3.first][p3.second] = 1;

    // a를 쫙 탐색하면서 a 업데이트
    for (auto p : virus) {
        bfs(p);
        // dfs(p);
    }
    
    // a에서 빈칸 넓이 체크
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (aCopy[i][j] == 0) {
                area++;
            }
        }
    }

    return area;
}

int main() {
    cin >> n >> m;

    // 빈칸: 0 벽: 1 바이러스: 2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            cin >> a[i][j];

            if (a[i][j] == 0) {
                zeros.push_back({i, j});
            } else if (a[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    int size = zeros.size();
    int max = -1;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                int area = tryBfs(zeros[i], zeros[j], zeros[k]);
                max = max > area ? max : area;
            }
        }
    }
    cout << max << '\n';
}