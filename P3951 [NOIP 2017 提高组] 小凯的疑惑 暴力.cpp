#include <bits/stdc++.h>
using namespace std;bool v[100000];int main(){ios::sync_with_stdio(0);cin.tie(0);int a,b;cin>>a>>b;for(int i=0;i*a<100000;i++)for(int j=0;i*a+j*b<100000;j++)v[i*a+j*b]=1;for(int i=99999;i>=0;i--)if(!v[i])return cout<<i<<'\n',0;}
