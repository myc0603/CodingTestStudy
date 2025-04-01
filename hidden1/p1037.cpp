#include <iostream>
using namespace std;

// 약수
int main() {
    int n; cin >> n;
    if (n == 1) {
        int num; cin >> num;
        cout << num * num;
        return 0;
    }
    int mn = 1000000;
    int mx = 2;
    while (n--) {
        int num; cin >> num;
        mn = min(num, mn);
        mx = max(num, mx);
    }
    cout << mn * mx;
}