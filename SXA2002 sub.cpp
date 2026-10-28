#include <bits/stdc++.h>
using namespace std;

signed main() {
    int k;
    cin >> k;
    int cnt = 0;
    for (int x = 10000; x <= 30000; x++) {
        int s1 = x / 100, s2 = x / 10 % 1000, s3 = x % 1000;
        if (s1 % k == 0 && s2 % k == 0 && s3 % k == 0) {
            cout << x << "\n";
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "No" << "\n";
    }
    return 0;
}
