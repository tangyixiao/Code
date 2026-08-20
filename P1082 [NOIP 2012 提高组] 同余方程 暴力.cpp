#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b;cin>>a>>b;for(int x=1;x<b;x++)if(a*x%b==1)return cout<<x<<'\n',0;}
