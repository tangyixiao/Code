#include <bits/stdc++.h>
using namespace std;
long long m,x[2][2],y[2][2],z[2][2];void q(long long a[2][2],long long b[2][2]){memset(z,0,sizeof z);for(int i=0;i<2;i++)for(int k=0;k<2;k++)for(int j=0;j<2;j++)z[i][j]=(z[i][j]+(__int128)a[i][k]*b[k][j])%m;memcpy(a,z,sizeof z);}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long p,r,a,b,n;cin>>p>>r>>a>>b>>n>>m;if(n==1)return cout<<a%m<<'\n',0;x[0][0]=p%m;x[0][1]=r%m;x[1][0]=1;y[0][0]=y[1][1]=1;for(n-=2;n;n>>=1,q(x,x))if(n&1)q(y,x);cout<<(long long)(((__int128)y[0][0]*(b%m)+(__int128)y[0][1]*(a%m))%m)<<'\n';}
