#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b,x,y;cin>>a>>b;E(a,b,x,y);cout<<(x%b+b)%b<<'\n';}
