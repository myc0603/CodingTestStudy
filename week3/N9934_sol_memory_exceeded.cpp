#include <bits/stdc++.h>
using namespace std;

int k, a[1024], nodeCnt;
vector<int> tree[11];

void go(int start, int end, int level) {
    if (start > end) return;
    if (start == end) {
        tree[level].push_back(a[start]);
        return;
    }

    int mid = (start + end) / 2;
    tree[level].push_back(a[mid]);
    go(start, mid - 1, level + 1);
    go(mid + 1, end, level + 1);
}

int main() {
    cin >> k;
    nodeCnt = pow(2, k) - 1;
    for (int i = 0; i < nodeCnt; i++) {
        cin >> a[i];
    }

    go(0, nodeCnt, 1);
    for (int level = 1; level <= k; level++) {
        for (int num : tree[level]) {
            cout << num << ' ';
        }
        cout << '\n';
    }
}