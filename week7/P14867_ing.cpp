#include <iostream>
#include <vector>
using namespace std;

int capA, capB, endA, endB;
int dp[1002][1002], visited[1002][1002];

vector<pair<int, int>> nextAmounts(int curA, int curB) {
    vector<pair<int, int>> v;
    if (curA != 0) v.push_back( {0, curB} );
    if (curB != 0) v.push_back( {curA, 0} );
    if (curA != capA) v.push_back( {capA, curB} );
    if (curB != capB) v.push_back( {curA, capB} );
    if (curA != 0 && curB != capB) {
        if (curA > capB - curB) v.push_back( {curA - (capB - curB), capB} );
        else v.push_back( {0, curB + curA} );
    }
    if (curB != 0 && curA != capA) {
        if (curB > capA - curA) v.push_back( {capA, curB - (capA - curA)} );
        else v.push_back( {curA + curB, 0} );
    }
    return v;
}

int dfs(int a, int b) {
    visited[a][b] = 1;
    if (a == endA && b == endB) return 0;

    int &result = dp[a][b];
    if (result != -1) return result;

    auto nextABs = nextAmounts(a, b);
    for (auto next : nextABs) {
        if (visited[next.first][next.second]) continue;
        if (result == -1) result = dfs(next.first, next.second);
        else result = min(result, dfs(next.first, next.second));
    }
    ++result;
    return result;
}

int main() {
    cin >> capA >> capB >> endA >> endB;
    fill(&dp[0][0], &dp[0][0] + 1002 * 1002, -1);

    visited[0][0] = 1;
    cout << dfs(0, 0);
}