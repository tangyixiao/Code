#include<bits/stdc++.h>
using namespace std;
const int N = 201;
int t,n,m,x,y,l[N],r[N],a[N],b[N],ans;
int main(){
    cin >> t;
    while(t--){
    	cin >> n >> m >> x >> y;
    	ans = 0;
    	for(int i = 1;i <= x;i++){
    		cin >> l[i] >> r[i];
		}
		for(int i = 1;i <= y;i++){
			cin >> a[i] >> b[i];
		}
		for(int i = 1;i <= x;i++){
			for(int j = 1;j <= y;j++){
				ans += max(0,(min(r[i],b[j]) - max(l[i],a[j]) + 1) - m + 1);
			}
		}
		cout << ans << endl;
	}
}
