#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int x,y,r=0;cin>>x>>y;for(int a=x;a<=y;a+=x)for(int b=x;b<=y;b+=x)if(__gcd(a,b)==x&&1LL*a/__gcd(a,b)*b==y)r++;cout<<r<<'\n';}
