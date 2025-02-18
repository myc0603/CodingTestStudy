#include <bits/stdc++.h>
using namespace std;

/**
 * 문자열에 들어가는 문자가 영어 대문자로 한정지어져 있어서 쉽게 접근 가능
 * input 길이가 짝수이면 모든 글자가 짝수이면 가능
 * 홀수면 하나만 홀수고, 나머지 글자가 홀수면 가능
 */
bool oddCheck(int* charCnt) {
    cout << "call oddCheck\n";
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (charCnt[i] % 2 == 1) {
            cout << "odd charCnt[i]: " << charCnt[i] << '\n';
            oddCount++;
            if (oddCount > 1) {
                return false;
            }
        }
    }
    return true;
}

bool evenCheck(int* charCnt) {
    cout << "call evenCheck\n";
    for (int i = 0; i < 26; i++) {
        if (charCnt[i] % 2 == 1) {
            cout << "odd charCnt[i]: " << charCnt[i] << '\n';
            return false;
        }
    }
    return true;
}

string makeEvenPalin(int* charCnt) {
    string result = "";

    for (int i = 0; i < 26; i++) {
        cout << "charCnt[" << i << "]: " << charCnt[i] << '\n';
        for (int j = 0; j < charCnt[i] / 2; j++) {
            result += (char) i + 'A';
        }
    }
    for (int i = 25; i >= 0; i--) {
        cout << "charCnt[" << i << "]: " << charCnt[i] << '\n';
        for (int j = 0; j < charCnt[i] / 2; j++) {
            result += (char) i + 'A';
        }
    }
    return result;
}
string makeOddPalin(int* charCnt) {
    // 위와 같은 과정을 반복하는데 개수가 odd인 알파벳 인덱스 기록해놨다가 중간에 추가해야됨
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
    
    for (int i : charCnt) {
        cout << i;
    }
    cout << '\n';
    
    bool odd = s.size() % 2 == 1;
    bool palin = odd ? oddCheck(charCnt) : evenCheck(charCnt);
    if (!palin) {
        cout << "I'm Sorry Hansoo";
        return 0;
    } else {
        cout << "palin SSAP POSSIBLE\n";
    }

    // make palindrom
    string result = odd ? makeOddPalin(charCnt) : makeEvenPalin(charCnt);
    cout << result;
    return 0;
}