#include <iostream>
using namespace std;

const int MAX = 100003;
int n, m, tree[MAX], pos[MAX], before[MAX];

void update(int i, int val) {
    while (i <= n) {
        tree[i] += val;
        i += i & -i;
    }
}

int sum(int i) {
    int result = 0;
    while (i > 0) {
        result += tree[i];
        i -= i & -i;
    }
    return result;
}

int query(int from, int to) {
    if (from > to) return 0;
    return sum(to) - sum(from - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--)  {
        cin >> n >> m;

        for (int dvd = 1; dvd <= n; ++dvd) pos[dvd] = dvd - 1;
        fill(tree, tree + MAX, 0);
        fill(before, before + MAX, 0);

        for (int i = 1; i <= m; ++i) {
            int dvd; cin >> dvd;

            if (pos[dvd]) {
                update(dvd, 1);
                cout << pos[dvd] + query(dvd + 1, n) << ' ';
            } else {
                cout << i - before[dvd] - 1 << ' ';
            }

            pos[dvd] = 0;
            before[dvd] = i;
        }
        cout << '\n';
    }
}