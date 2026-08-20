#include <bits/stdc++.h>
using namespace std;const int N=25;int w[N],t[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,W,r=0;cin>>n>>W;for(int i=0;i<n;i++)cin>>w[i]>>t[i];for(int s=1;s<(1<<n);s++){long long a=0,b=0;for(int i=0;i<n;i++)if(s>>i&1)a+=w[i],b+=t[i];if(a>=W)r=max(r,(int)(b*1000/a));}cout<<r<<'\n';}
