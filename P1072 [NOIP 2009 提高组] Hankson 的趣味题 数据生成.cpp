#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int T=g()%min(2000ULL,max(1ULL,z))+1;cout<<T<<'\n';while(T--){int x=g()%1000+1,a=x*(g()%100+1),b=__gcd(x,a),c=g()%1000+1,d=1LL*x/__gcd(x,c)*c;cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';}}
