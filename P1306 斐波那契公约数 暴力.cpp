#include <bits/stdc++.h>
using namespace std;const long long P=1e8;int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,m,a=0,b=1;cin>>n>>m;n=__gcd(n,m);while(n--){long long c=(a+b)%P;a=b;b=c;}cout<<a<<'\n';}
