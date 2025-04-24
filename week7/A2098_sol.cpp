#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, ways[16][16], dp[16][1 << 16];

int dfs(int visitCount, int city, int visited) {
    if (visitCount == n) {
        return ways[city][0] ? ways[city][0] : INF;
    }

    int &result = dp[city][visited];
    if (result != -1) return result;
    
    result = INF;
    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (visited & (1 << nextCity)) continue;
        if (ways[city][nextCity] == 0) continue;
        result = min(result, dfs(visitCount + 1, nextCity, visited | (1 << nextCity)) + ways[city][nextCity]);
    }
    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ways[i][j];
            // if (ways[i][j] == 0) ways[i][j] = 2000000; // 2백만
        }
    }
    
    fill(&dp[0][0], &dp[0][0] + 16 * (1 << 16), -1);
    // memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, 1);
}