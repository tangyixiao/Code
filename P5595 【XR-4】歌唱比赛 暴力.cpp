#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N],b[N];
string s;
int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>s;char z='Z';for(int i=0;i<s.size();i++){bool f=0;for(int x=0;x<10&&!f;x++)for(int y=0;y<10&&!f;y++){char q=x>y?'X':x<y?'Y':z;if(q==s[i])a[i]=x+'0',b[i]=y+'0',z=q,f=1;}if(!f)return cout<<-1<<'\n',0;}for(int i=s.size()-1;i>=0;i--)cout<<a[i];cout<<'\n';for(int i=s.size()-1;i>=0;i--)cout<<b[i];cout<<'\n';}
