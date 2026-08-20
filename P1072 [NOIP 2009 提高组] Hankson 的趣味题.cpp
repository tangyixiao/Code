#include <bits/stdc++.h>
using namespace std;const int N=2005;long long d[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){long long a,b,c,n;cin>>a>>b>>c>>n;int k=0;for(long long i=1;i*i<=n;i++)if(n%i==0){d[k++]=i;if(i*i<n)d[k++]=n/i;}int r=0;for(int i=0;i<k;i++)if(__gcd(d[i],a)==b&&d[i]/__gcd(d[i],c)*c==n)r++;cout<<r<<'\n';}}
