#include <iostream>
using namespace std;

const int MOD = 1e9 + 7, MAX = 200000;
int n, cntTree[MAX+1];
long long ans = 1, tree[MAX+1];

void update(int i, int val) {
    while (i <= MAX) {
        ++cntTree[i];
        tree[i] += val;
        i += i & -i;
    }
}

pair<long long, int> query(int i) {
    long long dis = 0;
    int cnt = 0;
    while (i > 0) {
        dis += tree[i];
        cnt += cntTree[i];
        i -= i & -i;
    }
    return {dis, cnt};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int first;
    cin >> first;
    ++first;
    update(first, first);
    for (int i = 1; i < n; ++i) {
        int pos; cin >> pos;
        ++pos;

        auto left = query(pos - 1);
        auto total = query(MAX);
        auto right = query(pos);

        long long leftSum = left.first; int leftCnt = left.second;
        long long rightSum = total.first - right.first; int rightCnt = total.second - right.second;

        long long totDis = (1LL * pos * leftCnt - leftSum) % MOD + (rightSum - 1LL * pos * rightCnt) % MOD;
        totDis %= MOD;
        ans = (totDis * ans) % MOD;

        update(pos, pos);
    }
    cout << ans;
}   