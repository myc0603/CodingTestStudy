#include <iostream>
#include <algorithm>
using namespace std;

int n, m, l, pos[53], lens[53], newLens[53], cnts[53];

int main() {
    cin >> n >> m >> l;
    for (int i = 0; i < n; ++i) cin >> pos[i];
    sort(pos, pos + n);

    lens[0] = pos[0];
    for (int i = 1; i < n; ++i) {
        lens[i] = pos[i] - pos[i-1];
    }
    lens[n] = l - pos[n-1];


    for (int i = 0; i <= n; ++i) newLens[i] = lens[i];

    while (m) {
        int maxIdx = max_element(newLens, newLens + n + 1) - newLens;
        ++cnts[maxIdx];
        newLens[maxIdx] = (lens[maxIdx] + cnts[maxIdx]) / (cnts[maxIdx] + 1);
        --m;
    }

    cout << *max_element(newLens, newLens + n + 1);
}