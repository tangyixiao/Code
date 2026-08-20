#include <bits/stdc++.h>
using namespace std;const int N=3000005;long long a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long p;cin>>n>>p;a[1]=1;cout<<1<<'\n';for(int i=2;i<=n;i++)a[i]=(p-p/i)*a[p%i]%p,cout<<a[i]<<'\n';}
