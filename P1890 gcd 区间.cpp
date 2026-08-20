#include <bits/stdc++.h>
using namespace std;const int N=1005,L=11;int a[N][L];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i][0];for(int j=1;j<L;j++)for(int i=1;i+(1<<j)-1<=n;i++)a[i][j]=__gcd(a[i][j-1],a[i+(1<<j-1)][j-1]);while(m--){int l,r;cin>>l>>r;int k=31-__builtin_clz(r-l+1);cout<<__gcd(a[l][k],a[r-(1<<k)+1][k])<<'\n';}}
