#include <bits/stdc++.h>
using namespace std;

int a[8][8], aCopy[8][8];
int n, m;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
vector<pair<int, int>> zeros, virus;

bool inMap(int y, int x) {
    // x < m 을 x <= m 으로 잘못씀
    // 정해진 맵 바깥으로 새어나감
    // 바깥부분을 벽으로 둘러쌀 필요가 있음
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool printACopy() {
    cout << "=============\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << aCopy[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=============\n";
}

void bfs(pair<int, int> start) {
    // if (start.first == 1) {
    //     cout << "\n\ncall bfs(), the problem is here...\n\n";
    //     printACopy();
    // }
    queue<pair<int, int>> q;
    q.push(start);
    // aCopy[start.first][start.second] = 2; // 필요x 이미 2임

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inMap(ny, nx) && aCopy[ny][nx] == 0) {
                q.push({ny, nx});
                aCopy[ny][nx] = 2;
                // if (start.first == 1) {
                //     cout << y << ',' << x << " -> " << ny << ',' << nx << '\n';
                //     printACopy();
                // }
            }
        }
    }
}

void dfs(pair<int, int> p) {

    aCopy[p.first][p.second] = 2;
    cout << "dfs(" << p.first << ',' << p.second << ") called\n";
    printACopy();

    for (int i = 0; i < 4; i++) {
        int ny = p.first + dy[i];
        int nx = p.second + dx[i];
        if (inMap(ny, nx) && aCopy[ny][nx] == 0) {
            cout << "i: " << i << "  " << p.first << ',' << p.second << " -> " << ny << ',' << nx << '\n';
            dfs({ny, nx});
        }
    }
}

int tryBfs(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    // a를 카피하려면 n*m이 아니라 전체크기인 8*8만큼을 다 카피해야됨
    copy(&a[0][0], &a[0][0] + 64, &aCopy[0][0]);
    // printACopy();

    // aCopy에 벽추가
    aCopy[p1.first][p1.second] = 1;
    aCopy[p2.first][p2.second] = 1;
    aCopy[p3.first][p3.second] = 1;

    // 벽 추가 후 aCopy print
    // printACopy();

    // a를 쫙 탐색하면서 a 업데이트
    for (auto p : virus) {
        // bfs(p);
        dfs(p); // dfs하면 멈춤....
    }
    // a 업뎃후 a 프린트
    // printACopy();
    
    // a에서 빈칸 넓이 체크
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (aCopy[i][j] == 0) {
                area++;
            }
        }
    }

    // a 원래대로하려면 2로 바꾼것도 체크해야됨됨
    // a[p1.first][p1.second] = 0;
    // a[p2.first][p2.second] = 0;
    // a[p3.first][p3.second] = 0;

    // 원래대로 a 바꾸고 나서 printA
    // printA();

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

    // virus는 문제 x
    // for (auto p : virus) {
    //     cout << p.first << ' ' << p.second << '\n';
    // }

    // int size = zero.size();
    // int max = -1;
    // for (int i = 0; i < size; i++) {
    //     for (int j = i + 1; j < size; j++) {
    //         for (int k = j + 1; k < size; k++) {
    //             int area = tryBfs(zero[i], zero[j], zero[k]);
    //             // if (max < area) {
    //                 // cout << "empty: " << i << ',' << j << ',' << k << " -> area: " << area << '\n';
    //             // }
    //             max = max > area ? max : area;
    //         }
    //     }
    // }
    // cout << max << '\n';

    // 디버깅용 테스트 현재 한번만 하면 ok 그 이상하면 a초기화가 잘 안돼서 안됨
    // a를 복사해서 따로 또 만들어야 될듯
    int area = tryBfs(zeros[0], zeros[4], zeros[16]);
    cout << area << '\n';
}