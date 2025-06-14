#include <iostream>
#include <vector>
using namespace std;

int mapSize, caseCount, dp[1002][1002];
vector<pair<int, int>> casePositions;

int dis(int i1, int i2) {
    pair<int, int> p1 = casePositions[i1], p2 = casePositions[i2];
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int dfs(int car1PositionIndex, int car2PositionIndex) {
    int currentCaseIndex = max(car1PositionIndex, car2PositionIndex) + 1;
    if (currentCaseIndex == caseCount + 2) return 0;

    int &result = dp[car1PositionIndex][car2PositionIndex];
    if (result != -1) return result;


}

int main() {
    cin >> mapSize >> caseCount;
    casePositions.reserve(caseCount + 1);
    casePositions.emplace_back(1, 1);
    casePositions.emplace_back(mapSize, mapSize);
    for (int i = 0; i < caseCount; ++i) {
        int y, x;
        cin >> y >> x;
        casePositions.emplace_back(y, x);
    }

    fill(&dp[0][0], &dp[0][0] + 1002 * 1002, -1);

}