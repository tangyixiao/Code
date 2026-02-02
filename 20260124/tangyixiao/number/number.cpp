#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,k,ans;
const int mod=1e9+7;
inline void solve(){
    ans=0;
    cin>>k;
    k=k*(k+1);
    for(int i=1;i*i<=k;i++){
        if(!(k%i)){
            ans=(ans+i)%mod;
            if(i*i!=k){
                ans=(ans+k/i)%mod;
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}