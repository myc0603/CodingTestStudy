#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, a[12][12], yangboons[12][12];
vector<int> ageOfTrees[12][12];
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dx[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool inMap(int y, int x) {
    return 1 <= y && y  <= n && 1 <= x && x <= n;
}

void springAndSummer() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            // spring
            auto &ages = ageOfTrees[i][j];
            vector<int> deadTrees;
            sort(ages.begin(), ages.end());
            for (size_t k = 0; k < ages.size(); ++k) {
                if (ages[k] <= yangboons[i][j]) {
                    yangboons[i][j] -= ages[k];
                    ages[k]++;
                } else {
                    deadTrees.push_back(k);
                }
            }

            // summer
            for (auto rit = deadTrees.rbegin(); rit != deadTrees.rend(); ++rit) {
                yangboons[i][j] += ages[*rit] / 2;
                ages.erase(ages.begin() + *rit);
                m--;
            }
        }
    }
}

void fallAndWinter() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            // fall
            for (int age : ageOfTrees[i][j]) {
                if (age % 5 == 0) {
                    for (int k = 0; k < 8; ++k) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (inMap(ny, nx)) {
                            ageOfTrees[ny][nx].push_back(1);
                            m++;
                        }
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
        ageOfTrees[r][c].push_back(age);
    }
    fill(&yangboons[0][0], &yangboons[0][0] + 12 * 12, 5);

    while (k--) {
        springAndSummer();
        fallAndWinter();
    }

    cout << m;
}