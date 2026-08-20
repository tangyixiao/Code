#include <bits/stdc++.h>
using namespace std;const int N=18;int a[N],p[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];for(int s=1;s<(1<<n);s++){int k=__builtin_popcount((unsigned)s),g=0;for(int i=0;i<n;i++)if(s>>i&1)g=__gcd(g,a[i]);p[k]=max(p[k],g);}for(int i=1;i<=n;i++)cout<<p[i]<<'\n';}
