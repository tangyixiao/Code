#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int n, m;
signed main() {
    cin >> n >> m;
    for (int i = n, x; i <= m; i++) {
        x = i;
        while (x) {
            mp[x % 10]++;
            x /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << mp[i] << " ";
    }
    return 0;
}