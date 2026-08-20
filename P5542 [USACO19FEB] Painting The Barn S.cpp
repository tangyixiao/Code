#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int a[N][N];
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k,x,y,u,v,z=0;cin>>n>>k;while(n--){cin>>x>>y>>u>>v;a[x][y]++;a[u][y]--;a[x][v]--;a[u][v]++;}for(int i=0;i<1e3;i++)for(int j=0;j<1e3;j++){if(i)a[i][j]+=a[i-1][j];if(j)a[i][j]+=a[i][j-1];if(i&&j)a[i][j]-=a[i-1][j-1];z+=a[i][j]==k;}cout<<z<<'\n';}
