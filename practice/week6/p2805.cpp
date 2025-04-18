#include <iostream>
#include <algorithm>
using namespace std;

int n, m, trees[1000002];

bool check(int height) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += max(trees[i] - height, 0);
    }
    
    return total >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> trees[i];

    int low = 0;
    int high = 1e9;
    while (low + 1 < high) {
        int mid = (low + high) / 2;
        
        // check(mid) == true == check(low)
        if (check(mid)) low = mid;
        else high = mid;
    }
    cout << low;
}