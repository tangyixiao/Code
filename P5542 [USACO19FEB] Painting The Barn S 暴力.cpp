#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int a[N][N];
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k,x,y,u,v,z=0;cin>>n>>k;while(n--){cin>>x>>y>>u>>v;for(int i=x;i<u;i++)for(int j=y;j<v;j++)a[i][j]++;}for(int i=0;i<1e3;i++)for(int j=0;j<1e3;j++)z+=a[i][j]==k;cout<<z<<'\n';}
