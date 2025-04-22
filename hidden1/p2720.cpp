#include <iostream>
using namespace std;
int t, cents, quaters, dimes, nickels, pennies;
string ans;
int main() {
    cin >> t;
    while (t--) {
        cin >> cents;
        
        quaters = cents / 25;
        cents -= 25 * quaters;
        
        dimes = cents / 10;
        cents -= 10 * dimes;

        nickels = cents / 5;
        cents -= 5 * nickels;

        pennies = cents;

        ans += to_string(quaters) + ' ' + to_string(dimes) + ' ' + to_string(nickels) + ' ' + to_string(pennies) + '\n';
    }
    cout << ans;
}