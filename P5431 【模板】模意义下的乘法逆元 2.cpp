#include <bits/stdc++.h>
using namespace std;long long F(long long a,long long b,long long p){long long r=1;for(;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long p,k,a,s=0,q=1,w;cin>>n>>p>>k;w=k;while(n--){cin>>a;s=(s*a+w*q)%p;q=q*a%p;w=w*k%p;}cout<<s*F(q,p-2,p)%p<<'\n';}
