#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000007;
int n, m, c, a[51][51];
vector<int> dp[51][51][51];

void addVector(vector<int> &result, const vector<int> &v) {
    for (int i = 0; i <= c; i++) {
        result[i] = (result[i] + v[i]) % MOD;
    }
}

// y,x에서 lastArcade를 마지막으로 지나왔을 때 n,m까지 오락실을 지나친 횟수 별 경우의 수
vector<int> dfs(int y, int x, int lastArcade) {
    auto &result = dp[y][x][lastArcade];
    if (result.size()) return result;

    result = vector<int>(c + 1);
    if (a[y][x] && lastArcade > a[y][x]) return result;
    if (y == n && x == m) {
        if (a[y][x] != 0) result[1] = 1;
        else result[0] = 1;
        return result;
    }
    
    if (a[y][x]) lastArcade = a[y][x];
    if (y < n) {
        result = dfs(y + 1, x, lastArcade);
        if (x < m) addVector(result, dfs(y, x + 1, lastArcade));
    } else result = dfs(y, x + 1, lastArcade);
    if (a[y][x]) {
        for (int i = c; i >= 0; --i) {
            result[i] = result[i-1];
        }
        result[0] = 0;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        int y, x;
        cin >> y >> x;
        a[y][x] = i;
    }

    auto result = dfs(1, 1, 0);
    for (int &num : result) cout << num << ' ';
}