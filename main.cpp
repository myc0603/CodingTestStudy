#include <bits/stdc++.h>
using namespace std;

bool oddCheck(int* charCnt) {
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (charCnt[i] % 2 == 1) {
            oddCount++;
            if (oddCount > 1) {
                return false;
            }
        }
    }
    return true;
}

bool evenCheck(int* charCnt) {
    for (int i = 0; i < 26; i++) {
        if (charCnt[i] % 2 == 1) {
            return false;
        }
    }
    return true;
}

string makeEvenPalin(int* charCnt) {
    string result = "";

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < charCnt[i] / 2; j++) {
            result += (char) i + 'A';
        }
    }
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < charCnt[i] / 2; j++) {
            result += (char) i + 'A';
        }
    }
    return result;
}
string makeOddPalin(int* charCnt) {
    string result = "";
    int oddIndex = -1;
    for (int i = 0; i < 26; i++) {
        if (charCnt[i] % 2 == 1) {
            oddIndex = i;
        }
        for (int j = 0; j < charCnt[i] / 2; j++) {
            result += (char) i + 'A';
        }
    }
    result += (char) oddIndex + 'A';
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < charCnt[i] / 2; j++) {
            result += (char) i + 'A';
        }
    }
    return result;
}

int main() {
    string s;
    cin >> s;

    int charCnt[26] = {};
    for (char c : s) {
        int index = c - 'A';
        charCnt[index]++;
    }
    
    bool odd = s.size() % 2 == 1;
    bool palin = odd ? oddCheck(charCnt) : evenCheck(charCnt);
    if (!palin) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    string result = odd ? makeOddPalin(charCnt) : makeEvenPalin(charCnt);
    cout << result;
    return 0;
}