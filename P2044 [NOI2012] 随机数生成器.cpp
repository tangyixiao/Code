#include <bits/stdc++.h>
using namespace std;unsigned long long m;unsigned long long q(unsigned long long a,unsigned long long b){return(__uint128_t)a*b%m;}
int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long a,c,x,n,g,u=1,v=0;cin>>m>>a>>c>>x>>n>>g;a%=m;c%=m;x%=m;for(;n;n>>=1){if(n&1)v=(q(u,c)+v)%m,u=q(u,a);c=(q(a,c)+c)%m;a=q(a,a);}cout<<(q(u,x)+v)%m%g<<'\n';}
