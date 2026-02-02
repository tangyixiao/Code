#include<bits/stdc++.h>
using namespace std;

char s[15][15];
int sum[15];
int main() {
	for(int i=1; i<=13; i++) {
		for(int j=1; j<=13; j++) {
			cin>>s[i][j];
		}
	}
	for(int i=1; i<=13; i++) {
		if(i%4==1)	continue;
		memset(sum,0,sizeof(sum));
		for(int j=1; j<=13; j++) {
			if(s[i][j]>='0'&&s[i][j]<='9') {
				sum[s[i][j]-'0']++;
				if(sum[s[i][j]-'0']>1) {
					puts("GRESKA");
					return 0;
				}
			}
		}
	}
	for(int i=1; i<=13; i++) {
		if(i%4==1)	continue;
		memset(sum,0,sizeof(sum));
		for(int j=1; j<=13; j++) {
			if(s[j][i]>='0'&&s[j][i]<='9') {
				sum[s[j][i]-'0']++;
				if(sum[s[j][i]-'0']>1) {
					puts("GRESKA");
					return 0;
				}
			}
		}
	}
	for(int i=1; i<=13; i++) {
		if(i%4!=2)	continue;
		for(int j=1; j<=13; j++) {
			if(j%4!=2)	continue;
			memset(sum,0,sizeof(sum));
			for(int i1=0; i1<=2; i1++) {
				for(int j1=0; j1<=2; j1++) {
					if(s[i+i1][j+j1]>='0'&&s[i+i1][j+j1]<='9') {
						sum[s[i+i1][j+j1]-'0']++;
						if(sum[s[i+i1][j+j1]-'0']>1) {
							puts("GRESKA");
							return 0;
						}
					}
				}
			}
		}
	}
	puts("OK");
	return 0;
}

