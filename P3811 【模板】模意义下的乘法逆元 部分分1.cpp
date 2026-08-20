#include <bits/stdc++.h>
using namespace std;long long F(long long a,long long b,long long p){long long r=1;for(;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long p;cin>>n>>p;for(int i=1;i<=n;i++)cout<<F(i,p-2,p)<<'\n';}
