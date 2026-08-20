#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long g=0,x;cin>>n;while(n--)cin>>x,g=__gcd(g,abs(x));cout<<g<<'\n';}
