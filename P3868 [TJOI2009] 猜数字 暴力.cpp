#include <bits/stdc++.h>
using namespace std;const int N=12;long long a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];long long m=1;for(int i=0;i<n;i++)cin>>b[i],m*=b[i];for(long long x=0;x<m;x++){bool f=1;for(int i=0;i<n;i++)if((x-a[i])%b[i])f=0;if(f)return cout<<x<<'\n',0;}}
