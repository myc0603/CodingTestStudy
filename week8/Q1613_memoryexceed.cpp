#include <iostream>
#include <vector>
using namespace std;

int n, k, s;
vector<int> greaterThan[401], lessThan[401];

bool contain(const vector<int> &v, int value) {
    for (int x : v) {
        if (x == value) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;

        greaterThan[a].push_back(b);
        lessThan[b].push_back(a);
        for (int les : lessThan[a]) {
            greaterThan[les].push_back(b);
            lessThan[b].push_back(les);
        }
        for (int gre : greaterThan[b]) {
            greaterThan[a].push_back(gre);
            lessThan[gre].push_back(a);
        }
    }

    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        if (contain(greaterThan[a], b)) { // a < b
            cout << -1 << '\n';
        } else if (contain(greaterThan[b], a)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}