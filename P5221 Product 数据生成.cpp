#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000000;mt19937_64 g(s);cout<<g()%min(1000000ULL,max(1ULL,z))+1<<'\n';}
