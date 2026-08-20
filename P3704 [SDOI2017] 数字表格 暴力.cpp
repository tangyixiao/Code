#include <bits/stdc++.h>
using namespace std;const long long P=1000000007;long long f[105];int main(){ios::sync_with_stdio(0);cin.tie(0);f[1]=1;for(int i=2;i<105;i++)f[i]=(f[i-1]+f[i-2])%P;int T;cin>>T;while(T--){int n,m;long long r=1;cin>>n>>m;for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)r=r*f[__gcd(i,j)]%P;cout<<r<<'\n';}}
