#include <iostream>
#include <vector>
using namespace std;

int n, m, shark_cnt, a[105][105];
int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 1, -1};

struct Shark {
    int index, y, x, y_speed, x_speed, direction, sizes;
    bool die = false;

    Shark() {}
    Shark(int r, int c, int y_s, int x_s, int d, int z) : y(r), x(c), y_speed(y_s), x_speed(x_s), direction(d), sizes(z) {}

    pair<int, int> move() {
        if (direction == 1)  {
            y -= y_speed;
            if (y == 1) {
                direction = 2;
                y = 2 - y;
            }
        } else if (direction == 2) {
            y += y_speed;
            if (y == n) {
                direction == 1;
                y = 2 * n - y;
            }
        } else if (direction == 3) {
            x += x_speed;
            if (x == m) {
                direction = 4;
                x = 2 * m - x;
            }
        } else {
            x -= x_speed;
            if (x == 1) {
                direction = 3;
                x = 2 - x;
            }
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
    sharks[0].die = true;
    for (int i = 1; i <= shark_cnt; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        
        // optimized part 1
        int y_speed = s % (2 * (n - 1));
        int x_speed = s % (2 * (m - 1));

        Shark shark(r, c, y_speed, x_speed, d, z);
        sharks[i] = shark;
        a[r][c] = i;
    }

    int catch_size = 0;
    for (int fisher_pos = 1; fisher_pos <= m; fisher_pos++) {
        // 상어 잡기
        for (int row = 1; row <= n; row++) {
            int shark_index = a[row][fisher_pos];
            if (shark_index && !sharks[shark_index].die) {
                catch_size += sharks[shark_index].sizes;
                sharks[shark_index].die = true;
                a[row][fisher_pos] = 0;
                break;
            }
        }

        // 상어 이동
        // optimized part 2
        vector<int> moving_sharks;
        for (int i = 1; i <= shark_cnt; i++) {
            if (sharks[i].die) continue;
            
            a[sharks[i].y][sharks[i].x] = 0;
            auto next_pos = sharks[i].move();
            moving_sharks.push_back(i);
        }

        for (int shark_idx : moving_sharks) {
            int y = sharks[shark_idx].y;
            int x = sharks[shark_idx].x;

            int already_idx = a[y][x];
            if (already_idx) fight(shark_idx, already_idx);
            else a[y][x] = shark_idx;
        }
    }

    cout << catch_size;
}