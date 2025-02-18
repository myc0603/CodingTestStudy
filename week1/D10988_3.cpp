#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    // len even 딱 거꾸로 매칭해서 같으면 ok
    // len odd  가운데 글자 확인 불필요!!
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len-1-i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}