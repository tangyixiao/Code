#include <bits/stdc++.h>
using namespace std;const int N=100005,P=998244353;int a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=1;i<n;i++)cin>>b[i];a[0]=1;for(int i=1;i<n;i++)for(int j=1;j<=i;j++)a[i]=(a[i]+1LL*a[i-j]*b[j])%P;for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<'\n';}
