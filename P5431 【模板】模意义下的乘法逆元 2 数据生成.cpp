#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);const int P=998244353;int n=g()%min(5000000ULL,max(1ULL,z))+1;cout<<n<<' '<<P<<' '<<g()%(P-2)+2<<'\n';while(n--)cout<<g()%(P-1)+1<<' ';cout<<'\n';}
