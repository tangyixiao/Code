#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
signed main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, m, x, y, xx, yy;
        cin >> n >> m >> x >> y >> xx >> yy;
        if (x == xx && y == yy)
            cout << "0\n";
        else if (x == xx) {
            if (abs(y - yy) == 1)
                cout << "1\n";
            else if (abs(y - yy) % 2 == 0 && abs(y - yy) / 2 <= max(x - 1, n - x))
                cout << "2\n";
            else if (abs(y - yy) <= max(x - 1, n - x))
                cout << "2\n";
            else
                cout << "3\n";
        } else if (y == yy) {
            if (abs(x - xx) == 1)
                cout << "1\n";
            else if (abs(x - xx) % 2 == 0 && abs(x - xx) / 2 <= max(y - 1, m - y))
                cout << "2\n";
            else if (abs(x - xx) <= max(y - 1, m - y))
                cout << "2\n";
            else
                cout << "3\n";
        } else if (abs(x - xx) == abs(y - yy)) {
            if (abs(x - xx) == 1)
                cout << "1\n";
            else
                cout << "2\n";
        } else
            cout << "2\n";
    }
    return 0;
}
