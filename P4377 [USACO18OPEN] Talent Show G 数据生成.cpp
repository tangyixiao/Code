#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(250ULL,max(1ULL,z))+1,W=g()%1000+1;cout<<n<<' '<<W<<'\n';for(int i=0;i<n;i++){int x=g()%1000000+1;if(!i)x=max(x,W);cout<<x<<' '<<g()%1000+1<<'\n';}}
