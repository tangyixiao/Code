#include <bits/stdc++.h>
#define task
using namespace std;
#ifndef task
namespace Tangyixiao {
typedef long long ll;

const int MAXN = 1e6 + 5;

ll a[MAXN];
ll xl[MAXN], xr[MAXN];
ll ans_x[MAXN];

bool check(int n, ll l, ll L, ll R) {
    xl[0] = xr[0] = 0;
    for (int i = 1; i <= n; i++) {
        xl[i] = max(a[i - 1], xl[i - 1] + L);
        xr[i] = min((i < n) ? a[i] : l, xr[i - 1] + R);
        if (xl[i] > xr[i])
            return false;
    }
    return xl[n] <= l && l <= xr[n];
}

void construct(int n, ll l, ll L, ll R, ll *x) {

    xl[0] = 0;
    for (int i = 1; i <= n; i++) {
        xl[i] = max(a[i - 1], xl[i - 1] + L);
    }

    x[n] = l;
    for (int i = n - 1; i >= 0; i--) {
        ll lower = max(xl[i], x[i + 1] - R);
        ll upper = min((i < n - 1) ? a[i + 1] : l, x[i + 1] - L);
        x[i] = lower;
    }
}

int main() {
    freopen("synapse.in", "r", stdin);
    freopen("synapse.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        ll l;
        int n;
        scanf("%lld %d", &l, &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        ll left = 0, right = l;
        ll best_D = l, best_L = 1;

        while (left <= right) {
            ll D = (left + right) / 2;

            bool found = false;
            ll found_L = 1;

            ll L_low = 1, L_high = l - D;

            if (check(n, l, L_low, L_low + D)) {
                found = true;
                found_L = L_low;
            }

            if (!found) {
                if (check(n, l, L_high, L_high + D)) {
                    found = true;
                    found_L = L_high;
                }
            }
            if (!found) {
                ll low = L_low, high = L_high;
                while (low <= high) {
                    ll mid = (low + high) / 2;
                    if (check(n, l, mid, mid + D)) {
                        found = true;
                        found_L = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }

            if (found) {
                best_D = D;
                best_L = found_L;
                right = D - 1;
            } else {
                left = D + 1;
            }
        }

        construct(n, l, best_L, best_L + best_D, ans_x);

        bool valid = true;
        for (int i = 1; i <= n; i++) {
            ll diff = ans_x[i] - ans_x[i - 1];
            if (diff < best_L || diff > best_L + best_D) {
                valid = false;
                break;
            }
            if (ans_x[i - 1] > a[i - 1] || ans_x[i] < a[i - 1]) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            ans_x[0] = 0;
            for (int i = 1; i <= n; i++) {
                ans_x[i] = max(a[i - 1], ans_x[i - 1] + best_L);
            }
            ans_x[n] = l;
            for (int i = n - 1; i >= 0; i--) {
                ans_x[i] = min(ans_x[i], ans_x[i + 1] - best_L);
            }
        }

        for (int i = 0; i <= n; i++) {
            printf("%lld%c", ans_x[i], i == n ? '\n' : ' ');
        }
    }

    return 0;
}
} // namespace Tangyixiao

#endif

const int N = 2e6 + 1;
int n, len;
int a[N + 1];
int l[N + 1], r[N + 1];
signed p[N + 1];
bool calc(const int L, const int R) {
    for (int i = 1; i <= n; ++i) {
        l[i] = max(a[i], l[i - 1] + L);
        r[i] = min(a[i + 1], r[i - 1] + R);
        if (r[i] < a[i] || l[i] > a[i + 1])
            return 0;
    }
    return (r[n] == len ? 1 : 0);
}
signed al, ar;
void solve() {
    scanf("%d %d", &len, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    a[n + 1] = len;
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (!calc(mid, 1e9))
            r = mid - 1;
        else
            l = mid;
    }
    al = l;
    l = 0, r = 1e9;
    while (l < r) {
        mid = l + r >> 1;
        if (!calc(al, mid))
            l = mid + 1;
        else
            r = mid;
    }
    ar = r;
    calc(al, ar);
    p[n] = len;
    for (int i = n - 1; i >= 1; --i) {
        p[i] = max((signed)::l[i], p[i + 1] - ar);
    }
    for (int i = 0; i <= n; ++i) {
        printf("%d ", p[i]);
    }
    putchar('\n');
}
signed main() {
    freopen("synapse.in", "r", stdin);
    freopen("synapse.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (; T--;) {
        solve();
    }
    return 0;
}