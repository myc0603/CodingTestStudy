#include <bits/stdc++.h>
using namespace std;

char encodeChar(char c) {
    if ('a' <= c && c <= 'z') {
        // cout << "small\n";
        char newChar = ((c - 'a') + 13) % 26 + 'a';
        return newChar;
    }

    if ('A' <= c && c <= 'Z') {
        // cout << "capital\n";
        char newChar = ((c - 'A') + 13) % 26 + 'A';
        return newChar;
    }
    // cout << "not alphabet\n";
    return c;
}

int main() {

    // for (int i = 0; i < 128; i++) {
    //     cout << encodeChar(i) << ' ';
    // }
    // cout << '\n';

    for (char i = 0; i < 127; i++) {
        if (i == 127 || i == 128 || i == 0) {
            cout << (int) i << endl;
        }
    }
    char i = 127;
    cout << (int) i << ": " << i << '\n';
    i++;
    cout << (int) i << ": " << i << '\n';

}