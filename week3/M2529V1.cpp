#include <bits/stdc++.h>
using namespace std;

int k;
vector<char> signs;
vector<string> ans;

bool check(string nums) {

    int prev = nums[0] - '0';
    for (int i = 0; i < k; i++) {
        char sign = signs[i];
        int num = nums[i+1] - '0';

        if (sign == '<' && !(prev < num)) {
            return false;
        }
        if (sign == '>' && !(prev > num)) {
            return false;
        }
        prev = num;
    }
    return true;
}

void makePermutation(string s, int n, int r, int depth) {
    if (depth == r) {
        string temp = s.substr(0, k+1);
        if (check(temp)) {
            ans.push_back(temp);
        }
    }

    for (int i = depth; i < n; i++) {
        swap(s[i], s[depth]);
        makePermutation(s, n, r, depth + 1);
        swap(s[i], s[depth]);
    }
}

int main() {
    cin >> k;
    signs;
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        signs.push_back(c);
    }

    string source = "0123456789";
    makePermutation(source, 10, k + 1, 0);
    sort(ans.begin(), ans.end());

    cout << ans[ans.size()-1] << '\n';
    cout << ans[0] << '\n';
}