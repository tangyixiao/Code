from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=2000000;int p[N+5],u[N+5],s[N+5];bool v[N+5];long long f[N+5];unordered_map<long long,long long>a,b;long long F(long long n){if(n<=N)return f[n];auto t=a.find(n);if(t!=a.end())return t->second;long long r=n*(n+1)/2;for(long long l=2,q;l<=n;l=q+1){q=n/(n/l);r-=(q-l+1)*F(n/l);}return a[n]=r;}long long M(long long n){if(n<=N)return s[n];auto t=b.find(n);if(t!=b.end())return t->second;long long r=1;for(long long l=2,q;l<=n;l=q+1){q=n/(n/l);r-=(q-l+1)*M(n/l);}return b[n]=r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int z=0;u[1]=1;f[1]=1;for(int i=2;i<=N;i++){if(!v[i])p[z++]=i,u[i]=-1,f[i]=i-1;for(int j=0;j<z&&1LL*i*p[j]<=N;j++){v[i*p[j]]=1;if(i%p[j]==0){u[i*p[j]]=0;f[i*p[j]]=f[i]*p[j];break;}u[i*p[j]]=-u[i];f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=1;i<=N;i++)s[i]=s[i-1]+u[i],f[i]+=f[i-1];int T;cin>>T;while(T--){long long n;cin>>n;cout<<F(n)<<' '<<M(n)<<'\n';}}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;const int N=1000005;int p[N],u[N],s[N],q[1005];bool v[N];long long f[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int T,m=0,z=0;cin>>T;for(int i=0;i<T;i++)cin>>q[i],m=max(m,q[i]);u[1]=1;f[1]=1;for(int i=2;i<=m;i++){if(!v[i])p[z++]=i,u[i]=-1,f[i]=i-1;for(int j=0;j<z&&i*p[j]<=m;j++){v[i*p[j]]=1;if(i%p[j]==0){u[i*p[j]]=0;f[i*p[j]]=f[i]*p[j];break;}u[i*p[j]]=-u[i];f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=1;i<=m;i++)s[i]=s[i-1]+u[i],f[i]+=f[i-1];for(int i=0;i<T;i++)cout<<f[q[i]]<<' '<<s[q[i]]<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):2147483647;mt19937_64 g(s);int T=g()%10+1;cout<<T<<'\n';while(T--)cout<<g()%min(2147483647ULL,max(1ULL,z))+1<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=100000,V=100;int p[N+5],u[N+5],s[N+5];bool v[N+5];long long f[N+5];unordered_map<long long,long long>a,b;long long F(long long n){if(n<=V)return f[n];auto t=a.find(n);if(t!=a.end())return t->second;long long r=n*(n+1)/2;for(long long l=2,q;l<=n;l=q+1){q=n/(n/l);r-=(q-l+1)*F(n/l);}return a[n]=r;}long long M(long long n){if(n<=V)return s[n];auto t=b.find(n);if(t!=b.end())return t->second;long long r=1;for(long long l=2,q;l<=n;l=q+1){q=n/(n/l);r-=(q-l+1)*M(n/l);}return b[n]=r;}int main(int C,char**w){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(w[1]):1000;unsigned long long z=C>2?stoull(w[2]):1;mt19937_64 g(z);int k=0;u[1]=1;f[1]=1;for(int i=2;i<=N;i++){if(!v[i])p[k++]=i,u[i]=-1,f[i]=i-1;for(int j=0;j<k&&i*p[j]<=N;j++){v[i*p[j]]=1;if(i%p[j]==0){u[i*p[j]]=0;f[i*p[j]]=f[i]*p[j];break;}u[i*p[j]]=-u[i];f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=1;i<=N;i++)s[i]=s[i-1]+u[i],f[i]+=f[i-1];while(R--){int n=g()%N+1;if(F(n)!=f[n]||M(n)!=s[n])return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4213','P4213 【模板】杜教筛',r'''预处理一段欧拉函数与莫比乌斯函数前缀。利用 $\varphi*1=id$ 和 $\mu*1=\varepsilon$，对超过预处理范围的 $n$ 递归分块：

$$S_\varphi(n)=\frac{n(n+1)}2-\sum_{l=2}^n(r-l+1)S_\varphi(\lfloor n/l\rfloor),$$

$$S_\mu(n)=1-\sum_{l=2}^n(r-l+1)S_\mu(\lfloor n/l\rfloor).$$

用哈希表记忆化相同商值。''',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1\n1\n','1 1\n'),('2\n2\n10\n','2 0\n32 -1\n'),('2\n100\n1000\n','3044 1\n304192 2\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=2097152;const double P=acos(-1);complex<double>a[N],b[N];int r[N];void f(complex<double>*a,int n,int o){for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);for(int l=2;l<=n;l<<=1){complex<double>w(cos(2*P/l),o*sin(2*P/l));for(int i=0;i<n;i+=l){complex<double>x(1);for(int j=0;j<l/2;j++,x*=w){auto u=a[i+j],v=x*a[i+j+l/2];a[i+j]=u+v;a[i+j+l/2]=u-v;}}}if(o<0)for(int i=0;i<n;i++)a[i]/=n;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,l=1,k=0;cin>>n>>m;while(l<=n+m)l<<=1;while((1<<k)<l)k++;for(int i=0;i<=n;i++){double x;cin>>x;a[i]=x;}for(int i=0;i<=m;i++){double x;cin>>x;b[i]=x;}for(int i=1;i<l;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));f(a,l,1);f(b,l,1);for(int i=0;i<l;i++)a[i]*=b[i];f(a,l,-1);for(int i=0;i<=n+m;i++)cout<<(long long)(a[i].real()+.5)<<' ';cout<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const int N=2000005;long long a[N],b[N],c[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<=n;i++)cin>>a[i];for(int i=0;i<=m;i++)cin>>b[i];for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)c[i+j]+=a[i]*b[j];for(int i=0;i<=n+m;i++)cout<<c[i]<<' ';cout<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(1000000ULL,max(1ULL,z))+1,m=g()%min(1000000ULL,max(1ULL,z))+1;cout<<n<<' '<<m<<'\n';for(int i=0;i<=n;i++)cout<<g()%10<<' ';cout<<'\n';for(int i=0;i<=m;i++)cout<<g()%10<<' ';cout<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=256;const double P=acos(-1);complex<double>a[N],b[N];int r[N];long long c[N];void f(complex<double>*a,int n,int o){for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);for(int l=2;l<=n;l<<=1){complex<double>w(cos(2*P/l),o*sin(2*P/l));for(int i=0;i<n;i+=l){complex<double>x(1);for(int j=0;j<l/2;j++,x*=w){auto u=a[i+j],v=x*a[i+j+l/2];a[i+j]=u+v;a[i+j+l/2]=u-v;}}}if(o<0)for(int i=0;i<n;i++)a[i]/=n;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%60,m=g()%60,l=1,k=0;while(l<=n+m)l<<=1;while((1<<k)<l)k++;memset(a,0,sizeof a);memset(b,0,sizeof b);memset(c,0,sizeof c);for(int i=0;i<=n;i++)a[i]=g()%10;for(int i=0;i<=m;i++)b[i]=g()%10;for(int i=1;i<l;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)c[i+j]+=(long long)a[i].real()*(long long)b[j].real();f(a,l,1);f(b,l,1);for(int i=0;i<l;i++)a[i]*=b[i];f(a,l,-1);for(int i=0;i<=n+m;i++)if((long long)(a[i].real()+.5)!=c[i])return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3803','P3803 【模板】多项式乘法（FFT）',r'''把长度补到不小于 $n+m+1$ 的二次幂。迭代 FFT 先按二进制翻转置换，再逐层进行蝴蝶变换；两个系数数组正变换后逐点相乘，逆变换并四舍五入得到整数系数。

复杂度 $O((n+m)\log(n+m))$，数组长度上限为 $2^{21}$。''',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('0 0\n7\n8\n','56\n'),('2 2\n1 0 1\n1 1 1\n','1 1 2 1 1\n'),('3 1\n0 1 2 3\n4 5\n','0 4 13 22 15\n')])
