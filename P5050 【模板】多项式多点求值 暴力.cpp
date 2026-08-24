#include <bits/stdc++.h>
using namespace std;const int N=64005,P=998244353;static int a[N],x[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<=n;i++)cin>>a[i];for(int i=0;i<m;i++)cin>>x[i];for(int i=0;i<m;i++){int s=0;for(int j=n;j>=0;j--)s=(1LL*s*x[i]+a[j])%P;cout<<s<<'\n';}}
