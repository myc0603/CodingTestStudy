#include <iostream>
using namespace std;

int n, a[16][16], dp[16][16][3];

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool canGo(int y, int x, int newState) {
    if (newState == 0) return inMap(y, x + 1) && a[y][x+1] == 0;
    else if (newState == 2) return inMap(y + 1, x) && a[y+1][x] == 0;
    else { // newState == 1
        return inMap(y, x + 1) && a[y][x+1] == 0
            && inMap(y + 1, x) && a[y+1][x] == 0
            && inMap(y + 1, x + 1) && a[y+1][x+1] == 0;
    }
}

int dfs(int y, int x, int state) {
    if (y == n - 1 && x == n - 1) return 1;

    int &result = dp[y][x][state];
    if (result != -1) return result;

    result = 0;
    if (state != 2 && canGo(y, x, 0)) result += dfs(y, x + 1, 0);
    if (canGo(y, x, 1)) result += dfs(y + 1, x + 1, 1);
    if (state != 0 && canGo(y, x, 2)) result += dfs(y + 1, x, 2);
    return result;
}

// state: 0: 가로, 1: 대각선, 2: 세로
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    fill(&dp[0][0][0], &dp[0][0][0] + 16 * 16 * 3, -1);
    cout << dfs(0, 1, 0);
}