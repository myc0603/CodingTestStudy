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
        int start = max(hole.first, r);
        int end = hole.second;

        if (start < end) {
            int rem = (end - start) % len;
            cnt += (end - start) / len + (rem ? 1 : 0);
            r = end - rem + (rem ? len : 0);
        }
    }
    cout << cnt;
}