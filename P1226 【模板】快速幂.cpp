#include <bits/stdc++.h>
using namespace std;
long long q(long long a,long long b,long long p){long long r=1%p;for(;b;b>>=1,a=(__int128)a*a%p)if(b&1)r=(__int128)r*a%p;return r;}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b,p;cin>>a>>b>>p;cout<<a<<'^'<<b<<" mod "<<p<<'='<<q(a,b,p)<<'\n';}
