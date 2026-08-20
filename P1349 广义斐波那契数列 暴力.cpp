#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(0);cin.tie(0);long long p,q,a,b,n,m;cin>>p>>q>>a>>b>>n>>m;a%=m;b%=m;for(long long i=3;i<=n;i++){long long c=((__int128)p*b+(__int128)q*a)%m;a=b;b=c;}cout<<(n==1?a:b)<<'\n';}
