#include <bits/stdc++.h>
using namespace std;

// choose 7 using recursive combination func.
int sum(vector<int> v) {
    int sum = 0;
    for (int num : v) {
        sum += num;
    }
    return sum;
}

/**
 * combi함수는 만드는 벡터의 사이즈가 r이 될때까지 계속 뽑는데 그 전까지 
 * 돌아가면서 뽑음
 * @param idx 어떤 depth에서 어디서부터 뽑기 시작할지 정하는거
 * 이전 depth에서 뽑은 숫자가 다음 순서 숫자들 중에서 뽑아야됨
 * 매 depth에서 숫자를 뽑는 건 depth ~ n-1까지 루프를 돌면서 뽑기때문에
 * 각 루프에서 다음 껄 뽑기 위해 combi()를 호출할때는 depth에 그 루프에서 뽑은 숫자의 인덱스+1을
 * 넣어야됨 -> combi(from, to, n, r, i+1)
 */
void combi(int* from, vector<int> to, int n, int r, int idx) {
    if (to.size() == r && sum(to) == 100) {
        // do something
        for (int num : to) {
            cout << num << '\n';
        }
        exit(0);
    }

    for (int i = idx; i < n; i++) {
        to.push_back(from[i]);
        combi(from, to, n, r, i+1);
        to.pop_back();
    }
}

int main() {
    int a[9] = {};
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    sort(a, a+9);

    vector<int> to;
    combi(a, to, 9, 7, 0);
}