#include<bits/stdc++.h>
using namespace std;
const int N=1e1;
long long a[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,o,l,r,k;cin>>n>>m;for(int i=1;i<=n;i++)a[i]=i;while(m--){cin>>o>>l>>r;if(o==1){cin>>k;for(int i=l;i<=r;i++)a[i]+=k;}else{long long s=0;for(int i=l;i<=r;i++)s+=a[i];cout<<s<<'\n';}}}
