#include <bits/stdc++.h>
using namespace std;const int P=20101009;int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;long long r=0;cin>>n>>m;for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)r=(r+1LL*i/__gcd(i,j)*j)%P;cout<<r<<'\n';}
