#include<iostream>
#include<cmath>
using namespace std;
char ch;
int len;
string s;
int a,b;
void cal(int k) {
	a=b=0;
	for(int i=0; i<len; i++) {
		if(s[i]=='W')
			a++;
		else if(s[i]=='L')
			b++;
		if(max(a,b)>=k&&abs(a-b)>=2) {
			cout<<a<<':'<<b<<'\n';
			a=b=0;
		}
	}
	cout<<a<<':'<<b<<'\n';
	return;
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>ch) {
		if(ch=='W'||ch=='L')
			s+=ch;
		else if(ch=='E')
			break;
	}
	len=s.size();
	cal(11);
	cout<<'\n';
	cal(21);
	return 0;
}
