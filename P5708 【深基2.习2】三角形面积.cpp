#include<bits/stdc++.h>
using namespace std;
double a,b,c,p;
int main(){
	cin>>a>>b>>c;
	p=(a+b+c)/2.0;
	printf("%.1lf",sqrt(p*(p-a)*(p-b)*(p-c)));
}