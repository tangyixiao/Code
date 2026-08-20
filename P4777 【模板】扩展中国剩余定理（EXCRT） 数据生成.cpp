#include <bits/stdc++.h>
using namespace std;const int a[16]={1,2,3,4,5,6,7,8,9,10,12,14,15,18,20,24};int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(100000ULL,max(1ULL,z))+1,x=g()%2520;cout<<n<<'\n';while(n--){int m=a[g()%16];cout<<m<<' '<<x%m<<'\n';}}
