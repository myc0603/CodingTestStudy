#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> objects;
vector<int> bags;

int main() {
    cin >> n >> k;

    // 골동품 정보 -> 무게, 가치
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        objects.push_back(p);
    }
    sort(objects.begin(), objects.end());

    // 가방 정보
    for (int i = 0; i < k; i++) {
        int capacity; cin >> capacity;
        bags.push_back(capacity);
    }
    sort(bags.begin(), bags.end());

    int value = 0;
    priority_queue<int> pq;
    int j = 0;
    for (int i = 0; i < k; i++) {
        // 각 가방에 담을 수 있는 골동품의 가치를 우선순위 큐에 다 넣어놓고
        // 가장 가치가 높은 걸 value에 추가
        // pq에는 bags[i]가 담을 수 있는 골동품들의 가치가 들어있다.
        // i전의 인덱스에서의 가방이 담을 수 있는 골동품 포함
        while (j < n && objects[j].first <= bags[i]) pq.push(objects[j++].second);
        if (pq.size()) {
            value += pq.top(); pq.pop();
        }
    }
    cout << value;
}