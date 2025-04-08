#include <bits/stdc++.h>
using namespace std;

string s, bomb;

// bool, int return?
/**
 * @return 다음 인덱스
 */
int findBomb(int idx) {

    if (s.substr(idx, bomb.length()) == bomb) {
        s.erase(idx, bomb.length());
        return idx;
    }

    string temp;
    for (size_t _n = 1; _n < bomb.length(); _n++) {
        
        temp += s[idx + _n - 1];

        if (temp == bomb.substr(0, _n)) {

            // 폭발 문자열은 같은 문자를 두 개 이상 포함하지 않기 때문에 
            // s[idx+_n] == bombn[0]알 때 다음 temp가 bomb의 substr이 될 걱정은 하지 않아도 된다.
            if (s[idx+_n] == bomb[0]) {

                int result = findBomb(idx + _n);

                if (result == idx + _n) { // bomb찾아서 폭발
                    continue; // 이렇게 해서 _n이 bomb.length()까지 가면 s.erase하면 됨됨
                } else { // bomb 못 찾음
                    continue;
                }

            } else {
                continue;
            }

        } else {
            return idx + _n + 1;
        }
        
    }

    temp += s[idx + bomb.length() - 1];
    if (temp == bomb) {
        s.erase(idx, bomb.length());
        return idx;
    }
    return idx + bomb.length();
}

int main() {
    cin >> s >> bomb;

    for (int i = 0; i < s.length();) {
        if (s[i] == bomb[0]) i = findBomb(i);
        else i++;
    }

    cout << (s.empty() ? "FRULA" : s);
}