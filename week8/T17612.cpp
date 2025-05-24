#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Customer {
    long long id;
    int w;
    Customer(int _id, int _w) : id(_id), w(_w) {}
};
struct Counter {
    int idx, time;
    long long customer_id;
    Counter(int i, int c_id, int t) : idx(i), customer_id(c_id), time(t) {}
};
struct pq_cmp {
    bool operator()(const Counter &c1, const Counter &c2) {
        return c1.time > c2.time;
    }
};

int n, k;
queue<Customer> customers;

bool vec_cmp(const Counter &c1, const Counter &c2) {
    return c1.idx < c2.idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        long long id; int w;
        cin >> id >> w;
        customers.emplace(id, w);
    }

    priority_queue<Counter, vector<Counter>, pq_cmp> pq;
    for (int idx = 1; pq.size() < k && customers.size(); ++idx) {
        pq.emplace(idx++, customers.front().id, customers.front().w);
        customers.pop();
    }

    vector<Counter> temp; // 동시에 계산이 끝나는 카운터들이 들어감
    long long ans = 0;
    int out_cnt = 1;
    while (pq.size()) {
        while (temp.empty() || temp.back().time == pq.top().time) {
            temp.push_back(pq.top());
            pq.pop();
            if (pq.empty()) break; // pq.size() check
        }
        sort(temp.begin(), temp.end(), vec_cmp); // idx 오름차순 정렬

        
        for (auto c : temp) { // 다음 고객이 카운터 사용
            if (customers.empty()) break;
            pq.emplace(c.idx, customers.front().id, c.time + customers.front().w);
            customers.pop();
        }

        // 쇼핑몰 나가는 고객들
        for (auto rit = temp.rbegin(); rit != temp.rend(); ++rit) ans += (out_cnt++) * (rit->customer_id);
        temp.clear();
    }
    cout << ans;
}