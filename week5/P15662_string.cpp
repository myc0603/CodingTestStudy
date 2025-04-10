#include <iostream>
#include <vector>
using namespace std;

const int RIGHT = 2, LEFT = 6;
int n, k;
bool rotated[1005];
string wheels[1005];
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
    
    string temp = wheels[wheel][7] + wheels[wheel] + wheels[wheel][0];
    wheels[wheel] = temp.substr(1 - direction, 8);
}

int main() {
    // 0: N극, 1: S극
    // 1: clockwise, -1: counter-clockwise
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> wheels[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int wheel, direction;
        cin >> wheel >> direction;
        rotations.push_back( { --wheel, direction } );
    }

    for (auto rotation : rotations) {
        fill(rotated, rotated + n, false);
        rotate(rotation.first, rotation.second);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (wheels[i][0] == '1') cnt++;
    }
    cout << cnt;
}