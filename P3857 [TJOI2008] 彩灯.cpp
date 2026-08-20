#include <bits/stdc++.h>
using namespace std;const int P=2008;unsigned long long a[64];char s[55];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,r=0;cin>>n>>m;while(m--){cin>>s;unsigned long long x=0;for(int i=0;i<n;i++)if(s[i]=='O')x|=1ULL<<i;for(int i=63;i>=0;i--)if(x>>i&1){if(a[i])x^=a[i];else{a[i]=x;r++;break;}}}int z=1;while(r--)z=z*2%P;cout<<z<<'\n';}
