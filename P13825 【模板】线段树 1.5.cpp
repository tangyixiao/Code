#include<bits/stdc++.h>
using namespace std;
const int N=7e6+5;
int l[N],r[N],t=1;
long long s[N],z[N];
void u(int&p,int x,int y,int a,int b,long long k){if(!p)p=++t;if(a<=x&&y<=b){s[p]+=k*(y-x+1);z[p]+=k;return;}int m=x+(y-x)/2;if(a<=m)u(l[p],x,m,a,b,k);if(b>m)u(r[p],m+1,y,a,b,k);s[p]=s[l[p]]+s[r[p]]+z[p]*(y-x+1);}
long long q(int p,int x,int y,int a,int b,long long k=0){if(a<=x&&y<=b)return s[p]+k*(y-x+1);k+=z[p];int m=x+(y-x)/2;long long v=0;if(a<=m)v+=q(l[p],x,m,a,b,k);if(b>m)v+=q(r[p],m+1,y,a,b,k);return v;}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,o,a,b,k,p=1;cin>>n>>m;while(m--){cin>>o>>a>>b;if(o==1)cin>>k,u(p,1,n,a,b,k);else cout<<(long long)(a+b)*(b-a+1)/2+q(p,1,n,a,b)<<'\n';}}
