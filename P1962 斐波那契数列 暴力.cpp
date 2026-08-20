#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long n;cin>>n;long long a=0,b=1;while(n--){long long c=(a+b)%P;a=b;b=c;}cout<<a<<'\n';}
