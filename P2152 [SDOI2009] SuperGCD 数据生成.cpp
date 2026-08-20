#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int n=min(10000ULL,max(1ULL,z));for(int k=0;k<2;k++){cout<<g()%9+1;for(int i=1;i<n;i++)cout<<g()%10;cout<<'\n';}}
