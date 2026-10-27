#include <bits/stdc++.h>
using namespace std;

int age, dose, tot;

signed main() {
    cin >> age;
    if (age > 10) {
        dose = 25;
    } else if (age >= 7) {
        dose = 15;
    } else {
        dose = 5;
    }
    tot = dose * 3 * 5;
    cout << (tot + 119) / 120 << "\n";
    return 0;
}
