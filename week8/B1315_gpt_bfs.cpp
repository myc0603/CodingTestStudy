#include <iostream>
#include <queue>
using namespace std;

int N, STR[52], INT[52], PNT[52], points[1002][1002], clearCnts[1002][1002], visited[1002][1002];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> STR[i] >> INT[i] >> PNT[i];

    for (int q = 0; q < N; ++q) {
        for (int s = 0; s <= 1000; ++s) {
            for (int i = s < STR[q] ? INT[q] : 0; i <= 1000; ++i) {
                points[s][i] += PNT[q];
                ++clearCnts[s][i];    
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = 1;

    int ans = 0;
    while (q.size()) {
        auto [s, i] = q.front();
        q.pop();

        ans = max(ans, clearCnts[s][i]);
        if (ans == N) break;

        int pnt = points[s][i] - (s + i - 2);
        for (int p = 0; p <= pnt; ++p) {
            int ns = min(1000, s + p);
            int ni = min(1000, i + pnt - p);
            if (ns == 1000 || ni == 1000) {
                cout << N;
                return 0;
            }
            // if (!visited[ns][ni] && clearCnts[ns][ni] > clearCnts[s][i]) { -> 성능이 더 좋아지진 않았음
            // clearCnts[ns][ni] > clearCnts[s][i] 조건에 안 맞는 상태에서 큐에 들어가게 되면
            // ns, ni를 탐색할 때 더 얻을 수 있는 포인트가 없기 때문에 어차피 더 이상 탐색하지 못해서 이에 대한 탐색 연산은 금방 끝남
            if (!visited[ns][ni]) {
                q.push({ns, ni});
                visited[ns][ni] = 1;
            }
        }
    }

    cout << ans;
}