#include <bits/stdc++.h>
using namespace std;

int n = 9, k = 7;
int a[9];
int main() {
    int tot = 0;
    // int a[9] = {20, 7, 23, 19, 10, 15, 25, 8, 13};
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        tot += a[i];
    }
    
    // printf("tot: %d\n", tot);
    int a1, a2;
    for (int i = 0; i < 9; i++) {
        a1 = a[i];
        for (int j = i + 1; j < 9; j++) {
            a2 = a[j];
            if (tot - a1 - a2 == 100) {
                break;
            }
        }
        if (tot - a1 - a2 == 100) {
            break;
        }
    }
    // printf("a1: %d, a2: %d\n", a1, a2);

    vector<int> result = {};
    for (int i : a) {
        if (i == a1 || i == a2) {
            // printf("i: %d a1: %d, a2: %d\n", i, a1, a2);
            continue;
        }
        // printf("result.push_back(%d)\n", i);
        result.push_back(i);
    }
    sort(result.begin(), result.end());
    // cout << "sorted result print\n";
    for (int i : result) {
        cout << i << '\n';
    }

}