#include <iostream>
#include <vector>
using namespace std;

const int WALL = 6;
int n, m, a[10][10], visited[10][10], blind_area = 100, can_see;
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

int check_can_see_spot(pair<int, int> pos, vector<int> directions, bool check) {
    int area = 0;
    for (int dir : directions) {
        int y = pos.first;
        int x = pos.second;
        while (inMap(y, x) && a[y][x] != WALL) {
            if (a[y][x] == 0) {
                if (check) {
                    if (visited[y][x] == 0) area++;
                    visited[y][x]++;
                } else {
                    visited[y][x]--;
                    // if (visited[y][x] == 0) area++;
                }
            }
            y += dy[dir];
            x += dx[dir];
        }
    }

    return area;
}

void dfs(int idx, int area) {
    if (idx == cctv_positions.size()) {
        blind_area = min(can_see - area, blind_area);
        return;
    }

    auto pos = cctv_positions[idx];
    int cctv = a[pos.first][pos.second];
    for (auto directions : v[cctv]) {
        int add_area = check_can_see_spot(pos, directions, true);
        dfs(idx + 1, area + add_area);
        check_can_see_spot(pos, directions, false);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (1 <= a[i][j] && a[i][j] <= 5) {
                cctv_positions.push_back( {i, j} );
            }
            if (a[i][j] == 0) can_see++;
        }
    }

    dfs(0, 0);
    cout << blind_area;
}