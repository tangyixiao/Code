#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);long long L=g()%max(2ULL,z)+2;cout<<g()%L+1<<' '<<g()%L+1<<' '<<g()%L+1<<' '<<g()%L+1<<' '<<L<<'\n';}
