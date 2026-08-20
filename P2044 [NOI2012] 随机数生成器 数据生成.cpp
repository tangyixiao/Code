#include <bits/stdc++.h>
using namespace std;int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c0>1?stoull(v[1]):1,z=c0>2?stoull(v[2]):100;mt19937_64 r(s);unsigned long long m=r()%max(2ULL,z)+2;cout<<m<<' '<<r()%m<<' '<<r()%m<<' '<<r()%m<<' '<<r()%max(1ULL,z)+1<<' '<<r()%min(m,(unsigned long long)1e8)+1<<'\n';}
