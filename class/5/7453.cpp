#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 4002;
int n, a[4][SIZE], sum[2][SIZE*SIZE];
long long cnt;

void buildSumArray(int sumArrIdx) {
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum[sumArrIdx][index++] = a[2*sumArrIdx][i] + a[2*sumArrIdx+1][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[j][i];
        }
    }

    buildSumArray(0);
    buildSumArray(1);

    int N = n * n;
    sort(sum[0], sum[0] + N);
    sort(sum[1], sum[1] + N);

    for (int i = 0; i < N; ++i) {
        int val = -sum[0][i];
        auto lit = lower_bound(sum[1], sum[1] + N, val);
        auto uit = upper_bound(sum[1], sum[1] + N, val);
        cnt += uit - lit;
    }

    // int i = 0;
    // while (i < N) {
    //     int val = sum[0][i];
    //     int cnt1 = upper_bound(sum[0], sum[0] + N, val) - lower_bound(sum[0], sum[0] + N, val);
    //     int cnt2 = upper_bound(sum[1], sum[1] + N, -val) - lower_bound(sum[1], sum[1] + N, -val);
    //     cnt += (long long) cnt1 * cnt2;
    //     i += cnt1;
    // }

    cout << cnt;
}