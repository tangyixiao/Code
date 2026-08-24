#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);z=min(100000ULL,max(1ULL,z));int n=g()%z+1;cout<<n<<'\n'<<0<<' ';for(int i=1;i<n;i++)cout<<g()%998244353<<' ';cout<<'\n';}
