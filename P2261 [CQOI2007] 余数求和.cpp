#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,k,r;cin>>n>>k;r=n*k;for(long long l=1,m=min(n,k),q;l<=m;l=q+1){q=min(m,k/(k/l));r-=k/l*(l+q)*(q-l+1)/2;}cout<<r<<'\n';}
