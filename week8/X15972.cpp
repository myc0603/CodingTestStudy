#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State {
    int height, y, x;
};

struct cmp {
    bool operator()(const State &s1, const State &s2) {
        return s1.height > s2.height;
    }
};

int n, m, h, water[1005][1005], widthHoles[1005][1005], lengthHoles[1005][1005];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int adjHoleHeight(int y, int x, int ny, int nx) {
    if (x == nx) return widthHoles[max(y, ny)][x];
    return lengthHoles[y][max(x, nx)];
}

void dijkstra(vector<State> v) {
    priority_queue<State, vector<State>, cmp> pq;
    for (auto s : v) pq.push(s);

    while (pq.size()) {
        int height = pq.top().height;
        int y = pq.top().y;
        int x = pq.top().x;
        pq.pop();

        if (height > water[y][x]) continue;

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // height는 cur의 높이, newHeight는 다음 인접 칸의 높이.
            // 다음 인접칸의 현재높이는 중요치 않은듯....? 차피 밑에 if문에서 현재높이랑 비교
            int holeHeight = adjHoleHeight(y, x, ny, nx);
            if (holeHeight == -1) continue;
            int newHeight = max(height, holeHeight);

            if (water[ny][nx] > newHeight) {
                water[ny][nx] = newHeight;
                pq.push( {newHeight, ny, nx} );
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> widthHoles[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m + 1; ++j) {
            cin >> lengthHoles[i][j];
        }
    }

    fill(&water[0][0], &water[0][0] + 1005 * 1005, h);
    for (int i = 0; i <= n + 1; ++i) water[i][0] = 0;
    for (int i = 0; i <= n + 1; ++i) water[i][m+1] = 0;
    for (int j = 0; j <= m + 1; ++j) water[0][j] = 0;
    for (int j = 0; j <= m + 1; ++j) water[n+1][j] = 0;
    
    vector<State> v;
    for (int i = 1; i <= n; ++i) {
        if (lengthHoles[i][1] != -1) {
            water[i][1] = lengthHoles[i][1];
            v.push_back( {water[i][1], i, 1} );
        }

        if (lengthHoles[i][m+1] != -1) {
            water[i][m] = lengthHoles[i][m+1]; //
            v.push_back( {water[i][m], i, m} );
        }
    }
    for (int j = 1; j <= m; ++j) {
        if (widthHoles[1][j] != -1) {
            water[1][j] = min(water[1][j], widthHoles[1][j]);
            v.push_back( {water[1][j], 1, j} );
        }

        if (widthHoles[n+1][j] != -1) {
            water[n][j] = min(water[n][j], widthHoles[n+1][j]);
            v.push_back( {water[n][j], n, j} );
        }
    }

    dijkstra(v);

    int total = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            total += water[i][j];
        }
    }
    cout << total;
}