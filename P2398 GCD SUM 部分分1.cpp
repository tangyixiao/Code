#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long r=0;cin>>n;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)r+=__gcd(i,j);cout<<r<<'\n';}
