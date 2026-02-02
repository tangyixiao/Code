#include <bits/stdc++.h>
using namespace std;
int n, k;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    cout << ((n + k) % 7 ? (n + k) % 7 : 7);
    return 0;
}