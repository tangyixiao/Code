#include <bits/stdc++.h>
using namespace std;char s[100005];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long z=c>1?stoull(v[1]):1,w=c>2?stoull(v[2]):20;mt19937_64 g(z);int n=g()%max(1ULL,w)+1,m=g()%min(100000ULL,max(1ULL,w))+1;cout<<n<<'\n';for(int i=0;i<m;i++)cout<<char(g()%26+97);cout<<'\n';}
