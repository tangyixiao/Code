#include <bits/stdc++.h>
using namespace std;const long long P=998244353;long long f(long long n){long long r=0;for(long long l=1,q;l<=n;l=q+1){q=n/(n/l);r=(r+(q-l+1)%P*(n/l))%P;}return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);long long l,r;cin>>l>>r;cout<<(f(r)-f(l-1)+P)%P<<'\n';}
