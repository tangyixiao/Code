#include <bits/stdc++.h>
using namespace std;const long long P=1e8;void f(long long n,long long&a,long long&b){if(!n){a=0;b=1;return;}long long c,d;f(n>>1,c,d);a=c*((2*d-c+P)%P)%P;b=(c*c+d*d)%P;if(n&1){c=a;a=b;b=(c+b)%P;}}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,m,a,b;cin>>n>>m;f(__gcd(n,m),a,b);cout<<a<<'\n';}
