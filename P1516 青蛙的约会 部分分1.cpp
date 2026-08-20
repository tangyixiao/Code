#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long x,y,m,n,L;cin>>x>>y>>m>>n>>L;for(int t=0;t<=L;t++)if((x+m*t-y-n*t)%L==0)return cout<<t<<'\n',0;cout<<"Impossible\n";}
