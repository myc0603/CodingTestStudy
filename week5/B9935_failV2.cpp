#include <bits/stdc++.h>
using namespace std;

string s, bomb;

int main() {
    cin >> s >> bomb;
    
    stack<string> stk;
    for (char c : s) {
        if (stk.empty()) {
            string str(1, c);
            stk.push(str);
            continue;
        }
        if (bomb.find(stk.top()) != string::npos) {
            stk.top() += c;
        }
    }
}