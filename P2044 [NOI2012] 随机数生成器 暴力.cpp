#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long m,a,c,x,n,g;cin>>m>>a>>c>>x>>n>>g;while(n--)x=((__uint128_t)a*x+c)%m;cout<<x%g<<'\n';}
