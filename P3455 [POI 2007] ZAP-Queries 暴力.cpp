#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int a,b,d,r=0;cin>>a>>b>>d;for(int x=1;x<=a;x++)for(int y=1;y<=b;y++)r+=__gcd(x,y)==d;cout<<r<<'\n';}}
