#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int ret = 1, cnt = 1;
        while (cnt != 0) {
            if (n == 1) break;
            cnt = cnt * 10 + 1;
            cnt %= n;
            ret++;
        }
        printf("%d\n", ret);
    }

    return 0;
}