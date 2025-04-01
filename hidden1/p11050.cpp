#include <iostream>
using namespace std;

// 이항 계수
int main() {
    int n, k; cin >> n >> k;
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n--) / i;
    }
    cout << result;
}