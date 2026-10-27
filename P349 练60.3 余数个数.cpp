#include <bits/stdc++.h>
using namespace std;

int x, cnt, seen[45];

signed main() {
    for (int i = 1; i <= 10; i++) {
        cin >> x;
        seen[x % 42] = 1;
    }
    for (int i = 0; i < 42; i++) {
        if (seen[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
