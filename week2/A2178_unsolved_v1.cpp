#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int n, m;
vector<int> counts;
bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void go(vector<bool> a[], int y, int x, vector<bool> visited[], int cnt) {
    visited[y][x] = true;
    cout << "call go() y: " << y << ", x: " << x << '\n';
    cnt++;
    if (y == n-1 && x == m-1) {
        cout << "cnt: " << cnt << '\n';
        counts.push_back(cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << "ny: " << ny << ", nx: " << nx << '\n';
        // 2,4 에서 3,4->3,5로 가서 리턴되고 3,4에서 리턴되고
        // inMap으로 범위 확인을 하기 때문에 out of index 예외는 발생 안 할것 같은데...
        if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
            cout << y << "," << x << " -> " << ny << "," << nx << '\n';
            go(a, ny, nx, visited, cnt);
            // visited[nx][ny] = false;
            visited[ny][nx] = false;
            // cnt--; cnt는 호출된 go()에서 받을 때 복사되어서 넘어가기 때문에
            // go()에서 증가한 cnt는 여기에 영향 x, 증가되지 않는다.
        }
    }
    cout << "return at x: " << x << ", y: " << y << '\n';
/* 
    // dx, dy배열을 활용하지 않는다면,
    int ny = y + 1; int nx = x;
    // using ny, nx

    int ny = y - 1; int nx = x;
    // using ny, nx

    int ny = y; int nx = x + 1;
    // using ny, nx

    int ny = y; int nx = x - 1;
    // using ny, nx */
}

int main() {
    cin >> n >> m;
    vector<bool> a[n];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vector<bool> v;
        for (char c : s) {
            v.push_back(c-'0');
        }
        a[i] = v;
    }

    vector<bool> visited[n];
    for (int i = 0; i < n; i++) {
        vector<bool> v;
        for (int j = 0; j < m; j++) {
            v.push_back(false);
        }
        visited[i] = v;
    }

    // cout << "\n======\n\n";
    // // print matrix a
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << a[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << "\n======\n\n";
    // // print matrix visited
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << visited[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << "\n======\n\n";

    int cnt = 0;
    go(a, 0, 0, visited, cnt);
    int min = *min_element(counts.begin(), counts.end());
    cout << "the shortest path length: " << min << '\n';
}