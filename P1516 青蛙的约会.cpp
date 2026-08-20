#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long x,y,m,n,L,a,b;cin>>x>>y>>m>>n>>L;long long q=m-n,d=E(abs(q),L,a,b),c=y-x;if(q<0)a=-a;if(c%d)return cout<<"Impossible\n",0;L/=d;cout<<(long long)(((__int128)a*(c/d)%L+L)%L)<<'\n';}
