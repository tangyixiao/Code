#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int x,y;cin>>x>>y;if(y%x)return cout<<0<<'\n',0;int n=y/x,r=1;for(int p=2;1LL*p*p<=n;p++)if(n%p==0){r*=2;while(n%p==0)n/=p;}if(n>1)r*=2;cout<<r<<'\n';}
