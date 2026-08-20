#include <bits/stdc++.h>
using namespace std;bool p(int x){if(x<2)return 0;for(int i=2;i*i<=x;i++)if(x%i==0)return 0;return 1;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,r=0;cin>>n;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)r+=p(__gcd(i,j));cout<<r<<'\n';}
