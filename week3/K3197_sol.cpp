#include <bits/stdc++.h>
using namespace std;

int n, m, visited[1500][1500], swanVisited[1500][1500];
char a[1500][1500];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void printLake() {
    cout << "=== print Lake ===\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << "==================\n";
}

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool canMeetSwan(queue<pair<int, int>> &swanQ) {
    queue<pair<int, int>> temp;
    while (swanQ.size()) {
        int y, x;
        tie(y, x) = swanQ.front(); swanQ.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inMap(ny, nx) && !swanVisited[ny][nx]) {
                if (a[ny][nx] == 'L') {
                    return true;
                }
                if (a[ny][nx] == 'X') {
                    temp.push({ny, nx});
                } else {
                    swanQ.push({ny, nx});
                }
                swanVisited[ny][nx] = 1;
            }
        }
    }
    swanQ = temp;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int swanY, swanX;
    queue<pair<int, int>> waterQ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] != 'X') {
                waterQ.push({i, j});
                visited[i][j] = 1;
            }
            if (a[i][j] == 'L') {
                swanY = i;
                swanX = j;
            }
        }
    }

    int day = 0;
    queue<pair<int, int>> swanQ;
    swanQ.push({swanY, swanX});
    swanVisited[swanY][swanX] = 1;
    while (!canMeetSwan(swanQ)) {

        queue<pair<int, int>> temp;

        while (waterQ.size()) {
            int y, x;
            tie(y, x) = waterQ.front(); waterQ.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (inMap(ny,nx) && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    if (a[ny][nx] == 'X') {
                        temp.push({ny, nx});
                        a[ny][nx] = '.';
                    }
                }
            }
        }
        // memset을 하면 안됨
        // memset(&visited[0][0], 0, sizeof(visited));
        // memset(&swanVisited[0][0], 0, sizeof(swanVisited));
        // printLake();

        waterQ = temp;
        day++;
    }
    cout << day << '\n';
}