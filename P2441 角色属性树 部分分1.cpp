#include <bits/stdc++.h>
using namespace std;const int N=205;int a[N],p[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k;cin>>n>>k;for(int i=1;i<=n;i++)cin>>a[i];for(int i=1,x,y;i<n;i++)cin>>x>>y,p[y]=x;while(k--){int t,u,x;cin>>t>>u;if(t==2)cin>>x,a[u]=x;else{int v=p[u];while(v&&__gcd(a[u],a[v])==1)v=p[v];cout<<(v?v:-1)<<'\n';}}}
