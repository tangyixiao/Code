#include<bits/stdc++.h>
using namespace std;
bool f;
int a;
signed main(){
	cin>>a;
	if(a%4){
		f=0;
	}else{
		if(a%100){
			f=1;
		}
		else{
			if(a%400){
				f=0;
			}
			else{
				if(a%3200){
					f=1;
				}
				else{
					if(a%172800){
						f=0;
					}
					else{
						f=1;
					}
				}
			}
		}
	}
	if(f){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}
