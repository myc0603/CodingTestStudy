#include <bits/stdc++.h>
using namespace std;

int fare[4] = {};
int t1[2], t2[2], t3[2];
int main() {
    // init
    for (int i = 1; i <= 3; i++)
        cin >> fare[i];
    for (int i = 0; i < 2; i++)
        cin >> t1[i];
    for (int i = 0; i < 2; i++)
        cin >> t2[i];
    for (int i = 0; i < 2; i++)
        cin >> t3[i];
    
    int end = t1[1] > t2[1] ? t1[1] : t2[1];
    end = end > t3[1] ? end : t3[1];

    int parkedNum[end+1] = {};
    for (int i = t1[0] + 1; i <= t1[1]; i++) {
        parkedNum[i]++;
    }
    for (int i = t2[0] + 1; i <= t2[1]; i++) {
        parkedNum[i]++;
    }
    for (int i = t3[0] + 1; i <= t3[1]; i++) {
        parkedNum[i]++;
    }

    int tot = 0;
    for (int i = 2; i < end+1; i++) {
        tot += parkedNum[i] * fare[parkedNum[i]];
    }
    cout << tot;

    return 0;
}