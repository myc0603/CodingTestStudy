#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int cand = 1;
    while (true) {
        if (cand == n) {
            cout << 0;
            break;
        }
        int temp = cand;
        int sum = temp;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == n) {
            cout << cand;
            break;
        }
        ++cand;
    }
}