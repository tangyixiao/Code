#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	string c,s;
	cin>>c;
	getchar();
	getline(cin,s);
	c = ' '+c+' ';
	s = ' '+s+' ';
	for(int i=0;c[i];i++){
		c[i] = toupper(c[i]);
	}
	for(int i=0;s[i];i++){
		s[i] = toupper(s[i]);
	} 
	int pos = s.find(c);
	int t = pos;
	if(pos==-1){
		cout<<-1;
		return 0; 
	}
	int cnt = 0;
	while(pos!=-1){
		cnt++;
		pos = s.find(c,pos+1);
	}
	cout<<cnt<<' '<<t<<endl;
	return 0;
}
