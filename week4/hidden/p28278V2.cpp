#include <iostream>
using namespace std;

// 스택 2
int stk[1000000], idx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    string ans;
    while (n--) {
        int command; cin >> command;
        if (command == 1) {
            int x; cin >> x;
            stk[idx++] = x;
        } else if (command == 2) {
            if (idx == 0) {
                ans += to_string(-1) + '\n';
                continue;
            }
            ans += to_string(stk[--idx]) + '\n';
        } else if (command == 3) {
            ans += to_string(idx) + '\n';
        } else if (command == 4) {
            ans += to_string(idx ? 0 : 1) + '\n';
        } else if (command == 5) {
            if (idx == 0) {
                ans += to_string(-1) + '\n';
                continue;
            }
            ans += to_string(stk[(idx-1)]) + '\n';
        }
    }
    cout << ans;
}