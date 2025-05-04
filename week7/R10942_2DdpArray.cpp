#include <iostream>
using namespace std;

int n, m, nums[2003], isPelin[2003][2003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        if (i > 2) {
            for (int j = 1; j <= i - 2; ++j) {
                if (nums[i] == nums[j] && isPelin[j+1][i-1]) {
                    isPelin[j][i] = 1;
                }
            }
        }

        if (i > 1 && nums[i] == nums[i-1]) isPelin[i-1][i] = 1;
        isPelin[i][i] = 1;
    }

    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << (isPelin[s][e] ? 1 : 0) << '\n';
    }
}