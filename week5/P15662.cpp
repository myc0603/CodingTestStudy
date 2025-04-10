#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int RIGHT = 2, LEFT = 6;
int n, k;
bool wheels[1000][8], rotated[1000];
vector<pair<int, int>> rotations; // wheel to rotate, direction of the rotation

void rotate(int wheel, int direction) {
    rotated[wheel] = 1;
    
    // 왼쪽 rotate
    if (wheel > 0 && !rotated[wheel-1]) {
        if (wheels[wheel][LEFT] != wheels[wheel-1][RIGHT]) rotate(wheel - 1, -direction);
    }
    // 오른쪽 rotate
    if (wheel < n - 1 && !rotated[wheel+1]) {
        if (wheels[wheel][RIGHT] != wheels[wheel+1][LEFT]) rotate(wheel + 1, -direction);
    }

    bool result[8];
    for (int i = 0; i < 8; i++) {
        int result_idx = (i + direction + 8) % 8;
        result[result_idx] = wheels[wheel][i];
    }

    for (int i = 0; i < 8; i++) {
        wheels[wheel][i] = result[i];
    }
}

// 0: N극, 1: S극
// 1: clockwise, -1: counter-clockwise
// 0-based index
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string wheel; cin >> wheel;
        for (int j = 0; j < 8; j++) {
            wheels[i][j] = wheel[j] == '1' ? 1 : 0;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int wheel, direction;
        cin >> wheel >> direction;
        rotations.push_back( { --wheel, direction } );
    }

    for (auto rotation : rotations) {
        int wheel, direction;
        tie(wheel, direction) = rotation;

        fill(rotated, rotated + n, false);
        rotate(wheel, direction);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (wheels[i][0] == 1) cnt++;
    }
    cout << cnt;
}