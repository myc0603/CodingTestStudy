#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, a[12][12], yangboons[12][12];
deque<pair<int, int>> ageOfTrees[12][12];
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dx[] = {1, 0, -1, 1, -1, 1, 0, -1};

void springAndSummer() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            // spring
            auto &trees = ageOfTrees[i][j];
            int add = 0;
            int idx = 0;
            for (; idx < trees.size(); ++idx) {

                int &age = trees[idx].first;
                int &cnt = trees[idx].second;
                
                if (age * cnt <= yangboons[i][j]) {
                    yangboons[i][j] -= age * cnt;
                    age++;
                } else if (age > yangboons[i][j]) {
                    break;
                } else {
                    int alive = yangboons[i][j] / age;
                    int dead = cnt - alive;

                    yangboons[i][j] -= alive * age;

                    // alive == 0 이어서 나중에 삭제될 부분이라면
                    // 여기서 cnt가 감소되면 나중에 삭제되면서 add와 m이 cnt값으로 업데이트되므로
                    // cnt가 변하면 안됨
                    // if (alive) {
                    cnt -= dead;
                    m -= dead;
                    add += (age / 2) *dead;
                    ++idx;
                    ++age;
                    // }

                    break;
                }
            }

            // idx부터 다 죽음
            while (idx < trees.size()) {
                add += (trees.back().first / 2) * trees.back().second;
                m -= trees.back().second;
                trees.pop_back();
            }
            
            // summer
            yangboons[i][j] += add;
        }
    }
}

void fallAndWinter() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            // fall
            for (auto &tree : ageOfTrees[i][j]) {
                if (tree.first % 5 == 0) {
                    for (int k = 0; k < 8; ++k) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
                        if (ageOfTrees[ny][nx].empty() || ageOfTrees[ny][nx].front().first != 1) {
                            ageOfTrees[ny][nx].push_front( {1, tree.second} );
                        } else {
                            ageOfTrees[ny][nx].front().second += tree.second;
                        }
                        m += tree.second;
                    }
                }
            }

            // winter
            yangboons[i][j] += a[i][j];
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        int r, c, age;
        cin >> r >> c >> age;
        ageOfTrees[r][c].push_back( {age, 1} );
    }
    fill(&yangboons[0][0], &yangboons[0][0] + 12 * 12, 5);

    while (k--) {
        springAndSummer();
        fallAndWinter();
    }

    cout << m;
}