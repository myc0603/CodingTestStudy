#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> xs, ys;
vector<pair<int, int>> xlines, ylines;

int indexOf(const vector<int> &v, int value) {
    return lower_bound(v.begin(), v.end(), value) - v.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    xlines.reserve(n); ylines.reserve(n);

    int fx, fy, px, py;
    cin >> fx >> fy;
    xs.push_back(fx);
    ys.push_back(fy);
    px = fx;
    py = fy;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        xs.push_back(x);
        ys.push_back(y);

        if (px != x) xlines.emplace_back(min(px, x), max(px, x));
        if (py != y) ylines.emplace_back(min(py, y), max(py, y));

        px = x;
        py = y;
    }

    if (px != fx) xlines.emplace_back(min(px, fx), max(px, fx));
    if (py != fy) ylines.emplace_back(min(py, fy), max(py, fy));

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    vector<int> diff_x(xs.size()), diff_y(ys.size());
    for (const auto &p : xlines) {
        int minx = indexOf(xs, p.first);
        ++diff_x[minx];
        
        int maxx = indexOf(xs, p.second);
        --diff_x[maxx];
    }
    for (const auto &p : ylines) {
        int miny = indexOf(ys, p.first);
        ++diff_y[miny];

        int maxy = indexOf(ys, p.second);
        --diff_y[maxy];
    }

    // diff_x, cnt_y를 스위핑하면서 각 위치에서의 수직, 수평선이 지나갈 때 만나는 점의 개수를 확인
    int bestx = -1, besty = -1;
    int cur = 0;
    for (auto d : diff_x) {
        cur += d;
        bestx = max(cur, bestx);
    }
    cur = 0;
    for (auto d : diff_y) {
        cur += d;
        besty = max(cur, besty);
    }
    cout << max(bestx, besty);
}