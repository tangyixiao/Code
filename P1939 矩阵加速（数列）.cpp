#include <bits/stdc++.h>
using namespace std;
const long long P=1e9+7;long long x[3][3],y[3][3],z[3][3];void q(long long a[3][3],long long b[3][3]){memset(z,0,sizeof z);for(int i=0;i<3;i++)for(int k=0;k<3;k++)for(int j=0;j<3;j++)z[i][j]=(z[i][j]+a[i][k]*b[k][j])%P;memcpy(a,z,sizeof z);}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t;cin>>t;while(t--){long long n;cin>>n;if(n<4){cout<<1<<'\n';continue;}memset(x,0,sizeof x);memset(y,0,sizeof y);x[0][0]=x[0][2]=x[1][0]=x[2][1]=1;y[0][0]=y[1][1]=y[2][2]=1;for(n-=3;n;n>>=1,q(x,x))if(n&1)q(y,x);cout<<(y[0][0]+y[0][1]+y[0][2])%P<<'\n';}}
