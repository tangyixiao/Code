#include <bits/stdc++.h>
using namespace std;
int n, ans;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x = i;
        map<int, int> mp;
        while (x) {
            mp[x % 10]++;
            x /= 10;
        }
        if (mp.size() == 1) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}