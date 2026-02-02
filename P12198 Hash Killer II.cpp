#include <bits/stdc++.h>
using namespace std;
const int n = 1e5, l = 114;
mt19937 rnd(time(NULL));
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << n << " " << l << "\n";
    for (int i = 1; i <= n; i++) {
        cout << (char)(rnd() % 26 + 'a');
    }
    return 0;
}