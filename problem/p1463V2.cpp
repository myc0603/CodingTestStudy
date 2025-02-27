#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dis[n+1] = {};
    for (int i = 2; i <= n; i++) {
        dis[i] = dis[i-1] + 1;
        if (i % 2 == 0) dis[i] = min(dis[i/2] + 1, dis[i]);
        if (i % 3 == 0) dis[i] = min(dis[i/3] + 1, dis[i]);
    }
    cout << dis[n] << '\n';
}