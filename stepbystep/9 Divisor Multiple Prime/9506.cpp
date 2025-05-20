#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int n; cin >> n;
        if (n == -1) break;

        int sum = 0;
        vector<int> divisors;
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                sum += i;
                divisors.push_back(i);
            }
        }

        bool isPerfect = sum == n;
        if (isPerfect) {
            cout << n << " = ";
            for (int i = 0; i < divisors.size() - 1; ++i) {
                cout << divisors[i] << " + ";
            }
            cout << divisors.back() << '\n';
        } else cout << n << " is NOT perfect.\n";
    }
}