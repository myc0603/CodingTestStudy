#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[200002], b[200002];

bool intersection(int in_a) {
    int left = 0; int right = m - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (b[mid] == in_a) return true;
        if (b[mid] < in_a) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b, b + m);
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (intersection(a[i])) cnt++;
    }
    cout << n + m - 2 * cnt;
}