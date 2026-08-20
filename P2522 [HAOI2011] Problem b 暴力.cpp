#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int a,b,c,d,k,r=0;cin>>a>>b>>c>>d>>k;for(int x=a;x<=b;x++)for(int y=c;y<=d;y++)r+=__gcd(x,y)==k;cout<<r<<'\n';}}
