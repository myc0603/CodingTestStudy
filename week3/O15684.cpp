#include <bits/stdc++.h>
using namespace std;

int n, m, h, ladder[31][10];

bool check() {
    for (int x = 1; x <= n; x++) {
        int val = x;
        for (int y = 1; y <= h; y++) {
            if (val < n && ladder[y][val]) {
                val++;
            } else if (val > 0 && ladder[y][val-1]) {
                val--;
            }
        }

        if (x != val) {
            return false;
        }
    }
    return true;
}

bool canAdd(int y, int x) {
    if (x > 1 && ladder[y][x-1] == 1) return false;
    if (x < n && ladder[y][x+1] == 1) return false;
    return true;
}

void checkAndExit(int cnt) {
    if (check()) {
        cout << cnt << '\n';
        exit(0);
    }
}

pair<int, int> getCoordFromIdx(int idx) {
    int y = idx / (n-1) + 1;
    int x = idx % (n-1) + 1;
    return {y, x};
}

int main() {
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;
        ladder[y][x] = 1;
    }

    if (check()) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = 4;
    int ladderSize = h * (n-1);
    for (int i = 0; i < ladderSize; i++) {
        int y1, x1;
        tie(y1, x1) = getCoordFromIdx(i);
        if (ladder[y1][x1] || !canAdd(y1, x1)) continue;

        ladder[y1][x1] = 1;
        if (check()) {
            cout << 1 << '\n';
            return 0;
        }

        for (int j = i + 1; j < ladderSize; j++) {
            int y2, x2;
            tie(y2, x2) = getCoordFromIdx(j);
            if (ladder[y2][x2] || !canAdd(y2, x2)) continue;

            ladder[y2][x2] = 1;
            if (check()) {
                ans = 2;
            }

            for (int k = j + 1; k < ladderSize; k++) {
                int y3, x3;
                tie(y3, x3) = getCoordFromIdx(k);
                if (ladder[y3][x3] || !canAdd(y3, x3)) continue;

                ladder[y3][x3] = 1;
                if (check()) {
                    ans = min(ans, 3);
                }

                ladder[y3][x3] = 0;
            }
            ladder[y2][x2] = 0;
        }
        ladder[y1][x1] = 0;
    }

    if (ans == 4) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}