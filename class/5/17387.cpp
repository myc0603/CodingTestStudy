#include <iostream>
#define y1 yy
using namespace std;

bool ans;
long long x1, y1, x2, y2, x3, y3, x4, y4;
long long x, y; // 교점
long long dx1, dy1, dx2, dy2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    dx1 = x2 - x1; dy1 = y2 - y1;
    dx2 = x4 - x3; dy2 = y4 - y3;

    if (dx1 == 0 && dx2 == 0) {
        if (x1 != x3) ans = false;
        else if ((min(y1, y2) <= y3 && y3 <= max(y1, y2))
                || (min(y1, y2) <= y4 && y4 <= max(y1, y2))) ans = true;
        else if ((min(y3, y4) <= y1 && y1 <= max(y3, y4))
                || (min(y3, y4) <= y2 && y2 <= max(y3, y4))) ans = true;
        
        cout << ans;
        return 0;
    }
    if (dy1 == 0 && dy2 == 0) {
        if (y1 != y3) ans = false;
        else if ((min(x1, x2) <= x3 && x3 <= max(x1, x2))
                || (min(x1, x2) <= x4 && x4 <= max(x1, x2))) ans = true;
        else if ((min(x3, x4) <= x1 && x1 <= max(x3, x4))
                    || (min(x3, x4) <= x2 && x2 <= max(x3, x4))) ans = true;
        cout << ans;
        return 0;
    }

    // 교점 구하기
    long long coef_x = 1, coef_y = 1;
    if (dx1 == 0) {
        x = x1;
        y = dy2 * (x1 - x3) + y3 * dx2;
        coef_y = dx2;
    } else if (dx2 == 0) {
        x = x3;
        y = dy1 * (x3 - x1) + y1 * dx1;
        coef_y = dx1;
    } 
    else {
        long long a, b, c, d, e, f;
        a = dy1; b = -dx1; c = x1 * y2 - y1 * x2;
        d = dy2; e = -dx2; f = x3 * y4 - y3 * x4;

        if (a * e == d * b) { // 기울기가 같은 경우
            if (a * f != c * d) ans = false;
            else if ((min(x1, x2) <= x3 && x3 <= max(x1, x2))
                    || (min(x1, x2) <= x4 && x4 <= max(x1, x2))) ans = true;
            else if ((min(x3, x4) <= x1 && x1 <= max(x3, x4))
                    || (min(x3, x4) <= x2 && x2 <= max(x3, x4))) ans = true;
            cout << ans;
            return 0;
        }

        x = c * e - b * f;
        coef_x = a * e - b * d;
        y = a * f - c * d;
        coef_y = coef_x;
    }

    x1 *= coef_x; x2 *= coef_x;
    x3 *= coef_x; x4 *= coef_x;
    y1 *= coef_y; y2 *= coef_y;
    y3 *= coef_y; y4 *= coef_y;

    ans = (min(x1, x2) <= x && x <= max(x1, x2))
        && (min(y1, y2) <= y && y <= max(y1, y2))
        && (min(x3, x4) <= x && x <= max(x3, x4))
        && (min(y3, y4) <= y && y <= max(y3, y4));

    cout << ans;
}