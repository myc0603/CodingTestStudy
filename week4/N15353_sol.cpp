#include <bits/stdc++.h>
using namespace std;

int main() {
    string smallNum, bigNum; cin >> smallNum >> bigNum;

    reverse(smallNum.begin(), smallNum.end());
    reverse(bigNum.begin(), bigNum.end());
    
    int shortLen = smallNum.length();
    int longLen = bigNum.length();
    if (shortLen > longLen) {
        swap(smallNum, bigNum);
        swap(shortLen, longLen);
    }
    
    string ans;
    int temp = 0;
    for (int idx = 0; idx < longLen; idx++) {
        temp += bigNum[idx] - '0';
        if (idx < shortLen) temp += smallNum[idx] - '0';
        ans += to_string((temp % 10));
        temp /= 10;
    }
    if (temp) ans += to_string(1);

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}