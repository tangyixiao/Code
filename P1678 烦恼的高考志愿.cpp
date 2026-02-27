#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], b[N], ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1,x; i <= m; i++) {
        x = lower_bound(a + 1, a + n + 1, b[i]) - a;
        if(x==n+1){
            ans+=(b[i]-a[n]);
        }
        else{
            if(x==1){
                ans+=(a[1]-b[i]);
            }
            else{
                ans+=min(abs(a[x]-b[i]),abs(a[x-1]-b[i]));
            }
        }
    }
    cout << ans;
    return 0;
}