#include <iostream>
using namespace std;

int requiredSticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string minDp[102], maxDp[102], minDpReverse[102];

bool operator<(const string &s1, const string &s2) {
    if (s1.size() == s2.size()) {
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) continue;
            return s1[i] < s2[i];
        }
        return false;
    }
    return s1.size() < s2.size();
}

// minDp, minDpReverse 비교 -> 같음
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(minDp, minDp + 102, string(50, '9'));
    fill(minDpReverse, minDpReverse + 102, string(50, '9'));
    // for (int i = 0; i <= 9; ++i) { // 0 포함
    for (int i = 1; i <= 9; ++i) { // 0 포함 x
        int cnt = requiredSticks[i];
        minDp[cnt] = min(minDp[cnt], to_string(i));
        minDpReverse[cnt] = min(minDpReverse[cnt], to_string(i));
    }

    for (int j = 2; j <= 100; ++j) {
        // for (int i = 0; i <= 9; ++i) { // 0 포함
        for (int i = 1; i <= 9; ++i) { // 0 포함 x
            int cnt = requiredSticks[i];
            if (j < cnt) continue;

            string s = minDp[j-cnt] + to_string(i);
            if (s < minDp[j]) minDp[j] = s;

            s = to_string(i) + minDpReverse[j-cnt];
            if (s < minDpReverse[j]) minDpReverse[j] = s;

            s = maxDp[j-cnt] + to_string(i);
            if (maxDp[j] < s) maxDp[j] = s;
        }
    }

    for (int i = 2; i <= 100; ++i) {
        cout << minDp[i] << ' ' << minDpReverse[i] << '\n';
    }
}