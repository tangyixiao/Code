#include <bits/stdc++.h>
using namespace std;
const int N=205;const long long I=4e18;long long a[N][N],f[N],g[N];int h[1005];
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,t,s,e,k=0;cin>>n>>t>>s>>e;memset(h,-1,sizeof h);for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=I;while(t--){int w,u,v;cin>>w>>u>>v;if(h[u]<0)h[u]=k++;if(h[v]<0)h[v]=k++;a[h[u]][h[v]]=a[h[v]][h[u]]=w;}fill(f,f+k,I);f[h[s]]=0;while(n--){fill(g,g+k,I);for(int i=0;i<k;i++)for(int j=0;j<k;j++)if(f[i]<I&&a[i][j]<I)g[j]=min(g[j],f[i]+a[i][j]);copy(g,g+k,f);}cout<<f[h[e]]<<'\n';}
