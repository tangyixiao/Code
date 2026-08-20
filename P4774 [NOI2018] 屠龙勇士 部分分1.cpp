#include <bits/stdc++.h>
using namespace std;const int N=100005;long long a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int n,m;cin>>n>>m;for(int i=0;i<n;i++)cin>>a[i];long long x;for(int i=0;i<n;i++)cin>>x;for(int i=0;i<n;i++)cin>>x;while(m--)cin>>x;cout<<*max_element(a,a+n)<<'\n';}}
