#include <bits/stdc++.h>
using namespace std;const int N=2000005;long long a[N],b[N],c[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<=n;i++)cin>>a[i];for(int i=0;i<=m;i++)cin>>b[i];for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)c[i+j]+=a[i]*b[j];for(int i=0;i<=n+m;i++)cout<<c[i]<<' ';cout<<'\n';}
