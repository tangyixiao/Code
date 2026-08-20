#include <bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int t=min(100ULL,max(1ULL,z/10));cout<<t<<'\n';while(t--)cout<<g()%max(1ULL,z)+1<<'\n';}
