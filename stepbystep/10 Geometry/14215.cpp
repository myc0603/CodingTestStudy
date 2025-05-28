#include <iostream>
using namespace std;
int a, b, c;
int main() {
    cin >> a >> b >> c;
    int tot = a + b + c;
    int mx = max(a, max(b, c));
    int len2 = tot - mx;
    if (mx < len2) cout << tot;
    else cout << tot - (mx - len2 + 1);
}