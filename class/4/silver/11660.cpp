#include <iostream>
using namespace std;
int n, m, psum[1030][1030];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1] + x;
        }
    }
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1] << '\n';
    }
}