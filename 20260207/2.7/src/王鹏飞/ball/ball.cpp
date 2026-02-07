#include<bits/stdc++.h>
using namespace std;
inline read(){
	int ma=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(('0'<=c&&c<='9')){ma=(ma<<3)+(ma<<1)+c-'0';}
	return ma*f;
}
string s;
signed main(){
	freopen("ball.in","r",stdin);freopen("ball.out","w",stdout);
	string sb;
	while(cin >>sb)s+=sb;
	int i=0,a=0,b=0;
	while(s[i]!='E'){
		if(s[i]=='W')a++;
		else b++;
		if(a==11||b==11){
			cout<<a<<":"<<b<<"\n";
			a=0,b=0;
		}
		i++;
	}
	cout<<a<<":"<<b<<"\n";
	cout<<"\n";
	i=0;a=0,b=0;
	while(s[i]!='E'){
		if(s[i]=='W')a++;
		else b++;
		if(a==21||b==21){
			cout<<a<<":"<<b<<"\n";
			a=0,b=0;
		}
		i++;
	}
	cout<<a<<":"<<b<<"\n";
}
