#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;

ll a[MAXN];
ll xl[MAXN], xr[MAXN];
ll ans_x[MAXN];

bool check(int n, ll l, ll L, ll R) {
    xl[0] = xr[0] = 0;
    for (int i = 1; i <= n; i++) {
        xl[i] = max(a[i-1], xl[i-1] + L);
        xr[i] = min((i < n) ? a[i] : l, xr[i-1] + R);
        if (xl[i] > xr[i]) return false;
    }
    return xl[n] <= l && l <= xr[n];
}

void construct(int n, ll l, ll L, ll R, ll* x) {

    xl[0] = 0;
    for (int i = 1; i <= n; i++) {
        xl[i] = max(a[i-1], xl[i-1] + L);
    }
    
    x[n] = l;
    for (int i = n-1; i >= 0; i--) {
        ll lower = max(xl[i], x[i+1] - R);
        ll upper = min((i < n-1) ? a[i+1] : l, x[i+1] - L);
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
            ll diff = ans_x[i] - ans_x[i-1];
            if (diff < best_L || diff > best_L + best_D) {
                valid = false;
                break;
            }
            if (ans_x[i-1] > a[i-1] || ans_x[i] < a[i-1]) {
                valid = false;
                break;
            }
        }
        
        if (!valid) {
            ans_x[0] = 0;
            for (int i = 1; i <= n; i++) {
                ans_x[i] = max(a[i-1], ans_x[i-1] + best_L);
            }
            ans_x[n] = l;
            for (int i = n-1; i >= 0; i--) {
                ans_x[i] = min(ans_x[i], ans_x[i+1] - best_L);
            }
        }
        
        for (int i = 0; i <= n; i++) {
            printf("%lld%c", ans_x[i], i == n ? '\n' : ' ');
        }
    }
    
    return 0;
}