#include <iostream>
#include <stack>
using namespace std;

int k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    stack<int> stk;
    long long ans = 0;
    while (k--) {
        int x; cin >> x;
        if (x) {
            ans += x;
            stk.push(x);
        } else {
            ans -= stk.top();
            stk.pop();
        }
    }
    cout << ans;
}