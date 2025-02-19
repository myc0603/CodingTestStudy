#include <bits/stdc++.h>
using namespace std;
int fare[4], cnt[100], t1, t2, tot;
int main() {
    cin >> fare[1] >> fare[2] >> fare[3];
    for (int i = 0; i < 3; i++) {
        cin >> t1 >> t2;
        for (int j = t1; j < t2; j++) cnt[j]++;
    }
    for (int num : cnt) tot += num * fare[num];
    cout << tot;
    return 0;
}