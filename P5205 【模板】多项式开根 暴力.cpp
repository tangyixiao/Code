#include <bits/stdc++.h>
using namespace std;const int N=100005,P=998244353;static int a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];b[0]=1;for(int i=1;i<n;i++){long long s=0;for(int j=1;j<i;j++)s=(s+1LL*b[j]*b[i-j])%P;b[i]=1LL*(a[i]-s+P)*(P+1)/2%P;}for(int i=0;i<n;i++)cout<<b[i]<<' ';cout<<'\n';}
