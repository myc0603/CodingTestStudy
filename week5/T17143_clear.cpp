#include <iostream>
#include <vector>
using namespace std;

int n, m, shark_cnt, a[105][105]; // a[i][j] : i,j에 있는 상어의 index (1-based index)
int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 1, -1};

struct Shark {
    int index, y, x, speed, direction, sizes;
    bool die = false;

    Shark() {}
    Shark(int r, int c, int s, int d, int z) : y(r), x(c), speed(s), direction(d), sizes(z) {}

    pair<int, int> move() {
        int dis = speed;
        while (dis > 0) {
            int ny = max(min(y + dy[direction] * dis, n), 1);
            int nx = max(min(x + dx[direction] * dis, m), 1);

            dis -= max(abs(ny - y), abs(nx - x));
            y = ny; x = nx;

            if (direction == 1 && y == 1) direction = 2;
            else if (direction == 2 && y == n) direction = 1;
            else if (direction == 3 && x == m) direction = 4;
            else if (direction == 4 && x == 1) direction = 3;
        }

        return { y, x };
    }
};

vector<Shark> sharks;

void fight(int s1, int s2) {
    if (sharks[s1].sizes > sharks[s2].sizes) {
        sharks[s2].die = true;
        a[sharks[s1].y][sharks[s1].x] = s1;
    } else {
        sharks[s1].die = true;
        a[sharks[s2].y][sharks[s2].x] = s2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> shark_cnt;

    sharks.resize(shark_cnt + 1);
    for (int i = 1; i <= shark_cnt; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark shark(r, c, s, d, z);
        sharks[i] = shark;
        a[r][c] = i;
    }

    int catch_size = 0;
    for (int fisher_pos = 1; fisher_pos <= m; fisher_pos++) {
        // 상어 잡기
        for (int row = 1; row <= n; row++) {
            int shark_index = a[row][fisher_pos];
            cout << "  catch? -> " << shark_index << '\n';
            if (shark_index && !sharks[shark_index].die) {
                catch_size += sharks[shark_index].sizes;
                sharks[shark_index].die = true;
                a[row][fisher_pos] = 0; //
                break;
            }
        }

        // 상어 이동
        vector<pair<int, pair<int, int>>> new_positions;
        for (int i = 1; i <= shark_cnt; i++) {
            if (sharks[i].die) continue;
            
            cout << "  shark" << i << " ";
            a[sharks[i].y][sharks[i].x] = 0;
            auto next_pos = sharks[i].move();
            new_positions.push_back( { i, next_pos } );
        }

        for (auto p : new_positions) {
            int shark_idx = p.first;
            auto pos = p.second;

            int already_idx = a[pos.first][pos.second];
            if (already_idx) fight(shark_idx, already_idx);
            else a[sharks[shark_idx].y][sharks[shark_idx].x] = shark_idx;
        }
    }

    cout << catch_size;
}