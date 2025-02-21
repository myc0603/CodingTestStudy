#include <bits/stdc++.h>
using namespace std;

char encoded(char c) {
    if ('a' <= c && c <= 'z') {
        return (c - 'a' + 13) % 26 + 'a';
    }
    if ('A' <= c && c <= 'Z') {
        return (c - 'A' + 13) % 26 + 'A';
    }
    return c;
}

int main() {
    string s;
    cin >> s;
    string result;
    for (char c : s) {
        result += encoded(c);
    }
    cout << result << '\n';
}