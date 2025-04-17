#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int WALL = 6;
int n, m, a[10][10], blind_area = 100;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
vector<pair<int, int>> cctv_positions;
vector<vector<vector<int>>> v = {
    {},
    { {0}, {1}, {2}, {3} },
    { {0, 2}, {1, 3} },
    { {0, 1}, {1, 2}, {2, 3}, {3, 0} },
    { {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} },
    { {0, 1, 2, 3} }
};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int get_blind_area() {
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) area++;
        }
    }
    return area;
}

void check_can_see_spot(pair<int, int> pos, vector<int> directions, bool check) {
    for (int dir : directions) {
        int y = pos.first;
        int x = pos.second;
        while (inMap(y, x) && a[y][x] != WALL) {
            if (a[y][x] == -1 || a[y][x] == 0) a[y][x] = check ? -1 : 0;
            y += dy[dir];
            x += dx[dir];
        }
    }
}

void dfs(int idx) {
    if (idx == cctv_positions.size()) {
        blind_area = min(get_blind_area(), blind_area);
        return;
    }

    int backup[10][10];
    memcpy(backup, a, sizeof(a));

    auto pos = cctv_positions[idx];
    int cctv = a[pos.first][pos.second];
    for (auto directions : v[cctv]) {
        check_can_see_spot(pos, directions, true);
        dfs(idx + 1);
        memcpy(a, backup, sizeof(a)); // 원래대로 복원
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (1 <= a[i][j] && a[i][j] <= 5) {
                cctv_positions.push_back( {i, j} );
            }
        }
    }

    dfs(0);
    cout << blind_area;
}