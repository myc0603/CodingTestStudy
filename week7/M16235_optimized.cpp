#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, a[12][12], yangboons[12][12];
deque<int> ageOfTrees[12][12];
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dx[] = {1, 0, -1, 1, -1, 1, 0, -1};

void springAndSummer() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            // spring
            auto &ages = ageOfTrees[i][j];
            deque<int> newAges;
            int add = 0;
            for (int age : ages) {
                if (age <= yangboons[i][j]) {
                    yangboons[i][j] -= age;
                    newAges.push_back(age + 1);
                } else {
                    add += age / 2;
                    m--;
                }
            }
            swap(ages, newAges);
            
            // summer
            yangboons[i][j] += add;
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
                        if (1 <= ny && ny  <= n && 1 <= nx && nx <= n) {
                            ageOfTrees[ny][nx].push_front(1);
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