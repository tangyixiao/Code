#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 114;
struct node {
    int m;
    int v;
    double t;
} a[N];
int n, T, cnt;
double ans;
bool cmp(node A, node B) { return A.t > B.t; }
inline void input() {
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].m >> a[i].v;
        a[i].t = (double)(a[i].v) / (double)(a[i].m);
    }
    return;
}

inline void output() {
    printf("%.2lf", ans);
    return;
}

inline void init() {
    sort(a + 1, a + 1 + n, cmp);
    cnt = n;
    return;
}

inline void solve() {
    input();
    init();
    for (int i = 1; i <= n; i++) {
        if (T >= a[i].m) {
            T -= a[i].m;
            ans += a[i].v;
        } else {
            ans += (a[i].t * T);
            T = 0;
        }
    }
    output();
    return;
}

signed main() {
    solve();
    return 0;
}