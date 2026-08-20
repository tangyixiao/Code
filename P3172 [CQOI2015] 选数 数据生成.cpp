#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);long long n=g()%1000000000+1,k=g()%1000000000+1,l=g()%1000000000+1,w=g()%min(100000ULL,max(1ULL,z));cout<<n<<' '<<k<<' '<<l<<' '<<min(1000000000LL,l+w)<<'\n';}
