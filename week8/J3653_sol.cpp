#include <iostream>
using namespace std;

int n, m, tree[200003], pos[100003];

void update(int i, int val) {
    while (i <= n + m) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--)  {
        cin >> n >> m;

        fill(tree, tree + 200003, 0);
        for (int i = 1; i <= n; ++i) update(m + i, 1);
        for (int dvd = 1; dvd <= n; ++dvd) pos[dvd] = m + dvd;

        int update_idx = m;
        for (int i = 1; i <= m; ++i) {
            int dvd; cin >> dvd;
            int cur_pos = pos[dvd];

            cout << sum(cur_pos - 1) << ' ';

            update(cur_pos, -1);
            update(update_idx, 1);
            pos[dvd] = update_idx--;
        }
        cout << '\n';
    }
}