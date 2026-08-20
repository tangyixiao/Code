#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],w[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,z=0;char c;cin>>n>>m;for(int i=0;i<m;i++)cin>>c>>a[i]>>b[i],w[i]=c=='D';for(int s=0;s<(1<<n);s++){bool f=1;for(int i=0;i<m;i++)f&=(((s>>a[i]-1)^(s>>b[i]-1))&1)==w[i];z+=f;}if(!z)return cout<<0<<'\n',0;cout<<bitset<20>(z).to_string().substr(20-(int)log2(z)-1)<<'\n';}
