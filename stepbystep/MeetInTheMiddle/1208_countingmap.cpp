#include <iostream>
// #include <unordered_map>
using namespace std;

const int BIAS = 2000000; // s - sum 절댓값의 범위가 최대 300만
int n, s, a[41] , countingmap[2*BIAS+1];
// unordered_map<int, long long> countingmap;
long long cnt;

void dfs1(int cur, int sum) {
    if (cur == n / 2) {
        ++countingmap[BIAS + sum];
        return;
    }
    dfs1(cur + 1, sum);
    dfs1(cur + 1, sum + a[cur]);
}

void dfs2(int cur, int sum) {
    if (cur == n) {
        if (abs(s - sum) <= BIAS) { // 이 조건을 위와 합치면 안 됨 return은 같이 안 묶이기 때문에
            cnt += countingmap[BIAS + (s - sum)];
        }
        return;
    }
    dfs2(cur + 1, sum);
    dfs2(cur + 1, sum + a[cur]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];

    dfs1(0, 0);
    dfs2(n / 2, 0);

    cout << cnt - (s == 0);
}