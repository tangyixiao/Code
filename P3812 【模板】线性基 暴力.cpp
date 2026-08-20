#include <bits/stdc++.h>
using namespace std;const int N=25;unsigned long long a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];unsigned long long r=0;for(unsigned long long s=0;s<(1ULL<<n);s++){unsigned long long x=0;for(int i=0;i<n;i++)if(s>>i&1)x^=a[i];r=max(r,x);}cout<<r<<'\n';}
