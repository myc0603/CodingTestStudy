#include <bits/stdc++.h>
using namespace std;

int n;

int calculate(string exp) {
    // cout << "call calculate expression: " << exp << '\n';
    int result;
    int start;
    if (exp[0] == '(') {
        result = calculate(exp.substr(1, 3));
        start = 5;
    } else {
        result = exp[0] - '0';
        start = 1;
    }
    
    // cout << "  first number: " << result << '\n';
    for (int i = start; i < exp.length(); i += 2) {
        char op = exp[i];
        int cur;
        if (exp[i+1] == '(') {
            cur = calculate(exp.substr(i+2, 3));
            i += 4;
        } else {
            cur = exp[i+1] - '0';
        }

        // cout << "  op: " << op << ", cur: " << cur << '\n';
        // cout << "  -> " << result << op << cur << " = ";

        if (op == '+') {
            result += cur;
        } else if (op == '-') {
            result -= cur;
        } else if (op == '*') {
            result *= cur;
        } else {
            cout << "   op: " << op << " -> wrong operator\n";
        }
        // cout << result << '\n';
    }

    // cout << "return calculate()======\n\n";
    return result;
}

void insertParentheses(string s, vector<string> &v, int index) {
    v.push_back(s);

    for (int i = index; i >= 3; i -= 2) {
        s.insert(s.begin() + i, ')');
        s.insert(s.begin() + i - 3, '(');
        insertParentheses(s, v, i - 4);
        s.erase(s.begin() + i + 1);
        s.erase(s.begin() + i - 3);
    }
}

int main() {
    string s;
    cin >> n >> s;

    vector<string> newExps;
    insertParentheses(s, newExps, n);
    vector<int> ans;
    for (string exp : newExps) {
        int num = calculate(exp);
        // cout << exp << ": " << num << '\n';
        ans.push_back(num);
    }

    cout << *max_element(ans.begin(), ans.end()) << '\n';

}