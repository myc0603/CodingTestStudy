#include <bits/stdc++.h>
using namespace std;

int n, k, words[50];
int ans;

string getIncludingChars(int n) {
    string binary;
    while (n) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    
    string result;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            result += (char) (binary.length()-i-1 + 'a');
            result += ' ';
        }
    }
    return result;
}

int count(int learnedChars) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((words[i] | learnedChars) == learnedChars) cnt++;
        // if ((words[i] & learnedChars) == words[i]) cnt++;
    }
    return cnt;
}

/**
 * 26개 알파벳중에서 k개를 뽑아서 words중에서 갯수세기
 * @param idx
 * @param learnedChars 배운 글자들
 * @param cnt 지금까지 뽑은 배운 글자 수
 */
void combi(int idx, int learnedChars, int cnt) {
    if (cnt > k || idx > 26) return;
    if (cnt == k) {
        int temp = count(learnedChars);
        // cout << getIncludingChars(learnedChars) << " -> " << temp << '\n';
        ans = max(ans, temp);
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (i == 'a'-'a' || i == 'c'-'a' || i == 'i'-'a' || i == 'n'-'a' || i == 't'-'a') {
            continue;
        }
        combi(i + 1, learnedChars | (1 << i), cnt + 1);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s) {
            int charIdx = c - 'a';
            words[i] |= (1 << charIdx);
        }
    }

    int learnedChars = 0;
    learnedChars |= (1 << ('a' - 'a'));
    learnedChars |= (1 << ('c' - 'a'));
    learnedChars |= (1 << ('i' - 'a'));
    learnedChars |= (1 << ('n' - 'a'));
    learnedChars |= (1 << ('t' - 'a'));
    combi(0, learnedChars, 5);

    cout << ans << '\n';
}