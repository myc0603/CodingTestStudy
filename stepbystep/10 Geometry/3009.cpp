#include <iostream>
#include <set>
using namespace std;

multiset<int> setx, sety;

int main() {
    for (int i = 0; i < 3; ++i) {
        int x, y;
        cin >> x >> y;
        setx.insert(x);
        sety.insert(y);
    }

    for (auto x : setx) {
        if (setx.count(x) == 1) cout << x << ' ';
    }
    for (auto y : sety) {
        if (sety.count(y) == 1) cout << y;
    }
}