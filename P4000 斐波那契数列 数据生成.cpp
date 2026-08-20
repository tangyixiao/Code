#include <bits/stdc++.h>
using namespace std;const int N=1e6+5;char a[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int n=min((unsigned long long)1e6,max(1ULL,z));a[0]=g()%9+49;for(int i=1;i<n;i++)a[i]=g()%10+48;a[n]=0;cout<<a<<'\n'<<g()%2147483646+1<<'\n';}
