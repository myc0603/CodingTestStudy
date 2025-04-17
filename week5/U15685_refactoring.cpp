#include <iostream>
#include <vector>
using namespace std;

int n, a[101][101];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void checkCurve(int x, int y, int d, int g) {
    vector<pair<int, int>> curve;
    
    curve.push_back( {y, x} );
    a[y][x] = 1;
    
    int ny = y + dy[d];
    int nx = x + dx[d];
    curve.push_back( {ny, nx} );
    a[ny][nx] = 1;

    for (int gen = 1; gen <= g; gen++) {

        int pivot_idx = curve.size() - 1;
        for (int i = pivot_idx - 1; i >= 0; i--) {
            int cur_y = curve[i].first - curve[pivot_idx].first;
            int cur_x = curve[i].second - curve[pivot_idx].second;

            int rotated_y = cur_x + curve[pivot_idx].first;
            int rotated_x = -cur_y + curve[pivot_idx].second;
            curve.push_back( {rotated_y, rotated_x} );
            a[rotated_y][rotated_x] = 1;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        checkCurve(x, y, d, g);
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
           if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) cnt++;
        }
    }
    cout << cnt;
}