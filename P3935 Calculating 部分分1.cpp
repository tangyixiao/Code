#include <bits/stdc++.h>
using namespace std;const long long P=998244353;int main(){ios::sync_with_stdio(0);cin.tie(0);long long l,r,a=0;cin>>l>>r;for(long long x=l;x<=r;x++)for(long long d=1;d*d<=x;d++)if(x%d==0)a+=1+(d*d<x);cout<<a%P<<'\n';}
