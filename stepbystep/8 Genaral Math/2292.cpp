#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;

    int cnt = 1;
    int t = 6;
    --n;
    while (n > 0) {
        n -= t;
        t += 6;
        ++cnt;
    }
    cout << cnt;
}