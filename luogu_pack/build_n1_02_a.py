from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;const double E=1e-9;double a[N][N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)for(int j=0;j<=n;j++)cin>>a[i][j];for(int i=0;i<n;i++){int k=i;for(int j=i+1;j<n;j++)if(abs(a[j][i])>abs(a[k][i]))k=j;if(abs(a[k][i])<E)return cout<<"No Solution\n",0;for(int j=i;j<=n;j++)swap(a[i][j],a[k][j]);for(int j=n;j>=i;j--)a[i][j]/=a[i][i];for(int r=0;r<n;r++)if(r!=i)for(int j=n;j>=i;j--)a[r][j]-=a[r][i]*a[i][j];}cout<<fixed<<setprecision(2);for(int i=0;i<n;i++)cout<<(abs(a[i][n])<.0005?0:a[i][n])<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;long long a[N][N],x[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10;mt19937_64 g(s);int n=g()%min(100ULL,max(1ULL,z))+1;for(int i=0;i<n;i++)x[i]=(long long)(g()%21)-10;cout<<n<<'\n';for(int i=0;i<n;i++){long long b=0;for(int j=0;j<n;j++){a[i][j]=i==j?n*20+1:(long long)(g()%11)-5;b+=a[i][j]*x[j];cout<<a[i][j]<<' ';}cout<<b<<'\n';}}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=15;const double E=1e-8;double a[N][N],o[N][N],x[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%10+1;for(int i=0;i<n;i++){x[i]=(int)(g()%21)-10;for(int j=0;j<n;j++)o[i][j]=a[i][j]=i==j?n*20+1:(int)(g()%11)-5;}for(int i=0;i<n;i++){a[i][n]=0;for(int j=0;j<n;j++)a[i][n]+=a[i][j]*x[j];o[i][n]=a[i][n];}for(int i=0;i<n;i++){int k=i;for(int j=i+1;j<n;j++)if(abs(a[j][i])>abs(a[k][i]))k=j;for(int j=i;j<=n;j++)swap(a[i][j],a[k][j]);for(int j=n;j>=i;j--)a[i][j]/=a[i][i];for(int r=0;r<n;r++)if(r!=i)for(int j=n;j>=i;j--)a[r][j]-=a[r][i]*a[i][j];}for(int i=0;i<n;i++){double z=0;for(int j=0;j<n;j++)z+=o[i][j]*a[j][n];if(abs(z-o[i][n])>E)return cout<<"WA\n",1;}}cout<<"OK\n";}
'''
add('P3389','P3389 【模板】高斯消元法','逐列选取绝对值最大的主元并交换到当前行，再做 Gauss-Jordan 消元。若某列没有非零主元，则方程组没有唯一解。时间复杂度 $O(n^3)$。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':A,' 对拍.cpp':AS},extra=[('1\n2 4\n','2.00\n'),('2\n1 1 3\n1 -1 1\n','2.00\n1.00\n'),('2\n1 1 2\n2 2 4\n','No Solution\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=15;const double E=1e-10;double p[N][N],a[N][N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<=n;i++)for(int j=0;j<n;j++)cin>>p[i][j];for(int i=1;i<=n;i++)for(int j=0;j<n;j++)a[i-1][j]=2*(p[i][j]-p[0][j]),a[i-1][n]+=p[i][j]*p[i][j]-p[0][j]*p[0][j];for(int i=0;i<n;i++){int k=i;for(int j=i+1;j<n;j++)if(abs(a[j][i])>abs(a[k][i]))k=j;for(int j=i;j<=n;j++)swap(a[i][j],a[k][j]);for(int j=n;j>=i;j--)a[i][j]/=a[i][i];for(int r=0;r<n;r++)if(r!=i)for(int j=n;j>=i;j--)a[r][j]-=a[r][i]*a[i][j];}cout<<fixed<<setprecision(3);for(int i=0;i<n;i++)cout<<(i?" ":"")<<(abs(a[i][n])<E?0:a[i][n]);cout<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;const int N=15;double c[N];int main(int z,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=z>1?stoull(v[1]):1,w=z>2?stoull(v[2]):5;mt19937_64 g(s);int n=g()%min(10ULL,max(1ULL,w))+1;for(int i=0;i<n;i++)c[i]=(int)(g()%21)-10;cout<<n<<'\n';double r=g()%10+1;for(int i=0;i<n;i++)cout<<c[i]+(i?0:r)<<' ';cout<<'\n';for(int i=1;i<=n;i++){for(int j=0;j<n;j++)cout<<c[j]+(j==i-1?-r:0)<<' ';cout<<'\n';}}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=15;double p[N][N],a[N][N],x[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%10+1;double r=g()%10+1;memset(a,0,sizeof a);for(int j=0;j<n;j++)x[j]=(int)(g()%21)-10;for(int i=0;i<=n;i++)for(int j=0;j<n;j++)p[i][j]=x[j]+(i==j+1?-r:i==0&&j==0?r:0);for(int i=1;i<=n;i++)for(int j=0;j<n;j++)a[i-1][j]=2*(p[i][j]-p[0][j]),a[i-1][n]+=p[i][j]*p[i][j]-p[0][j]*p[0][j];for(int i=0;i<n;i++){int k=i;for(int j=i+1;j<n;j++)if(abs(a[j][i])>abs(a[k][i]))k=j;for(int j=i;j<=n;j++)swap(a[i][j],a[k][j]);for(int j=n;j>=i;j--)a[i][j]/=a[i][i];for(int q=0;q<n;q++)if(q!=i)for(int j=n;j>=i;j--)a[q][j]-=a[q][i]*a[i][j];}double d=0;for(int j=0;j<n;j++)d+=(a[j][n]-x[j])*(a[j][n]-x[j]);if(d>1e-8)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4035','P4035 [JSOI2008] 球形空间产生器','任取第一个点作基准，将其到球心的距离平方与其余各点对应等式相减，二次项消去后得到 $n$ 元一次方程组，高斯消元求球心。时间复杂度 $O(n^3)$。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':B,' 对拍.cpp':BS},extra=[('1\n0\n2\n','1.000\n'),('2\n1 0\n-1 0\n0 1\n','0.000 0.000\n'),('3\n1 0 0\n-1 0 0\n0 1 0\n0 0 1\n','0.000 0.000 0.000\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;unsigned long long a[64];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;while(n--){unsigned long long x;cin>>x;for(int i=63;i>=0;i--)if(x>>i&1){if(a[i])x^=a[i];else{a[i]=x;break;}}}unsigned long long r=0;for(int i=63;i>=0;i--)r=max(r,r^a[i]);cout<<r<<'\n';}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;const int N=25;unsigned long long a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];unsigned long long r=0;for(unsigned long long s=0;s<(1ULL<<n);s++){unsigned long long x=0;for(int i=0;i<n;i++)if(s>>i&1)x^=a[i];r=max(r,x);}cout<<r<<'\n';}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(50ULL,max(1ULL,z))+1;cout<<n<<'\n';while(n--)cout<<(g()&((1ULL<<50)-1))<<' ';cout<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const int N=20;unsigned long long a[N],b[64];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%12+1;memset(b,0,sizeof b);for(int j=0;j<n;j++){a[j]=g()%100000;unsigned long long x=a[j];for(int i=63;i>=0;i--)if(x>>i&1){if(b[i])x^=b[i];else{b[i]=x;break;}}}unsigned long long x=0,y=0;for(int i=63;i>=0;i--)x=max(x,x^b[i]);for(int z=0;z<(1<<n);z++){unsigned long long q=0;for(int j=0;j<n;j++)if(z>>j&1)q^=a[j];y=max(y,q);}if(x!=y)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3812','P3812 【模板】线性基','从高位到低位插入每个数，得到异或线性基；再从高位到低位贪心尝试异或，使当前答案尽量增大。时间复杂度 $O(64n)$。',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},extra=[('1\n0\n','0\n'),('3\n1 2 4\n','7\n'),('3\n1 2 3\n','3\n')])

D=r'''#include <bits/stdc++.h>
using namespace std;const int P=2008;unsigned long long a[64];char s[55];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,r=0;cin>>n>>m;while(m--){cin>>s;unsigned long long x=0;for(int i=0;i<n;i++)if(s[i]=='O')x|=1ULL<<i;for(int i=63;i>=0;i--)if(x>>i&1){if(a[i])x^=a[i];else{a[i]=x;r++;break;}}}int z=1;while(r--)z=z*2%P;cout<<z<<'\n';}
'''
DB=r'''#include <bits/stdc++.h>
using namespace std;const int N=16;const int P=2008;unsigned long long a[N],b[1<<N];bool v[1<<N];char s[55];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<m;i++){cin>>s;for(int j=0;j<n;j++)if(s[j]=='O')a[i]|=1ULL<<j;}int k=1;b[0]=0;v[0]=1;for(int i=0;i<m;i++){int z=k;for(int j=0;j<z;j++){unsigned long long x=b[j]^a[i];if(!v[x])v[x]=1,b[k++]=x;}}cout<<k%P<<'\n';}
'''
DG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(50ULL,max(1ULL,z))+1,m=g()%min(50ULL,max(1ULL,z))+1;cout<<n<<' '<<m<<'\n';while(m--){for(int i=0;i<n;i++)cout<<(g()&1?'O':'X');cout<<'\n';}}
'''
DS=r'''#include <bits/stdc++.h>
using namespace std;const int P=2008;unsigned long long a[12],b[64];bool q[1<<10];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%10+1,m=g()%10+1,r=0;memset(b,0,sizeof b);memset(q,0,sizeof q);for(int j=0;j<m;j++){a[j]=g()&((1ULL<<n)-1);unsigned long long x=a[j];for(int i=63;i>=0;i--)if(x>>i&1){if(b[i])x^=b[i];else{b[i]=x;r++;break;}}}int x=1;while(r--)x=x*2%P;int k=0;for(int z=0;z<(1<<m);z++){unsigned long long y=0;for(int j=0;j<m;j++)if(z>>j&1)y^=a[j];if(!q[y])q[y]=1,k++;}if(x!=k%P)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3857','P3857 [TJOI2008] 彩灯','每个开关对应一个二进制向量，所有可达状态构成这些向量张成的异或空间。若线性基秩为 $r$，不同状态数就是 $2^r$，对 $2008$ 取模。时间复杂度 $O(NM)$。',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},parts=[DB],extra=[('1 1\nO\n','2\n'),('1 1\nX\n','1\n'),('2 2\nOO\nOO\n','2\n')])
