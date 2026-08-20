#include <bits/stdc++.h>
using namespace std;
const int N=205;const long long I=4e18;long long a[N][N],b[N][N],c[N][N],d[N][N];int h[1005],x[N];
void m(long long a[N][N],long long b[N][N],long long c[N][N],int n){for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=I;for(int i=0;i<n;i++)for(int k=0;k<n;k++)if(a[i][k]<I)for(int j=0;j<n;j++)if(b[k][j]<I)d[i][j]=min(d[i][j],a[i][k]+b[k][j]);for(int i=0;i<n;i++)for(int j=0;j<n;j++)c[i][j]=d[i][j];}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,t,s,e,k=0;cin>>n>>t>>s>>e;memset(h,-1,sizeof h);for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=I;while(t--){int w,u,v;cin>>w>>u>>v;if(h[u]<0)h[u]=k++;if(h[v]<0)h[v]=k++;a[h[u]][h[v]]=a[h[v]][h[u]]=w;}for(int i=0;i<k;i++)for(int j=0;j<k;j++)b[i][j]=i==j?0:I;for(;n;n>>=1,m(a,a,a,k))if(n&1)m(b,a,b,k);cout<<b[h[s]][h[e]]<<'\n';}
