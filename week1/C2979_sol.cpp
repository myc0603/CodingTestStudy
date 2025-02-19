#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int cnt[100] = {};

    for (int i = 0; i < 3; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        // t1+1 ~ t2 or t1 ~ t2-1
        for (int j = t1; j < t2; j++) {
            cnt[j]++;
        }
    }

    int tot = 0;
    for (int num : cnt) {
        if (num == 1) tot += a;
        else if (num == 2) tot += 2*b;
        else if (num == 3) tot += 3*c;
    }
    cout << tot;
    return 0;
}