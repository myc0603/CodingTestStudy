#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Spot {
    int height, y, x;

    Spot() {}
    Spot(int h, int _y, int _x) : height(h), y(_y), x(_x) {}

    bool operator<(const Spot &s) {
        return height < s.height;
    }
};

int n, m, t, d, a[27][27], minTime[2][27][27];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
vector<Spot> spots;

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int height(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

void dijkstra(bool isReturn) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq1, pq2;
    pq1.push( {0, {0, 0}} );
    minTime[isReturn][0][0] = 0;

    while (pq1.size()) {
        int curCost = pq1.top().first;
        int y = pq1.top().second.first;
        int x = pq1.top().second.second;
        pq1.pop();

        if (curCost > minTime[isReturn][y][x]) continue;

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!inMap(ny, nx)) continue;
            int diff = a[ny][nx] - a[y][x];
            if (isReturn) diff *= -1;
            if (abs(diff) > t) continue; 
            int nextCost = curCost + (diff > 0 ? diff * diff : 1);
            if (nextCost < minTime[isReturn][ny][nx]) {
                pq1.push( {nextCost, {ny, nx}} );
                minTime[isReturn][ny][nx] = nextCost;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t >> d;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            int h = height(s[j]);
            a[i][j] = h;
            spots.push_back( {h, i, j} );
        }
    }
    sort(spots.begin(), spots.end());

    fill(&minTime[0][0][0], &minTime[0][0][0] + 2 * 27 * 27, 1e9);

    dijkstra(0);
    dijkstra(1);

    for (auto rit = spots.rbegin(); rit != spots.rend(); ++rit) {
        int y = rit -> y;
        int x = rit -> x;
        if (minTime[0][y][x] + minTime[1][y][x] <= d) {
            cout << rit -> height;
            return 0;
        }
    }
}