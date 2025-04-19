#include <iostream>
using namespace std;

int n, m, lessons[100003];

bool check(int disk_size) {
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        sum += lessons[i];
        if (sum > disk_size) {
            if (lessons[i] > disk_size) return false;
            sum = lessons[i];
            cnt++;
            if (cnt > m) return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        cin >> lessons[i];
        left = max(left, lessons[i]);
        right += lessons[i];
    }
    left--;

    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }

    cout << right;
}