#include <iostream>
using namespace std;

int n, a[502][502];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            a[i][j] += max(a[i+1][j], a[i+1][j+1]);
        }
    }
    cout << a[0][0];
}