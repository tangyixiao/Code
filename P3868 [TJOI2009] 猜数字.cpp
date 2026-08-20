#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}
const int N=15;long long a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)cin>>b[i];long long m=1,r=0;for(int i=0;i<n;i++){long long x,y,d=E(m,b[i],x,y),q=b[i]/d,t=(long long)((__int128)(a[i]-r)/d*x%q);r=(long long)(((__int128)r+(__int128)m*t)%(m*q));m*=q;if(r<0)r+=m;}cout<<r<<'\n';}
