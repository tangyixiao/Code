#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long n,p,a=0,b=1;cin>>n>>p;while(n--){unsigned long long c=((__uint128_t)a+b)%p;a=b;b=c;}cout<<a%p<<'\n';}
