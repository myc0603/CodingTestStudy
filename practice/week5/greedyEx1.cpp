#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> objects;
vector<int> bags;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

// sol -> priorit_queue 사용 좀 다름
int main() {
    cin >> n >> k;

    // 골동품 정보 -> 가치, 무게
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.second >> p.first;
        objects.push_back(p);
    }
    sort(objects.begin(), objects.end(), cmp); // 가치 내림차순 -> 무게 오름차순
    // sort(objects.rbegin(), objects.rend()); // 내림차순

    // 가방 정보
    for (int i = 0; i < k; i++) {
        int capacity; cin >> capacity;
        bags.push_back(capacity);
    }
    sort(bags.begin(), bags.end());

    // first try -> 가치가 높은 거부터 capacity가 작은 가방부터 담아본다.
    // loop를 가방부터 돌리냐 골동품부터 돌리냐
    // -> 상관없는듯?!
    int value = 0;
    // for (int capacity : bags) {
    //     for (int i = 0; i < objects.size(); i++) {
    //         auto obj = objects[i];
    //         if (capacity >= obj.second) {
    //             value += obj.first;
    //             objects.erase(objects.begin() + i);
    //             break;
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++) {
        auto obj = objects[i];
        for (int j = 0; j < bags.size(); j++) {
            int capacity = bags[j];
            if (capacity >= obj.second) {
                value += obj.first;
                bags.erase(bags.begin() + j);
                break;
            }
        }
    }
    cout << value;
}