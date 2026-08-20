#include <bits/stdc++.h>
using namespace std;const int N=1005;long long k[N],g[N],r[N],w[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>k[i]>>g[i]>>r[i],w[i]=1;for(int d=0;d<=1000000000;d++){int i=0;for(;i<n;i++)if(w[i]!=r[i])break;if(i==n)return cout<<d<<'\n',0;for(i=0;i<n;i++)w[i]=w[i]*k[i]%g[i],w[i]+=!w[i]*g[i];}cout<<"Impossible\n";}
