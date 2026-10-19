#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
struct node {
    int b, e;
} a[N];
int n;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].b >> a[i].e;
    }
    sort(a + 1, a + n + 1, [](node x, node y) { return x.e < y.e; });
    int t = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].b >= t) {
            ans++, t = a[i].e;
        }
    }
    cout << ans << "\n";
    return 0;
}