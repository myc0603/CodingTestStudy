#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
vector<pair<ll, ll>> edges;
ll twiceAreaOf(pair<ll, ll> p1, pair<ll, ll> p2) { // p1 X p2
    return p1.first * p2.second - p1.second * p2.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    edges.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edges.emplace_back(x, y);
    }

    ll tot = 0;
    ll x = edges[0].first;
    ll y = edges[0].second;
    for (int i = 1; i < n - 1; ++i) {
        pair<ll, ll> p1 = {edges[i].first - x, edges[i].second - y};
        pair<ll, ll> p2 = {edges[i+1].first - x, edges[i+1].second - y};
        tot += twiceAreaOf(p1, p2);
    }
    cout << fixed << setprecision(1) << abs((double) tot / 2);
}