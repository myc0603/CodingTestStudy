#include <iostream>
#include <vector>
using namespace std;

const string str = "Messi Gimossi";
vector<int> lens;

int main() {
    lens.push_back(5);
    lens.push_back(str.size());
    while (lens.back() <= (1 << 30)) {
        int idx = lens.size() - 1;
        int newlen = lens[idx] + 1 + lens[idx-1];
        lens.push_back(newlen);
    }

    int m; cin >> m;
    for (int i = lens.size() - 1; m > str.size(); --i) {
        if (m >= lens[i] + 1) m -= lens[i] + 1;
    }

    if (m == 0 || m == 6) cout << "Messi Messi Gimossi";
    else cout << str[m-1];
}