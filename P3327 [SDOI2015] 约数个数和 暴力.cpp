#include <bits/stdc++.h>
using namespace std;int f(int x){int r=0;for(int i=1;i*i<=x;i++)if(x%i==0)r+=1+(i*i<x);return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int n,m;long long r=0;cin>>n>>m;for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)r+=f(i*j);cout<<r<<'\n';}}
