#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){unsigned long long n,m,x=0;cin>>n;m=n;for(unsigned long long i=2;i*i<=m;i++)while(m%i==0)x=i,m/=i;if(m<n&&m>1)x=m;if(!x)cout<<"Prime\n";else cout<<x<<'\n';}}
