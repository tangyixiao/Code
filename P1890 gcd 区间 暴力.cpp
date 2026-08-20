#include <bits/stdc++.h>
using namespace std;const int N=1005;int a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];while(m--){int l,r,z=0;cin>>l>>r;for(int i=l;i<=r;i++)z=__gcd(z,a[i]);cout<<z<<'\n';}}
