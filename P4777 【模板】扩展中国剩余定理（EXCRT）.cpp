#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long m,r;cin>>n>>m>>r;r%=m;while(--n){long long a,b,x,y;cin>>a>>b;long long d=E(m,a,x,y),q=a/d,t=(long long)((__int128)(b-r)/d*x%q);r=(long long)(((__int128)r+(__int128)m*t)%(m*q));m*=q;if(r<0)r+=m;}cout<<r<<'\n';}
