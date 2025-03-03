#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> subExIndices;

int calculate(string expression) {
    stack<int> nums;
    stack<char> ops;

    int len = expression.size();
    nums.push(expression[0] - '0');
    for (int i = 1; i < len; i += 2) {
        if (expression[i] == '*') {
            int num = nums.top() * (expression[i+1] - '0');
            nums.pop();
            nums.push(num);
        } else {
            nums.push(expression[i+1] - '0');
            ops.push(expression[i]);
        }
    }

    stack<int> newNums;
    stack<char> newOps;
    while (nums.size()) {
        newNums.push(nums.top());
        nums.pop();
    }
    while (ops.size()) {
        newOps.push(ops.top());
        ops.pop();
    }

    int result = newNums.top(); newNums.pop();
    while (newNums.size()) {
        if (newOps.top() == '+') {
            result += newNums.top();
        } else {
            result -= newNums.top();
        }
        newNums.pop(); newOps.pop();
    }

    return result;
}

void combi(int n, vector<pair<int, int>> &to, int idx) {
    // cout << "print vector<pair> to\n";
    for (auto p : to) {
        subExIndices.push_back(to);

        // cout << p.first << ',' << p.second << '\n';
    }

    for (int i = idx; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pair<int, int> p = {i, j};
            // cout << "  push_back(i,j): " << i << ',' << j << '\n';
            to.push_back(p);
            combi(n, to, j + 1);
            // cout << "  pop_back(i,j): " << i << ',' << j << '\n';
            to.pop_back();
        }
    }
}

int main() {
    int n; cin >> n;
    string expression; cin >> expression;

    vector<pair<int, int>> to;
    combi((n + 1) / 2, to, 0);
    // combi(5, to, 0);

    int result = calculate(expression);
    for (auto v : subExIndices) {

        // print v
        cout << "print subExpression indices\n";
        for (auto p : v) {
            cout << p.first << ',' << p.second << '\n';
        }
        string temp = expression;
        for (int i = v.size() - 1; i >= 0; i--) {
            int start = 2 * v[i].first;
            int end = 2 * v[i].second + 1;
            string s = temp.substr(start, end - start);
            
            cout << " string s: " << s << '\n';


            int num = calculate(s);
            cout << " calculate subEx, num=" << num << '\n';
            cout << " before replace: " << temp << '\n';
            cout << "  start, end: " << start << ',' << end << '\n';
            temp.replace(temp.begin() + start, temp.begin() + end, to_string(num));
            cout << " after replace: " << temp << '\n';
        }

        cout << temp << '\n';
        // result = max(calculate(expression), result);
    }
    cout << result << '\n';
}