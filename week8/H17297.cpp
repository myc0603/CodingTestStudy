#include <iostream>
#include <vector>
using namespace std;

const string str1 = "Messi", str2 = "Messi Gimossi";
vector<int> lens;

int main() {
    lens.push_back(str1.size());
    lens.push_back(str2.size());
    while (lens.back() <= (1 << 30)) {
        int idx = lens.size() - 1;
        int newlen = lens[idx] + 1 + lens[idx-1];
        lens.push_back(newlen);
    }

    int m; cin >> m;
    bool isBlank = false;
    int idx = lens.size() - 2;
    while (m > lens[1]) {
        if (m <= lens[idx]) --idx;
        else if (m > lens[idx] + 1) {
            m -= lens[idx] + 1;
            idx -= 2;
        } else {
            cout << "Messi Messi Gimossi";
            return 0;
        }
    }

    char ans = str2[m-1];
    if (ans == ' ') cout << "Messi Messi Gimossi";
    else cout << ans;
}