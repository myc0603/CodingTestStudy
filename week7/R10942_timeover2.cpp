#include <iostream>
#include <set>
using namespace std;

int n, m, nums[2001];
set<pair<int, int>> evenPelins, oddPelins;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        if (i > 2) {
            for (int j = 1; j <= i - 2; ++j) {
                if (nums[i] == nums[j]) {
                    pair<int, int> p = {j + 1, i - 1};
                    if ((i + j) % 2 == 0) { // oddPelin
                        if (oddPelins.find(p) != oddPelins.end()) {
                            oddPelins.erase(p);
                            oddPelins.insert({j, i});
                        }
                    } else { // evenPelins
                        if (evenPelins.find(p) != evenPelins.end()) {
                            evenPelins.erase(p);
                            evenPelins.insert({j, i});
                        }
                    }
                }
            }
        }

        if (i > 1 && nums[i] == nums[i-1]) evenPelins.insert({i - 1, i});
        oddPelins.insert({i, i});
    }

    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        bool isPelin = false;
        while (s <= e) {
            if ((s + e) % 2 == 0) { // odd pelin
                if (oddPelins.find({s, e}) != oddPelins.end()) isPelin = true;
            } else {
                if (evenPelins.find({s, e}) != evenPelins.end()) isPelin = true;
            }
            ++s; --e;
        }
        cout << (isPelin ? 1 : 0) << '\n';
    }
}