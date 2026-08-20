#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):2147483647;mt19937_64 g(s);int T=g()%10+1;cout<<T<<'\n';while(T--)cout<<g()%min(2147483647ULL,max(1ULL,z))+1<<'\n';}
