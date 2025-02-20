#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 1) {
            printf("%d\n", 1);
            continue;
        }
        int ret = 1;
        int rem = 1; // = 1 % n
        long long cnt = 1;
        while (rem != 0) {
            cnt *= 10;
            rem += cnt % n;
            rem %= n;
            ret++;
        }
        printf("%d\n", ret);
    }

    return 0;
}