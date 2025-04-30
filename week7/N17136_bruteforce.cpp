#include <iostream>
#include <vector>
using namespace std;

int a[15][15], minCnt, ans = 30, counts[6];
vector<pair<int, int>> toBeCovered;

int maxSize(int y, int x) {
    int size = 5;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (a[y+i][x+j] != 1) {
                size = max(i, j);
            }
        }
    }
    return size;
}

void cover(int y, int x, int cnt, int val) {
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            a[y+i][x+j] = val;
        }
    }
}

void checkAnswer() {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += counts[i];
    }
    ans = min(ans, sum);
}

void dfs2(int idx) {
    if (idx == toBeCovered.size()) {
        checkAnswer();
        return;
    }

    if (ans == minCnt) return;

    int i = idx;
    for (; i < toBeCovered.size(); ++i) {
        if (a[toBeCovered[i].first][toBeCovered[i].second] == 1) break;
    }
    if (i == toBeCovered.size()) {
        checkAnswer();
        return;
    }
    int y = toBeCovered[i].first;
    int x = toBeCovered[i].second;
    for (int j = maxSize(y, x); j >= 1;--j) {
        if (counts[j] == 5) continue;
        cover(y, x, j, 2);
        counts[j]++;
        dfs2(idx + 1);
        cover(y, x, j, 1);
        counts[j]--;
    }

}

int main() {
    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                toBeCovered.push_back( {i, j} );
                cnt++;
            }
        }
    }

    int t = 5;
    while (cnt) {
        minCnt += cnt / (t * t);
        cnt /= t * t;
        --t;
    }    

    dfs2(0);
    if (ans == 30) cout << -1;
    else cout << ans;
}