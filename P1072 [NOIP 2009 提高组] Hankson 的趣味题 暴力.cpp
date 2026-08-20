#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){long long a,b,c,d,r=0;cin>>a>>b>>c>>d;for(long long x=1;x<=d;x++)if(__gcd(x,a)==b&&x/__gcd(x,c)*c==d)r++;cout<<r<<'\n';}}
