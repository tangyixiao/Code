#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10000000;mt19937_64 g(s);z=min(10000000ULL,max(1ULL,z));cout<<g()%z+1<<' '<<g()%z+1<<'\n';}
