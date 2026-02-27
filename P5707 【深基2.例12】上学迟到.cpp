#include<bits/stdc++.h>
using namespace std;
double s,v;
int n,h,m;
int main() {
	cin>>s>>v;
	n=1910-ceil(s/v);
	if(n>=1440) n-=1440;
	h=n/60,m=n%60;
	if(h<10) {
		cout<<"0";
	}
	cout<<h<<":";
	if(m<10) {
		cout<<"0";
	}
	cout<<m;
	return 0;
}