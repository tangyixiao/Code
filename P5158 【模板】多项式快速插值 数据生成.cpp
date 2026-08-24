#include <bits/stdc++.h>
using namespace std;const int P=998244353;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;z=min(100000ULL,max(1ULL,z));mt19937_64 g(s);int n=g()%z+1,a=g()%P,d=g()%(P-1)+1;cout<<n<<'\n';for(int i=0;i<n;i++)cout<<(a+1LL*i*d)%P<<' '<<g()%P<<'\n';}
