#include<bits/stdc++.h>
using namespace std;
const int P=10007,N=1e2+5;
int a[N][N],b[N][N];
int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;for(int o=1,h,w,r;o<=T;o++){cin>>h>>w>>r;memset(a,0,sizeof a);memset(b,0,sizeof b);while(r--){int x,y;cin>>x>>y;b[x][y]=1;}a[1][1]=1;for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)if(!b[i][j]&&(i>1||j>1))a[i][j]=((i>1&&j>2?a[i-1][j-2]:0)+(i>2&&j>1?a[i-2][j-1]:0))%P;cout<<"Case #"<<o<<": "<<a[h][w]<<'\n';}}
