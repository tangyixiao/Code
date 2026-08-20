#include <bits/stdc++.h>
using namespace std;const long long P=104857601;int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long r=1;cin>>n;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){long long g=__gcd(i,j);r=r*(1LL*i/g*j/g)%P;}cout<<r<<'\n';}
