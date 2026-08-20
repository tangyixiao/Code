#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000000000000000000ULL;mt19937_64 g(s);int T=min(350ULL,max(1ULL,z/10000000000000000ULL+1));cout<<T<<'\n';while(T--)cout<<g()%(min(1000000000000000000ULL,max(2ULL,z))-1)+2<<'\n';}
