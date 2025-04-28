#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000007;
int n, m, c;
vector<vector<int>> dp[51][51];
vector<pair<int, int>> arcades;

void printVector(const vector<long long> &v) {
    for (long long x : v) cout << x << ' ';
    cout << '\n';
}

void addVector(vector<vector<int>> &result, const vector<vector<int>> &v) {
    for (int i = 0; i <= c; i++) {
        for (int j = 0; j <= c; j++) {
            result[i][j] = (result[i][j] + v[i][j]) % MOD;
        }
    }
}

vector<vector<int>> dfs(int y, int x) {
    int curArcade = 0;
    for (int i = 1; i <= c; i++) {
        if (arcades[i].first == y && arcades[i].second == x) {
            curArcade = i;
            break;
        }
    }

    vector<vector<int>> &res = dp[y][x];
    if (res.size()) return res;

    if (y == n && x == m) {
        res = vector<vector<int>>(c + 1, vector<int>(c + 1));
        int cnt = curArcade ? 1 : 0;
        res[cnt][curArcade] = 1;
        return res;
    }

    if (y < n) {
        res = dfs(y + 1, x);
        if (x < m) addVector(res, dfs(y, x + 1));
    } else res = dfs(y, x + 1);

    if (curArcade) {
        for (int i = c; i >= 1; i--) {
            int temp = res[i-1][0];
            res[i-1][0] = 0;
            for (int j = 0; j < curArcade; j++) {
                res[i-1][j] = 0;
            }
            for (int j = curArcade + 1; j <= c; j++) {
                temp = (temp + res[i-1][j]) % MOD;
                res[i-1][j] = 0;
            }
            res[i][curArcade] = temp;
        }
    }
    return res;
}

int main() {
    cin >> n >> m >> c;
    arcades.resize(c + 1);
    for (int i = 1; i <= c; i++) {
        cin >> arcades[i].first >> arcades[i].second;
    }

    vector<vector<int>> temp = dfs(1, 1);
    vector<int> result(c + 1);
    for (int i = 0; i <= c; i++) {
        for (int x : temp[i]) {
            result[i] = (result[i] + x) % MOD;
        }
    }
    
    for (int x : result) cout << x << ' ';
}