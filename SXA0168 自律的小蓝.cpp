#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, d;
    cin >> w >> d;
    if (d <= 5) {
        cout << "Study\n";
    } else if (w == 1 && d == 6) {
        cout << "Coding\n";
    } else if (w == 1 && d == 7) {
        cout << "Housework\n";
    } else if (w == 0 && d == 6) {
        cout << "Piano\n";
    } else {
        cout << "Grandma and grandpa\n";
    }
    return 0;
}
