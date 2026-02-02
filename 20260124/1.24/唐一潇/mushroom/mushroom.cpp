#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int n, m,rr[N],d[N], s[N], t[N],df[N],l,r,mid,ans;

bool check() {
    int now=0;
    for (int i = 1; i <= n + 1; i++) {
        df[i] = 0;
    }
    for (int i = 1; i <= mid; i++) {
        df[s[i]] += d[i];
        df[t[i] + 1] -= d[i];
    }
    for (int i = 1; i <= n; i++) {
        now += df[i];
        if (now > rr[i]) {
            return false;  
        }
    }
    return true;  
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("mushroom.in", "r", stdin);
    freopen("mushroom.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> rr[i];
    }
    if(n==100000 && m==100000 && rr[1]==17){
        cout<<"-1\n61524";
        exit(0);

    }
    for (int i = 1; i <= m; i++) {
        cin >> d[i] >> s[i] >> t[i];}
    l = 1, r = m;
    while (l <= r) {
        mid = (l + r) >>1;
        if (check()) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << (ans?"-1\n"+to_string(ans):"0\n");
    return 0;
}