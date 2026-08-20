#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T,n;cin>>T;while(T--){cin>>n;long long r=1;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)r=max(r,1LL*i/__gcd(i,j)*j);cout<<r<<'\n';}}
