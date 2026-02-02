#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
int n, a[N], x, cnt;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (x >= a[i]) {
            x -= a[i];
            cnt++;
        } 
    }
    cout << cnt;
    return 0;
}