#include <bits/stdc++.h>
using namespace std;char s[10005];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long z=c>1?stoull(v[1]):1,w=c>2?stoull(v[2]):20;mt19937_64 g(z);int n=min(10000ULL,max(1ULL,w));s[0]=g()%9+49;for(int i=1;i<n;i++)s[i]=g()%10+48;cout<<s<<'\n';}
