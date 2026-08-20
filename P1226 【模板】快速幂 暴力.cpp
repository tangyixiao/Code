#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b,p,r=1;cin>>a>>b>>p;for(long long i=0;i<b;i++)r=(__int128)r*a%p;cout<<a<<'^'<<b<<" mod "<<p<<'='<<r<<'\n';}
