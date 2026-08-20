#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int t=min(500ULL,max(1ULL,z));cout<<t<<'\n';while(t--)cout<<g()%2000000000+1<<'\n';}
