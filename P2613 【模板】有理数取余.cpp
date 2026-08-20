#include <bits/stdc++.h>
using namespace std;const long long P=19260817;long long Q(string s){long long x=0;for(char c:s)x=(x*10+c-48)%P;return x;}long long F(long long a,long long b=P-2){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);string a,b;cin>>a>>b;cout<<Q(a)*F(Q(b))%P<<'\n';}
