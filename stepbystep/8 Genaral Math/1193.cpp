#include <iostream>
using namespace std;
int x, idx, sum;
int main() {
    cin >> x;
    while (sum < x) {
        ++idx;
        sum += idx;
    }

    sum -= idx;
    int nu = x - sum;
    int de = idx + 1 - nu;
    if (idx % 2) swap(de, nu);
    cout << nu << '/' << de;
}