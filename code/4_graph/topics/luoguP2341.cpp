// link：
// https://www.luogu.com.cn/problem/P2341

/* think：
	受欢迎的奶牛只能是强连通分量中出度为零的奶牛。
	若出现两个以上出度为0的强连通分量则不存在明星奶牛，因为没有满足所有人都喜欢。 
*/ 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
char nc(){
    static char buf[1<<14],*p1=buf,*p2=buf;
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
int read(){
    int s=0,w=1;char ch=nc();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=nc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=nc();
    return s*w;
}

const int maxn=10005;
struct Node{
	int v,from;
};

int n,m,cnt,num,top,col;
ll ans;
int fir[maxn],dfn[maxn],low[maxn],st[maxn],co[maxn],si[maxn],de[maxn];
Node e[maxn*5];
	
void add(int u,int v)
{
	e[++cnt].v=v,e[cnt].from=fir[u],fir[u]=cnt;
}

void Tar(int u)
{
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=fir[u];i;i=e[i].from){
		int v=e[i].v;
		if(!dfn[v]){
			Tar(v);
			low[u]=min(low[u],low[v]);
		} else 
		if(!co[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		co[u]=++col;
		si[col]++;
		while(st[top]!=u){
			si[col]++;
			co[st[top]]=col;
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
    n=read(),m=read();
    for(int i=1; i<=m; i++){
    	int x=read(),y=read();
    	add(y,x);
    }
    for(int i=1; i<=n; i++){
    	if(!dfn[i]) Tar(i);
    }
    for(int i=1; i<=n; i++){
    	for(int j=fir[i];j;j=e[j].from)
    		if(co[i]!=co[e[j].v]) de[co[e[j].v]]++;
    }
	int tot=0;
    for(int i=1; i<=col; i++){
    	if(!de[i]) ans=si[i],tot++;
    }
    if(tot==1) printf("%lld\n",ans);
    else puts("0");
    
//	clock_t end_time=clock();
//cout<<"Running time is:"<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
//	fclose(stdin);fclose(stdout);
	return 0;
}
