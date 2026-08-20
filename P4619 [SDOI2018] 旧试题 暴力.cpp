#include <bits/stdc++.h>
using namespace std;int f(long long n){int r=0;for(long long i=1;i*i<=n;i++)if(n%i==0)r+=1+(i*i<n);return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int A,B,C;cin>>A>>B>>C;long long r=0;for(int i=1;i<=A;i++)for(int j=1;j<=B;j++)for(int k=1;k<=C;k++)r+=f(1LL*i*j*k);cout<<r%1000000007<<'\n';}}
