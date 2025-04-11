#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, len, cnt;
vector<pair<int, int>> water_holes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> len;
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        water_holes.push_back({ s, e });
    }

    sort(water_holes.begin(), water_holes.end());

    int r = -1;
    for (auto hole : water_holes) {
        r = max(hole.first, r);
        int end = hole.second;

        if (r >= end) continue;
        int add_count = (end - r + len - 1) / len;
        cnt += add_count;
        r += add_count * len;
    }
    cout << cnt;
}