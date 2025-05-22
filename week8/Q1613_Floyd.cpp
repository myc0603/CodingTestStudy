#include <iostream>
using namespace std;

const int SIZE = 402;
int n, k, s, mat[SIZE][SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;        
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i)  {
            for (int j = 1; j <= n; ++j) {
                mat[i][j] = mat[i][j] | (mat[i][k] & mat[k][j]);
                // mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]); min(0, 1) -> 0 -> 못감
            }
        }
    }

    cin >> s;
    while (s--) {
        int x, y;
        cin >> x >> y;
        if (mat[x][y]) cout << -1 << '\n';
        else if (mat[y][x]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}