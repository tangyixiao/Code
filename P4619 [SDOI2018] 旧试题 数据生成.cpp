#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);int T=g()%10+1;z=min(100000ULL,min(max(1ULL,z),200000ULL/T));cout<<T<<'\n';while(T--)cout<<g()%z+1<<' '<<g()%z+1<<' '<<g()%z+1<<'\n';}
