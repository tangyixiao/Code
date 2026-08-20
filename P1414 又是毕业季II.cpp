#include <bits/stdc++.h>
using namespace std;const int V=1000005,N=10005;int c[V],a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m=0;cin>>n;for(int i=0,x;i<n;i++)cin>>x,c[x]++,m=max(m,x);int k=0;for(int d=m;d;d--){int s=0;for(int j=d;j<=m;j+=d)s+=c[j];while(k<s)a[++k]=d;}for(int i=1;i<=n;i++)cout<<a[i]<<'\n';}
