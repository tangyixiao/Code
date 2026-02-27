#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,x;
int main() {
	cin>>a>>b>>c>>d;
	x=60*(c-a)+(d-b);
	cout<<x/60<<" "<<x%60;
	return 0;
}