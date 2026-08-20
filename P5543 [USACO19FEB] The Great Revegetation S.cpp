#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N],d[N];
int f(int x){if(p[x]==x)return x;int q=p[x];p[x]=f(p[x]);d[x]^=d[q];return p[x];}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,a,b,z=0;char c;cin>>n>>m;for(int i=1;i<=n;i++)p[i]=i;while(m--){cin>>c>>a>>b;int x=f(a),y=f(b),w=c=='D';if(x==y){if((d[a]^d[b])!=w)return cout<<0<<'\n',0;}else p[x]=y,d[x]=d[a]^d[b]^w;}for(int i=1;i<=n;i++)z+=f(i)==i;cout<<1;while(z--)cout<<0;cout<<'\n';}
