#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> subExIndices;

void combi(int n, vector<pair<int, int>> &to, int idx) {
    for (auto p : to) {
        subExIndices.push_back(to);
    }

    for (int i = idx; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pair<int, int> p = {i, j};
            to.push_back(p);
            combi(n, to, j + 1);
            to.pop_back();
        }
    }
}

int calculate(string expression) {
    stack<int> nums;

    int len = expression.size();
    
    int start;
    int firstNumber;
    if (expression[0] == '(') {
        int end = expression.find(')');
        string subExpression = expression.substr(1, end - 1);
        // cout << "subExpression: " << subExpression << '\n';

        firstNumber = calculate(subExpression);
        // cout << "result of subExpression: " << firstNumber << '\n';

        start = subExpression.size() + 2;
        // cout << "expression[i]: " << expression[start] << '\n';
    } else {
        start = 1;
        firstNumber = expression[0] - '0';
    }
    nums.push(firstNumber);
    for (int i = start; i < len; i += 2) {
        int num;
        char op = expression[i];
        if (expression[i+1] == '(') {
            int end = expression.find(')', i);
            string subExpression = expression.substr(i + 2, end - i - 2);
            // cout << "subExpression: " << subExpression << '\n';

            num = calculate(subExpression);
            // cout << "result of subExpression: " << num << '\n';

            i += subExpression.size() + 1;
            // cout << "expression[i]: " << expression[i] << '\n';
        } else {
            num = expression[i+1] - '0';
        }
        if (op == '*') {
            // cout << "num: " << num << '\n';
            num = nums.top() * num;
            // cout << "num: " << num << '\n';
            // cout << "popped number: " << nums.top() << '\n';
            nums.pop();
        } else if (op == '-') {
            num = -1 * num;
        }
        // cout << "pushed number: " << num << '\n';
        nums.push(num);
    }

    int result = 0;
    while (nums.size()) {
        result += nums.top();
        nums.pop();
    }
    return result;
}

int main() {
    int n; cin >> n;
    string expression; cin >> expression;

    vector<pair<int, int>> to;
    combi((n + 1) / 2, to, 0);

    // cout << calculate(expression) << '\n';
    vector<int> ans;
    int result = calculate(expression);
    // cout << "result: " << result << '\n';
    ans.push_back(result);
    for (auto v : subExIndices) {

        // print v
        // cout << "print subExpression indices\n";
        // for (auto p : v) {
        //     cout << p.first << ',' << p.second << '\n';
        // }
        string temp = expression;
        for (int i = v.size() - 1; i >= 0; i--) {
            int start = 2 * v[i].first;
            int end = 2 * v[i].second + 1;
            temp.insert(temp.begin() + end, ')');
            temp.insert(temp.begin() + start, '(');
            // cout << "insert (, ) -> " << temp << '\n';
        }

        // cout << temp << '\n';
        // result = max(calculate(expression), result);
        int result = calculate(temp);
        // cout << "result: " << result << '\n';
        ans.push_back(result);
    }
    // cout << result << '\n';
    // for (int num : ans) {
    //     cout << num << ' ';
    // }
    // cout << '\n';
    cout << *max_element(ans.begin(), ans.end()) << '\n';
}