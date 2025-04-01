#include <iostream>
#include <stack>
using namespace std;

// 스택 2
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    stack<int> stk;
    string ans;
    while (n--) {
        int command; cin >> command;
        if (command == 1) {
            int x; cin >> x;
            stk.push(x);
        } else if (command == 2) {
            if (stk.empty()) {
                ans += to_string(-1) + '\n';
                continue;
            }
            ans += to_string(stk.top()) + '\n';
            stk.pop();
        } else if (command == 3) {
            ans += to_string(stk.size()) + '\n';
        } else if (command == 4) {
            ans += to_string(stk.empty()) + '\n';
        } else if (command == 5) {
            if (stk.empty()) {
                ans += to_string(-1) + '\n';
                continue;
            }
            ans += to_string(stk.top()) + '\n';
        }
    }
    cout << ans;
}