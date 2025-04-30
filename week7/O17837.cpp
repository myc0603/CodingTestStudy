#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mal {
    int y, x, dir;
    Mal() {}
    Mal(int _y, int _x, int _dir) : y(_y), x(_x), dir(_dir) {}
};

int n, k, a[13][13];
vector<int> state[13][13];
vector<Mal> mals;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

string dirToStr(int dir) {
    if (dir == 0) return "R";
    if (dir == 1) return "L";
    if (dir == 2) return "U";
    if (dir == 3) return "D";
}

void printStates() {
    cout << "print states\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (state[i][j].empty()) continue;
            cout << i << ',' << j << ": ";
            for (int x : state[i][j]) {
                cout << x + 1 << "(" << dirToStr(mals[x].dir) << ") ";
            }
            cout << '\n';
        }
    }
}

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool canGo(int y, int x) {
    return inMap(y, x) && a[y][x] != 2;
}

// 말이 네 개 쌓이면 return false
bool moveMal(int i) {
    Mal mal = mals[i];
    int ny = mal.y + dy[mal.dir];
    int nx = mal.x + dx[mal.dir];

    if (!canGo(ny, nx)) {
        mals[i].dir ^= 1;
        ny = mal.y + dy[mals[i].dir];
        nx = mal.x + dx[mals[i].dir];
        if (canGo(ny, nx)) return moveMal(i);
    } else {
        vector<int> movingMals, stayMals;
        bool findMal = false;
        for (int idx : state[mal.y][mal.x]) {
            if (idx == i) findMal = true;
            if (findMal) movingMals.push_back(idx);
            else stayMals.push_back(idx);
        }

        if (a[ny][nx] == 1) reverse(movingMals.begin(), movingMals.end());
        for (int idx : movingMals) {
            state[ny][nx].push_back(idx);
            if (state[ny][nx].size() >= 4) return false;
            mals[idx].y = ny;
            mals[idx].x = nx;
        }
        state[mal.y][mal.x] = stayMals;
    }
    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    mals.reserve(k);
    for (int i = 0; i < k; ++i) {
        int y, x, dir;
        cin >> y >> x >> dir;
        mals.emplace_back(--y, --x, --dir);
        state[y][x].push_back(i);
    }

    int cnt = 1;
    while (true) {
        if (cnt > 1000) {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < k; ++i) {
            if (!moveMal(i)) {
                cout << cnt;
                return 0;
            }
        }
        ++cnt;
    }
}