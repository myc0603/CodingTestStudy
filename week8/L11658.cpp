#include <iostream>
using namespace std;

int n, m, a[1030][1030], tree[1030][1030];

void update(int y, int x, int val) {
    while (y <= n && x <= n) {
        tree[y][x] += val;
        for (int nx = x + (x & -x); nx <= n; nx += nx & -nx) {
            tree[y][nx] += val;
        }
        for (int ny = y + (y & -y); ny <= n; ny += ny & -ny) {
            tree[ny][x] += val;
        }

        y += y & -y; x += x & -x;
    }
}

int sum(int y, int x) {
    int result = 0;
    while (y > 0 && x > 0) {
        result += tree[y][x];
        for (int nx = x - (x & -x); nx > 0; nx -= nx & -nx) {
            result += tree[y][nx];
        }
        for (int ny = y - (y & -y); ny > 0; ny -= ny & -ny) {
            result += tree[ny][x];
        }

        y -= y & -y; x -= x & -x;
    }
    return result;
}

int query(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            update(i, j, a[i][j]);
        }
    }

    int w;
    while (m--) {
        cin >> w;
        if (w == 0) {
            int x, y, c;
            cin >> x >> y >> c;
            int diff = c - a[x][y];
            update(x, y, diff);
            a[x][y] = c;
        } else { // w == 1
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1, y1, x2, y2) << '\n';
        }
    }
}