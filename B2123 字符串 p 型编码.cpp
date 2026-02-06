#include <bits/stdc++.h>
using namespace std;
string p;
int cnt = 1;
signed main() {
    cin >> p;
    int n = p.length();
    for (int i = 1; i < n; i++) {
        if (p[i] != p[i - 1]) {
            cout << cnt << p[i - 1];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    cout << cnt << p[n - 1];
    return 0;
}
