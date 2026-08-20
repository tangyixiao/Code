#include <bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):8;mt19937_64 g(s);int n=g()%max(2ULL,z)+1,k=g()%min(8ULL,max(2ULL,z))+2,t=k*(k-1)/2;cout<<n<<' '<<t<<" 1 "<<k<<'\n';for(int i=1;i<=k;i++)for(int j=i+1;j<=k;j++)cout<<g()%30+1<<' '<<i<<' '<<j<<'\n';}
