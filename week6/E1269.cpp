#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        b.insert(x);
    }

    int cnt = 0;
    for (int num : a) {
        if (b.find(num) == b.end()) cnt++;
    }
    for (int num : b) {
        if (a.find(num) == a.end()) cnt++;
    }

    cout << cnt;
}