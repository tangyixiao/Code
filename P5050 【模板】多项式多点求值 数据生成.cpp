#include <bits/stdc++.h>
using namespace std;const int P=998244353;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):64000;z=min(64000ULL,max(1ULL,z));mt19937_64 g(s);int n=g()%z+1,m=g()%z+1;cout<<n<<' '<<m<<'\n';for(int i=0;i<=n;i++)cout<<g()%P<<' ';cout<<'\n';for(int i=0;i<m;i++)cout<<g()%P<<' ';cout<<'\n';}
