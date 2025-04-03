#include <iostream>
#include <stack>
using namespace std;

int main() {
    string ans;
    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break;
        
        bool valid = true;
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '[') stk.push(c);
            else if (c == ')'){
                if (stk.empty() || stk.top() != '(') valid = false;
                else stk.pop();
            } else if (c == ']') {
                if (stk.empty() || stk.top() != '[') valid = false;
                else stk.pop();
            }
        }
        ans += valid && stk.empty() ? "yes\n" : "no\n";
    }
    cout << ans;
}