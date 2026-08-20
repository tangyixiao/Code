#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;int main(){ios::sync_with_stdio(0);cin.tie(0);int t;cin>>t;while(t--){long long n,a,b,x,y,s;cin>>n>>a>>b>>x>>y;a%=P;b%=P;s=a*a%P;if(n>1)s=(s+b*b)%P;for(int i=3;i<=n;i++){long long c=(x%P*b+y%P*a)%P;a=b;b=c;s=(s+b*b)%P;}cout<<s<<'\n';}}
