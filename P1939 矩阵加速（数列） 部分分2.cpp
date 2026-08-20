#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;int main(){ios::sync_with_stdio(0);cin.tie(0);int t;cin>>t;while(t--){int n;cin>>n;long long a=1,b=1,c=1;for(int i=4;i<=n;i++){long long d=(a+c)%P;a=b;b=c;c=d;}cout<<(n<4?1:c)<<'\n';}}
