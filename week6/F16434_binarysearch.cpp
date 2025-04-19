#include <iostream>
#include <vector>
using namespace std;

struct Room {
    int type;
    long long attack, hp;
    Room(int t, int a, int h) : type(t), attack(a), hp(h) {}
};

int n, atk;
vector<Room> rooms;

bool can_clear(long long max_hp) {
    long long cur_atk = atk;
    long long cur_hp = max_hp;

    for (auto room = rooms.begin(); room != rooms.end(); ++room) {
        if (room -> type == 1) { // monster
            long long monster_hp = room -> hp;
            long long monster_atk = room -> attack;
            cur_hp -= ((monster_hp + cur_atk - 1) / cur_atk - 1) * monster_atk;
            if (cur_hp <= 0) return false;
        } else { // type == 2 potion
            cur_atk += room -> attack;
            cur_hp = min(max_hp, cur_hp + room -> hp);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> atk;
    rooms.reserve(n);

    long long left = 0;
    long long right = 1LL << 62;
    // long long right = 0;
    for (int i = 0; i < n; i++) {
        int t; long long a, h;
        cin >> t >> a >> h;
        // right += ((h + atk - 1) / atk - 1) * a;
        rooms.emplace_back(t, a, h);
    }
    // right++;

    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (can_clear(mid)) right = mid;
        else left = mid;
    }
    cout << right;
}