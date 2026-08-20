#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10;mt19937_64 g(s);int n=g()%min(100ULL,max(1ULL,z))+1;cout<<n<<' '<<g()%max(1ULL,z)<<'\n';for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<(long long)(g()%2001)-1000<<' ';cout<<'\n';}}
