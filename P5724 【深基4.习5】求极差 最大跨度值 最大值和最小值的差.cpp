#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n, a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1);
    return 0;
}