#include <bits/stdc++.h>
using namespace std;unsigned long long a[64];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;while(n--){unsigned long long x;cin>>x;for(int i=63;i>=0;i--)if(x>>i&1){if(a[i])x^=a[i];else{a[i]=x;break;}}}unsigned long long r=0;for(int i=63;i>=0;i--)r=max(r,r^a[i]);cout<<r<<'\n';}
