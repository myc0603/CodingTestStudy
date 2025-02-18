#include <bits/stdc++.h>
using namespace std;

bool isGood(string s) {

}
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (isGood(s)) {
            cnt++;
        }
    }
    cout << cnt;
}