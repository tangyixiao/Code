#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main() {
    cin >> n;
    cout << (n - 1) * (n - 2) * (n - 3) / 6 - ((((n - ((n + 1) >> 1)) >= 3) ? (((n - ((n + 1) >> 1)) * ((n - ((n + 1) >> 1)) - 1) * ((n - ((n + 1) >> 1)) - 2) / 6)) : (0)) << 2);
    return 0;
}