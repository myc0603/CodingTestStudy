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

    if (px != fx) xlines.emplace_back(min(px, fx), max(py, fy));
    if (py != fy) ylines.emplace_back(min(py, fy), max(py, fy));

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    vector<int> cnt_x(xs.size()), cnt_y(ys.size());
    for (const auto &p : xlines) {
        int minx = indexOf(xs, p.first);
        int maxx = indexOf(xs, p.second);
        // for (int i = minx; i <= maxx; ++i) ++cnt_x[i];
        for (int i = minx; i < maxx; ++i) ++cnt_x[i];
    }
    for (const auto &p : ylines) {
        int miny = indexOf(ys, p.first);
        int maxy = indexOf(ys, p.second);
        // for (int i = miny; i <= maxy; ++i) ++cnt_y[i];
        for (int i = miny; i < maxy; ++i) ++cnt_y[i];
    }

    cout << max(*max_element(cnt_x.begin(), cnt_x.end()), *max_element(cnt_y.begin(), cnt_y.end()));
}