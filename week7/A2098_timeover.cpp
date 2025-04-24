#include <iostream>
using namespace std;

int n, ways[17][17], visited[17], minCost = 1e8, firstCity;

void dfs(int visitCount, int city, int cost) {
    visited[city] = 1;
    if (visitCount == n) {
        minCost = min(minCost, cost + ways[city][firstCity]);
        return;
    }

    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (visited[nextCity]) continue;
        dfs(visitCount + 1, nextCity, cost + ways[city][nextCity]);
        visited[nextCity] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ways[i][j];
        }
    }
        
    dfs(1, 0, 0);
    cout << minCost;
}