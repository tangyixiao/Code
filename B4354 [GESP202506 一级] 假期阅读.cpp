#include <bits/stdc++.h>
using namespace std;
int n, k, t;
signed main() {
    cin >> n >> k >> t;
    cout << min(n, k * t);
    return 0;
}