#include <bits/stdc++.h>
using namespace std;

bool matchPattern(string pattern, string input) {
    // split
    int index = pattern.find('*');
    string front = pattern.substr(0, index);
    string back = pattern.substr(index + 1);
    cout << front << " | " << back << '\n';
    // input에서 back의 위치는 front보다 뒤여야 한다.
    // -> backPos는 front.size()보다 커야됨
    if (input.size() < front.size() + back.size()) {
        return false;
    }
    cout << "position of front: " << input.find(front) << '\n';
    if (input.find(front) != 0) {
        return false;
    }
    // input.find(back) 할때 뒤에서부터 찾아야됨
    int backPos = input.size() - back.size();
    cout << "position of back: " << input.find(back, backPos) << '\n';
    cout << "back has to be on: " << backPos << '\n';
    if (input.find(back, backPos) != backPos) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string pattern;
    cin >> pattern;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string output = matchPattern(pattern, s) ? "DA" : "NE";
        // 연속으로 계속 출력해야 할 때는 '\n'...추가....
        // 아니면 습관적으로 하는게 나을 듯
        cout << output << '\n';
    }
}