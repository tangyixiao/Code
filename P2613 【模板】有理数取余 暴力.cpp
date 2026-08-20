#include <bits/stdc++.h>
using namespace std;const long long P=19260817;long long F(long long a,long long b=P-2){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b;cin>>a>>b;cout<<a%P*F(b%P)%P<<'\n';}
