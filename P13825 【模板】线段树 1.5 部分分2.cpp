#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long s[N*4],z[N*4];
void u(int p,int x,int y,int a,int b,int k){if(a<=x&&y<=b){s[p]+=(long long)k*(y-x+1);z[p]+=k;return;}int m=(x+y)/2;if(a<=m)u(p*2,x,m,a,b,k);if(b>m)u(p*2+1,m+1,y,a,b,k);s[p]=s[p*2]+s[p*2+1]+z[p]*(y-x+1);}
long long q(int p,int x,int y,int a,int b,long long k=0){if(a<=x&&y<=b)return s[p]+k*(y-x+1);k+=z[p];int m=(x+y)/2;long long v=0;if(a<=m)v+=q(p*2,x,m,a,b,k);if(b>m)v+=q(p*2+1,m+1,y,a,b,k);return v;}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,o,a,b,k;cin>>n>>m;while(m--){cin>>o>>a>>b;if(o==1)cin>>k,u(1,1,n,a,b,k);else cout<<(long long)(a+b)*(b-a+1)/2+q(1,1,n,a,b)<<'\n';}}
