#include <bits/stdc++.h>
using namespace std;

int turnOffNthBit(int S, int n) {
    return S &= ~(1 << n);
}

int turnOnNthBit(int S, int n) {
    return S |= (1 << n);
}

int switchNthBit(int S, int n) {
    return S ^= (1 << n);
}

bool isNthBitOn(int S, int n) {
    return S & (1 << n);
}

int nBitsOn(int n) {
    return (1 << n) - 1;
}

int theLowestOnBitOf(int S) {
    return (S & -S);
}

int getDecimalOf(string b) {
    // 앞에 불필요한 0을 없애주는게 좋긴함
    int result = 0;
    int len = b.length();
    for (int i = len - 1; i >= 0; i--) {
        if (b[i] == '1') {
            result += (1 << (len - 1 - i));
        }
    }
    
    return result;
}

string getBinaryOf(int n) {
    string result = "";
    while (n) {
        result = to_string(n % 2) + result;
        n >>= 1;
    }
    return result;
}

int main() {
    int S = 18;
    cout << getBinaryOf(S) << '\n';
    cout << getBinaryOf(turnOnNthBit(S, 0)) << '\n';
    cout << getBinaryOf(turnOffNthBit(S, 1)) << '\n';
    cout << getBinaryOf(switchNthBit(S, 2)) << '\n';
    cout << (isNthBitOn(S, 1) ? "true" : "false") << '\n';
    cout << getBinaryOf(nBitsOn(5)) << '\n';
    cout << theLowestOnBitOf(S) << '\n';
}