#include <iostream>
#include <queue>
using namespace std;

// DP로 풀기~~!!

int n, m, a[502][502], dp[502][502][5];
int dy[] = {1, 0, 0};
int dx[] = {0, 1, -1};

// dp[i][j][4]
// dp[i+1][j][2]