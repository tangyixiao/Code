#include <bits/stdc++.h>
using namespace std;const int P=998244353;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;z=min(100000ULL,max(1ULL,z));mt19937_64 g(s);int n=g()%z+1;cout<<n<<'\n'<<1<<' ';for(int i=1;i<n;i++)cout<<g()%P<<' ';cout<<'\n';}
