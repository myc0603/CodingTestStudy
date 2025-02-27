#include <bits/stdc++.h>
using namespace std;

int a[100][100], visited[100][100];
int n, m;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

// 이렇게 고치면 될 거 같기는 한데 어차피 dfs(area = 0)에서 0으로 들어간 area값이
// 끝까지 전달되어서 호출되는 모든 dfs()에서 area = 0값으로 들어옴. 변경돼서 다음 dfs호출에 넘긴다거나 그러지 않음
// 그러면 파라미터로 area를 쓸 이유가 전혀 없음 => solDfs()
int MyDfs(int y, int x, int area) {
    cout << "call MyDfs(), area: " << area << '\n';
    visited[y][x] = 1;

    int sum = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
            sum += MyDfs(ny, nx, area);
        }
    }
    area += sum;
    return area;
}

int solDfs(int y, int x) {
    int area = 1;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
            area += solDfs(ny, nx);
        }
    }
    return area;
}

int main() {
    int k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 1;
        }
    }

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                a[i][j] = 0;
            }
        }
    }

    vector<int> areas;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] && !visited[i][j]) {
                // int area = MyDfs(i, j, 0);
                int area = solDfs(i, j);
                areas.push_back(area);
                // cnt++;
            }
        }
    }
    sort(areas.begin(), areas.end());
    cout << areas.size() << '\n';
    for (int num : areas) {
        cout << num << ' ';
    }
}
