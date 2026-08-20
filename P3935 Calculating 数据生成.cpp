#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):160000000000000ULL;mt19937_64 g(s);z=min(160000000000000ULL,max(1ULL,z));unsigned long long r=g()%z+1,l=g()%r+1;cout<<l<<' '<<r<<'\n';}
