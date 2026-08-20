#include <bits/stdc++.h>
using namespace std;const int N=5005,P=998244353;int a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=1;i<=n;i++)cin>>a[i];for(int i=1;i<=n;i++)cin>>b[i];for(int i=1;i<=n;i++){long long s=0,p=i;for(int j=1;j<=n;j++)s=(s+p*__gcd(a[i],b[j]))%P,p=p*i%P;cout<<s<<'\n';}}
