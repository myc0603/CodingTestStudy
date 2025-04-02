#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    int mx = 0;
    vector<int> scores;
    for (int i = 0; i < n; i++) {
        int score; cin >> score;
        mx = score > mx ? score : mx;
        scores.push_back(score);
    }
    double sum = 0;
    for (double score : scores) {
        sum += (score / mx) * 100;
    }
    cout << sum / n << '\n';
}