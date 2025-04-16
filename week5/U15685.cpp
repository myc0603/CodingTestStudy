#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
// #include <set>
using namespace std;

const int MAX_Y = 100;
const int MAX_X = 100;
int n, a[MAX_Y+5][MAX_X+5];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

unordered_set<pair<int, int>, pair_hash> on_curve;
// set<pair<int, int>> on_curve;

pair<int, int> rotate(pair<int, int> point, const pair<int, int> pivot) {
    point.first -= pivot.first; // y
    point.second -= pivot.second; // x

    swap(point.first, point.second);
    point.second *= -1;

    point.first += pivot.first; // y
    point.second += pivot.second; // x
    return point;
}

struct DragonCurve {
    int y, x, dir, gen;
    int end_y, end_x;
    
    vector<pair<int, int>> components;

    DragonCurve() {}
    DragonCurve(int _y, int _x, int _d, int _g) : y(_y), x(_x), dir(_d), gen(_g) {
        components.push_back( {y, x} );
        on_curve.insert( {y, x} );
        a[y][x] = 1;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        components.push_back( {ny, nx} );
        on_curve.insert( {ny, nx} );
        a[ny][nx] = 1;

        for (int g = 1; g <= gen; g++) {
            int pivot_idx = components.size() - 1;
            for (int i = pivot_idx - 1; i >= 0; i--) {
                auto rotatedPoint = rotate(components[i], components[pivot_idx]);
                components.push_back(rotatedPoint);
                on_curve.insert(rotatedPoint);
                a[rotatedPoint.first][rotatedPoint.second] = 1;
            }
        }
    }
};

int main() {
    cin >> n;
    vector<DragonCurve> curves;
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        DragonCurve curve(y, x, d, g);
        curves.push_back(curve);
    }

    int cnt = 0;
    for (auto p : on_curve) {
        int y = p.first;
        int x = p.second;
        if (a[y][x] && a[y+1][x] && a[y][x+1] && a[y+1][x+1]) cnt++;
    }
    cout << cnt;
}