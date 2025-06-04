#include <iostream>
#include <algorithm>
using namespace std;

const pair<int, int> SHAPE[5][4] = {
    { {0, 0}, {0, 1}, {1, 0}, {1, 1} }, // ㅁ
    { {0, 0}, {0, 1}, {0, 2}, {0, 3} }, // ㅡ
    { {0, 0}, {1, 0}, {1, 1}, {2, 1} }, // Z
    { {0, 0}, {0, 1}, {0, 2}, {1, 1} }, // ㅜ
    { {0, 0}, {0, 1}, {1, 0}, {2, 0} } // ㄴ
};

// a[1] : a[0]의 transpose
int n, m, a[2][510][510], ans;

void flipY() {
    for (int i = 0; i < n; ++i) reverse(a[0][i], a[0][i] + m);
    for (int j = 0; j < m; ++j) reverse(a[1][j], a[1][j] + n);
}

void flipX() {
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m; ++j) {
            swap(a[0][i][j], a[0][n-1-i][j]);
        }
    }
    for (int i = 0; i < m / 2; ++i) {
        for (int j = 0; j < n; ++j) swap(a[1][i][j], a[1][m-1-i][j]);
    }
}

int maxValue(int transpose, int shapeIndex) {
    int rows = transpose ? m : n;
    int cols = transpose ? n : m;
    int tot = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int temp = 0;
            for (int k = 0; k < 4; ++k) {
                int row = i + SHAPE[shapeIndex][k].first;
                int col = j + SHAPE[shapeIndex][k].second;
                temp += a[transpose][row][col];
            }

            tot = max(tot, temp);
        }
    }

    return tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[0][i][j];
            a[1][j][i] = a[0][i][j];
        }
    }

    for (int i = 0; i < 5; ++i) ans = max(ans, maxValue(0, i));
    for (int i = 1; i < 5; ++i) ans = max(ans, maxValue(1, i));

    // y축 대칭
    flipY();
    for (int i = 2; i < 5; ++i) {
        ans = max(ans, maxValue(0, i));
        ans = max(ans, maxValue(1, i));
    }

    flipX();
    for (int i = 2; i < 5; ++i) {
        ans = max(ans, maxValue(0, i));
        ans = max(ans, maxValue(1, i));
    }

    flipY();
    for (int i = 2; i < 5; ++i) {
        ans = max(ans, maxValue(0, i));
        ans = max(ans, maxValue(1, i));
    }

    cout << ans;
}