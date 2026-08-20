#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,k,r=0;cin>>n>>k;for(int i=1;i<=n;i++)r+=k%i;cout<<r<<'\n';}
