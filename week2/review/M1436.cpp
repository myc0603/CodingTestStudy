#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    for (int i = 666; n; i++) {
        if (to_string(i).find("666") != string::npos) n--;
        if (!n) cout << i << '\n';
    }
}