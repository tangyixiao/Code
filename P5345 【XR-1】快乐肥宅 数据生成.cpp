#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 q(s);int n=q()%min(1000ULL,max(1ULL,z))+1,d=q()%1000;cout<<n<<'\n';while(n--){long long g=q()%10000000+1,k=q()%g+1,r=1;for(int i=0;i<d;i++)r=r*k%g;r+=!r*g;cout<<k<<' '<<g<<' '<<r<<'\n';}}
