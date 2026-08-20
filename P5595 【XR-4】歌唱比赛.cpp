#include<bits/stdc++.h>
using namespace std;
string s,a,b;
int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>s;char p='Z';for(char c:s){if(c=='Z'&&p!='Z')return cout<<-1<<'\n',0;if(c==p)a+='0',b+='0';else if(c=='X')a+='1',b+='0';else if(c=='Y')a+='0',b+='1';else a+='0',b+='0';p=c;}reverse(a.begin(),a.end());reverse(b.begin(),b.end());cout<<a<<'\n'<<b<<'\n';}
