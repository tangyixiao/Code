#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int T=g()%min(50000ULL,max(1ULL,z))+1;cout<<T<<'\n';while(T--){int a=g()%50000+1,b=g()%50000+1,d=g()%min(a,b)+1;cout<<a<<' '<<b<<' '<<d<<'\n';}}
