#include <iostream>
using namespace std;

int N, a[130][130];

pair<int, int> sol(int sy, int sx, int n) {
    bool allSame = true;
    int temp = a[sy][sx];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (temp != a[sy+i][sx+j]) {
                allSame = false;
                break;
            }
        }
        if (!allSame) break;
    }
    if (allSame) {
        if (a[sy][sx]) return {0, 1};
        return {1, 0};
    }

    auto p1 = sol(sy, sx, n/2);
    auto p2 = sol(sy + n/2, sx, n/2);
    auto p3 = sol(sy, sx + n/2, n/2);
    auto p4 = sol(sy + n/2, sx + n/2, n/2);
    
    return {
        p1.first + p2.first + p3.first + p4.first,
        p1.second + p2.second + p3.second + p4.second,
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    auto ans = sol(0, 0, N);
    cout << ans.first << '\n' << ans.second << '\n';
}