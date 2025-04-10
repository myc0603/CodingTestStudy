#include <bits/stdc++.h>
using namespace std;

string s, bomb;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> bomb;

    // 사실 그냥 temp가 스택역할
    // 스택으로 푸는거랑 논리는 똑같음
    string temp;
    for (auto c : s) {
        temp += c;
        if (temp.size() < bomb.size()) continue;
        size_t idx = temp.size() - bomb.size(); // size_t로 해서 음수가 될 때 런타임 에러 확인하는 것도 하나의 방법일지도?
        if (temp.substr(idx, bomb.size()) == bomb) temp.erase(idx, bomb.size());
    }

    cout << (temp.empty() ? "FRULA" : temp);
}