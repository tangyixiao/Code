#include<bits/stdc++.h>
using namespace std;
#define intl ong long 
string s;
char x;
signed main(){
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(cin>>x&&x!='E')
        if(x=='W'||x=='L')s+=x;
    for(int i=0,suma=0,sumb=0;i<s.size();i++){
        if(s[i]=='W')suma++;
        if(s[i]=='L')sumb++;
        if(suma==11||sumb==11||i==s.size()-1){
            cout<<suma<<":"<<sumb<<'\n';
            suma=sumb=0;
        }
    }
    cout<<'\n';
    for(int i=0,suma=0,sumb=0;i<s.size();i++){
        if(s[i]=='W')suma++;
        if(s[i]=='L')sumb++;
        if(suma==21||sumb==21||i==s.size()-1){
            cout<<suma<<":"<<sumb<<'\n';
            suma=sumb=0;
        }
    }
    return 0;
}
/*
WWWWWWW  WWWWWWWW W   
WW W W 
WWL W E
*/