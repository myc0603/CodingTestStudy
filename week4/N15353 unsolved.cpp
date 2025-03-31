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
    bool moreThan10 = false;
    for (int idx = 0; idx < longLen; idx++) {
        int temp = bigNum[idx] - '0';
        if (idx < shortLen) temp += smallNum[idx] - '0';

        if (moreThan10) temp++;
        if (temp >= 10) {
            moreThan10 = true;
            temp -= 10;
        } else {
            moreThan10 = false;
        }

        ans = to_string(temp) + ans;
    }
    if (moreThan10) ans = to_string(1) + ans;

    cout << ans << '\n';
}