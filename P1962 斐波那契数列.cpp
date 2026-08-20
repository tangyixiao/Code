#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;void f(unsigned long long n,long long&a,long long&b){if(!n){a=0;b=1;return;}long long c,d;f(n>>1,c,d);a=c*(2*d-c+P)%P;b=(c*c+d*d)%P;if(n&1){c=a;a=b;b=(c+b)%P;}}
int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long n;long long a,b;cin>>n;f(n,a,b);cout<<a<<'\n';}
