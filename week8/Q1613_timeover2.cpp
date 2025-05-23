#include <iostream>
#include <unordered_set>
using namespace std;

int n, k, s;
unordered_set<int> greaterThan[401], lessThan[401];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;

        greaterThan[a].insert(b);
        lessThan[b].insert(a);
        for (int les : lessThan[a]) {
            greaterThan[les].insert(b);
            lessThan[b].insert(les);
        }
        for (int gre : greaterThan[b]) {
            greaterThan[a].insert(gre);
            lessThan[gre].insert(a);
        }
        for (int les : lessThan[a]) {
            for (int gre : greaterThan[b]) {
                greaterThan[les].insert(gre);
                lessThan[gre].insert(les);
            }
        }

        cout << "\ngreater\n";
        for (int i = 1; i <= 8; ++i) {
            cout << i << ": ";
            for (int x : greaterThan[i]) cout << x << ' ';
            cout << '\n';
        }
        cout << "less\n";
        for (int i = 1; i <= 8; ++i) {
            cout << i << ": ";
            for (int x : lessThan[i]) cout << x << ' ';
            cout << '\n';
        }
    }

    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;

        if (greaterThan[a].count(b)) cout << -1 << '\n';
        else if (greaterThan[b].count(a)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

/*
반례
8 4
8 4
5 3
5 2
4 5
1
2 8
 */