#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char a[3114][3114];
int n;
void dfs(int step,int x,int y){
    if(x<=0)return ;
    if(y<=0)return ;
    if(step==1){
        a[x][y]='/';
        a[x][y+1]='\\';
        a[x+1][y-1]='/';
        a[x+1][y]='_';
        a[x+1][y+1]='_';
        a[x+1][y+2]='\\';
        return ;
    }
    dfs(step-1,x,y);
    dfs(step-1,x+pow(2,step-1),y-pow(2,step-1));
    dfs(step-1,x+pow(2,step-1),y+pow(2,step-1));
    return ;
}
int main(){
    memset(a,32,sizeof(a));
    cin>>n;
    dfs(n,1,pow(2,n));
    for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n+1);j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
	return 0;
}

