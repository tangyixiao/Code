#include <bits/stdc++.h>
using namespace std;const int N=1e6+5;const long long P=1e9+7;long long f[N];bool a[105],b[105];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,x,z;cin>>n>>x;while(x--)cin>>z,a[z]=1;cin>>x;while(x--)cin>>z,b[z]=1;f[0]=1;for(int i=1;i<=n;i++)for(int j=1;j<=100&&j<=i;j++)if(a[j]&&b[j])f[i]=(f[i]+f[i-j])%P;cout<<f[n]<<'\n';}
