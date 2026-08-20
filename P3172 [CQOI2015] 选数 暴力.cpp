#include <bits/stdc++.h>
using namespace std;const long long P=1000000007;long long n,k,l,h,r;void d(int x,long long g){if(x==n){r+=g==k;return;}for(long long i=l;i<=h;i++)d(x+1,__gcd(g,i));}int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>n>>k>>l>>h;d(0,0);cout<<r%P<<'\n';}
