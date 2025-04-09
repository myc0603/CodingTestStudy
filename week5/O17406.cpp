#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cstring>
using namespace std;

int n, m, k, a[50][50], a_copy[50][50];
vector<tuple<int, int, int>> rotates;

int valueOf() {
    int value = 5000;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a_copy[i][j];
        }
        value = min(sum, value);
    }
    return value;
}

void shift(vector<pair<int, int>> v) {
    auto next = v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; i--) {
        auto cur = v[i];
        a_copy[next.first][next.second] = a_copy[cur.first][cur.second];
        
        next = cur;
    }
}

void do_rotation(tuple<int, int, int> rotation) {
    int r, c, max_s;
    tie(r, c, max_s) = rotation;
    
    for (int s = 1; s <= max_s; s++) {
        int start_y = r - s; int start_x = c - s;
        int end_y = r + s; int end_x = c + s;

        int temp = a_copy[start_y+1][start_x];

        vector<pair<int, int>> rotating_positions;
        for (int j = start_x; j < end_x; j++) rotating_positions.push_back( { start_y, j } );
        for (int i = start_y; i < end_y; i++) rotating_positions.push_back( { i, end_x } );
        for (int j = end_x; j > start_x; j--) rotating_positions.push_back( { end_y, j } );
        for (int i = end_y; i > start_y; i--) rotating_positions.push_back( { i, start_x} );

        shift(rotating_positions);

        a_copy[start_y][start_x] = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        rotates.push_back({--r, --c, s});
    }

    int ans = 5000;

    sort(rotates.begin(), rotates.end());
    do {
        memcpy(a_copy, a, sizeof(a));
        for (auto rotate : rotates) {
            do_rotation(rotate);
        }

        ans = min(valueOf(), ans);
    } while (next_permutation(rotates.begin(), rotates.end()));

    cout << ans;
}