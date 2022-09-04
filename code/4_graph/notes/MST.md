## 最小生成树

- 定义：
    - 生成树：生成的子图中恰好是一棵树。
    - 最小生成树：一张边带权的无向图中，生成树的边的权值之和最小。
- 思路：
    - 定理：任意一颗最小生成树一定包含无向图中权值最小的边
    - kruskla：
        1. 建立并查集，每个点自成一个集合
            2. 边按权值排序
            3. 若x和y联通则忽略该边，否则合并集合，加边
     - prim：
        1. 确定1号节点属于MST
            2. 最小生成树节点集合为T，剩余节点集合为S，加两个集合各自的点的边，并改变集合

```c++
//kruskal:O(mlogm)
struct Edge{
    int x,y,l;
};

int n,m,fa[N],cnt=0;
ll ans=0;
Edge a[N];

int getf(int p){
    if(fa[p]==p) return p;
    return fa[p]=getf(fa[p]);
}

bool cmp(Edge p,Edge q){
    return p.l<q.l;
}

for(int i=1; i<=m i++) a[i].x=read(),a[i].y=read(),a[i].l=read();
sort(a+1,a+1+m,cmp);
for(int i=1; i<=n; i++) fa[i]=i;
for(int i=1; i<=m i++){
    int x=getf(a[i].x), y=getf(a[i].y);
    if(x==y) continue;
    fa[x]=y;
    ans += a[i].l;
    cnt++;
    if(cnt==n-1) break;
}
if(cnt!=n-1) puts("orz");
else printf("%d\n",ans);


//prim:O(n^2)
void Prim(){
	memset(v,0,sizeof(v));
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	for(int i=1; i<n; i++){
		int x=0;
		for(int j=1; j<=n; j=+)
			if(!v[j] && (x==0||d[j]<d[x])) x=j;
		v[x]=1;
		for(int y=1; y<=n; y++)
			if(!v[y]) d[y]=min(d[y],a[x][y]);
	}
}

for(int i=2; i<=n; i++) ans+=d[i];
```
