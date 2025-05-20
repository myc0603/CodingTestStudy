#include <iostream>
using namespace std;
int n, k;
int main() {
    cin >> n >> k;
    int i = 1;
    for (; i <= n; ++i) {
        if (n % i == 0) --k;
        if (k == 0) break;
        if (i == n) {
            i = 0;
            break;
        }
    }
    cout << i;
}