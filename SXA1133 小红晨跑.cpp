#include <bits/stdc++.h>
using namespace std;

int x, s;

signed main() {
    for (int i = 1; i <= 5; i++) {
        cin >> x;
        s += x;
    }
    cout << s << "\n"
         << s / 5 << "\n";
    return 0;
}
