## Disjoint Set Union

- 基本原理：每个集合用一颗树来表示。树根的编号就是整个集合的编号。

    用于处理一些不交集的**合并**及**查询**问题

- 原理：
    
    - 查询：
        - 判断两者的祖先是否为同一个
        - 路径压缩：按照上一条的思想，我们只是想找一个根节点来代表这个集合，那我们可以在路径上的每个节点都直接连接到根上（即认同一个节点为父亲），优化复杂度。
    - 合并：
        - 我们任然只需要找一个根节点来代表集合，直接将一个集合的代表作为另一个集合的代表的父亲。
    
- 操作：

    - 维护连通块大小的并查集
    - 维护到祖宗节点距离的并查集

```c++
// model_1
int getf(int x)
{
	if(x!=fa[x]) return  fa[x]=getf(fa[x]);
	return fa[x];
}

void merge(int x,int y)
{
	fa[getf(x)] = getf(y);
}

void find(int x,int y)
{
	if(getf(x)==getf(y)) printf("Y\n");
	else printf("N\n");
}

for(int i=1; i<=n; i++) fa[i]=i;


// model_2
int fa[N], size[n];
void merge(int x, int y)
{
    fa[getf(x)] = getf(y);
    size[getf(y)] += size[getf(x)];
}

for(int i=1; i<=n; i++){
    fa[i]=i;
    size[i]=1;
}


// model_3
int fa[N], d[N], size[N];
int getf(int x)
{
	if(x!=fa[x]){
		int root=getf(fa[x]);
		d[x] += d[fa[x]];	//边权只累加一次就好了
        return fa[x]=root;
    } 
    return fa[x];
}

void merge(int x, int y)
{
	int fx=getf(x), fy=getf(y);
    fa[fx] = fy;
    d[fx] = size[fy];
    size[fy] += size[fx];
}

int find(int x, int y)
{
    if(getf(x) != getf(y)) return -1;
    return abs(d[x]-d[y])-1;
}

for(int i=1; i<=N; i++){	// N代表要全部初始化
    fa[i] = i;
    d[i] = 0;
    size[i] = 1;
}

//getf函数相同，距离为abs(d[a]-d[b])-1
```

## 例题

- 类型：

    - 模板问题，维护一个连通性问题
    - 求连通块个数：for(int i=1; i<=n; i++) if(fa[i]==i) ans++;
    - 边带权的并查集

- eg：

    [eg1](https://github.com/Evfidiw/acm-blog/blob/main/code/2_datastrcture/topics/AcWing1250.cpp)	

## 复杂度

- 推荐阅读：[oiwiki](https://oi-wiki.org/ds/dsu-complexity/)