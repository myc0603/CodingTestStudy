#include <bits/stdc++.h>
using namespace std;

int k;
vector<char> signs;
string ans;
bool found;

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
    if (found) return;
    if (depth == r) {
        string temp = s.substr(0, k);
        if (check(temp)) {
            ans = temp;
            found = true;
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
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        signs.push_back(c);
    }

    k++;

    string minSource = "0123456789";
    string maxSource = "9876543210";

    makePermutation(maxSource.substr(0, k), k, k, 0);
    cout << ans << '\n';

    found = false;
    makePermutation(minSource.substr(0, k), k, k, 0);
    cout << ans << '\n';
}