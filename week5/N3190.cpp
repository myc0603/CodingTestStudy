#include <bits/stdc++.h>
using namespace std;

int n, k, l, a[100][100];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
queue<pair<int, char>> turn_info;

deque<pair<int, int>> snail;

void printA() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=========================\n";
}

pair<int, int> getNextPosition(pair<int, int> current, int direction) {
    int ny = current.first + dy[direction];
    int nx = current.second + dx[direction];
    return {ny, nx};
}

bool inMap(pair<int, int> position) {
    int y = position.first;
    int x = position.second;
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool cannotGo(pair<int, int> nextPosition) {
    if (!inMap(nextPosition)) return true;
    for (auto body : snail) {
        if (nextPosition == body) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        a[--y][--x] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int sec; char dir; // L: -1, D: +1
        cin >> sec >> dir;
        turn_info.push({sec, dir});
    }

    snail.push_front({0, 0});
    int dir = 0;
    int sec = 0;
    while (true) {
        int ny, nx;
        tie(ny, nx) = getNextPosition(snail.front(), dir);
        if (cannotGo({ny, nx})) break;

        sec++;
        snail.push_front({ny, nx});
        if (a[ny][nx]) a[ny][nx] = 0;
        else {
            a[snail.back().first][snail.back().second] = 0;//
            snail.pop_back();
        }
        a[ny][nx] = 8;// -> 이걸로 뱀의 위치를 확인하면 cannotGo의 시간복잡도를 O(1)로 줄일 수 있겠다.

        cout << sec << " sec after:\n";
        printA();//

        if (turn_info.size() && sec == turn_info.front().first) {
            dir += turn_info.front().second == 'D' ? 1 : -1;
            dir = (dir + 4) % 4;
            // dir %= 4;
            turn_info.pop();
        }
    }

    cout << sec + 1 << '\n';
}