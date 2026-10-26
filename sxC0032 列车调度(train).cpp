#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, i, x, cnt;
int a[N];
set<int> s;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        x = a[i];
        set<int>::iterator it = s.lower_bound(x);
        if (it == s.end()) {
            cnt++;
        } else {
            s.erase(it);
        }
        s.insert(x);
    }
    cout << cnt << "\n";
    return 0;
}
