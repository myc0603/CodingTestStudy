#include <iostream>
#include <bitset>
using namespace std;

const int SIZE = 402;
int n, k, s;
bitset<401> greaterThan[401];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        greaterThan[x].set(y);      
    }

    for (int k = 1; k <= n; ++k) { // 중간 노드
        for (int i = 1; i <= n; ++i) { // 출발 노드
            if (greaterThan[i][k]) greaterThan[i] |= greaterThan[k];
        }
    }

    cin >> s;
    while (s--) {
        int x, y;
        cin >> x >> y;
        if (greaterThan[x][y]) cout << -1 << '\n';
        else if (greaterThan[y][x]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}