#include <iostream>
#include <algorithm>
using namespace std;

int n, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = -1000;
    cin >> n;
    while (n--) {
        int x; cin >> x;
        sum += x;
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }

    cout << ans;
}