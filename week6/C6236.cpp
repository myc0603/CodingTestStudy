#include <iostream>
#include <algorithm>
using namespace std;

int n, m, consume_amounts[100003];

bool check(int amount) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += consume_amounts[i];
        if (sum > amount) {
            sum = consume_amounts[i];
            cnt++;
            if (cnt > m) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int left = 0, right = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> consume_amounts[i];

        left = max(left, consume_amounts[i]); // min -> max
        right += consume_amounts[i];
    }
    left--;

    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }

    cout << right;
}