#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(2500ULL,max(1ULL,z))+1,k=g()%n+1;cout<<k<<' '<<n<<'\n';for(int i=1;i<=n;i++)cout<<g()%10000+1<<' '<<g()%10000+1<<' '<<g()%i<<'\n';}
