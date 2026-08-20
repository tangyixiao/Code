#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int n,r=0;cin>>n;for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((i||j)&&__gcd(i,j)==1)r++;cout<<r<<'\n';}
