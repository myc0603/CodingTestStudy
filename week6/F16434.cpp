#include <iostream>
#include <vector>
using namespace std;

struct Room {
    int type, attack, hp;
    Room(int t, int a, int h) : type(t), attack(a), hp(h) {}
};

int n, atk;
vector<Room> rooms;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> atk;
    rooms.reserve(n);
    long long final_atk = atk;
    for (int i = 0; i < n; i++) {
        int t, a, h;
        cin >> t >> a >> h;
        rooms.emplace_back(t, a, h);
        if (t == 2) final_atk += a;
    }

    long long cur_hp = 1;
    long long cur_atk = final_atk;

    long long max_hp = cur_hp;
    for (auto room = rooms.rbegin(); room != rooms.rend(); ++room) {
        cout << "cur HP: " << cur_hp << ", cur ATTACK: " << cur_atk << '\n';
        if (room -> type == 1) { // monster
            cout << "  monster attack: " << room -> attack << ", hp: " << room -> hp << '\n';
            int monster_hp = room -> hp;
            int monster_atk = room -> attack;

            cout << "    cur hp: " << cur_hp;
            cur_hp += ((monster_hp + cur_atk - 1) / cur_atk - 1) * monster_atk;
            max_hp = max(max_hp, cur_hp);
            cout << " -> " << cur_hp << '\n';
        } else { // type == 2 potion
            cout << "  potion attack: " << room -> attack << ", hp: " << room -> hp << '\n';

            cout << "    cur attack: " << cur_atk;
            cur_atk -= room -> attack;
            cout << " -> " << cur_atk << "\n";

            cout << "    cur hp: " << cur_hp;
            cur_hp -= room -> hp;
            if (cur_hp <= 0) cur_hp = 1;
            cout << " -> " << cur_hp << '\n';
        }
        cout << '\n';
    }

    cout << max_hp;
}