#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string temp = s;
    reverse(temp.begin(), temp.end());
    bool ans = s == temp ? true : false;
    cout << ans << '\n';
}