// link：
// https://www.luogu.com.cn/problem/P2341

/* think：
	受欢迎的奶牛只能是强连通分量中出度为零的奶牛。
	若出现两个以上出度为0的强连通分量则不存在明星奶牛，因为没有满足所有人都喜欢。 
*/ 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char getc(){
    static char buf[1<<14],*p1=buf,*p2=buf;
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
int read(){
   int s=0,w=1;  
   char ch=getchar();  
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}  
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();  
   return s*w;  
}
#define ll long long
#define inf 0x3f3f3f3f
const int N=10005;

int n,m;
ll ans=0;
int idx=0, num=0, top=0, col;
int head[N], to[N*5], nxt[N*5]; 
int dfn[N], low[N], st[N], co[N];
int si[N], de[N];

void init() 
{
	idx = num = top = 0;
	memset(head, -1, sizeof head);
}

void add(int u,int v)
{
	to[++idx]=v, nxt[idx]=head[u], head[u]=idx;
}

void Tar(int u)
{
	dfn[u] = low[u] = ++num;
	st[++top] = u;
	for(int i=head[u]; i!=-1; i=nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			Tar(v);
			low[u] = min(low[u],low[v]);
		} 
		else if(!co[v]) low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u]){
		co[u] = ++col;
		si[col]++;
		while(st[top]!=u){
			si[col]++;
			co[st[top]] = col;
			top--;
		}
		top--;
	}
}

int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
//	printf("%.3lf M\n",(double)sizeof(/*szm*/)/(1<<20));
//	clock_t start_time=clock();
	init();
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++){
    	int x=read(), y=read();
    	add(y,x);
    }
    for(int i=1; i<=n; i++){
    	if(!dfn[i]) Tar(i);
    }
    for(int i=1; i<=n; i++){
    	for(int j=head[i]; j!=-1; j=nxt[j])
    		if(co[i] != co[to[j]]) de[co[to[j]]]++;
    }
	int tot=0;
    for(int i=1; i<=col; i++){
    	if(!de[i]) ans=si[i], tot++;
    }
    if(tot==1) printf("%lld\n",ans);
    else puts("0");
    
//	clock_t end_time=clock();
//cout<<"Running time is:"<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
//	fclose(stdin);fclose(stdout);
	return 0;
}
