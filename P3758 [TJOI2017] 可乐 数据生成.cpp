#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10;mt19937_64 g(s);int n=g()%min(29ULL,max(1ULL,z-1))+2,m=n*(n-1)/2;cout<<n<<' '<<m<<'\n';for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cout<<i<<' '<<j<<'\n';cout<<g()%max(2ULL,z)+2<<'\n';}
