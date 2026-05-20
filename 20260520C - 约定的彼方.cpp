#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct node {
    int a, b;
    bool operator<(const node &other) const {
        if (a != other.a) {
            return a < other.a;
        }
        return b < other.b;
    }
} w[N];
int n, k, st;
signed main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i].a >> w[i].b;
    }
    sort(w + 1, w + 1 + n);
    st = w[n].a;
    for (int i = 1; i <= n; i++) {
        if (k >= (w[i].a - w[i - 1].a)) {
            k -= (w[i].a - w[i - 1].a);
            k += w[i].b;
        } else {
            st = w[i - 1].a;
            break;
        }
    }

    cout << st + k << "\n";
    return 0;
}