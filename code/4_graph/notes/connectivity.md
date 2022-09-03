## 连通分量

- 连通：在无向图中，节点vi到节点vj有路径，则称两个节点连通。
- 连通图：若图中任意两个节点都是连通的，则称该图为连通图。
- 连通分量：无向图的极大连通子图称为该图的连通分量。

## 强连通分量

- 强连通图：若一张有向图的节点两两互相可达，则称这张图是强连通的

    强连通分量：通俗点说，如果一个图的子图中，任意两点可以相互到达，那么这就组成了一个强联通分量。

- dfs生成树：如果结点u是某个强连通分量在搜索树中遇到的第一个结点，那么这个强连通分量的其余结点肯定是在搜索树中以u为根的子树中。结点u被称为这个强连通分量的根。(可由反证法证明)

- Tarjan算法求强连通分量：

    - 思路：利用dfs生成树的原理，搜索时把没处理的结点加入一个栈，回溯时判断当前结点能否与栈中结点构成一个强连通分量。分别找到一条条回路，使得初始点又回到初始点。
    - 步骤：
        1. 记录结点u的搜索次序编号（时间戳），以及结点u或者u的子树最多能够回溯到的结点x 且使得时间戳最小。
        2. 将u入栈。
        3. 同时在图中更新枚举的边。
        4. 如果形成了一条回路（即弹出u） ，此时被弹出的所有节点形成了一个强连通分量。

- 模板参考：

    ```c++
    // dfn:时间戳
    // low:记录u能回溯到哪个点 
    
    int idx=0, num=0, top=0, col;
    int head[N], to[N*5], nxt[N*5]; 
    int dfn[N], low[N], st[N], co[N];
    
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
    		while(st[top]!=u){
    			co[st[top]] = col;
    			top--;
    		}
    		top--;
    	}
    }
    
    for (int i = 1; i <= n; i++){
    	if (!dfn[i]) Tar(i);
    }
    printf ("%lld\n", col);	//有col个强连通分量
    for (int i = 1; i <= n; i++){
    	if (vis[i]) continue;
    	printf ("%lld ", i);
    	vis[i] = 1;
    	for (int j=i+1; j<=n; j++){
    		if (co[j] == co[i]){
    			printf ("%lld ", j);
    			vis[j] = 1;
    		}
    	}
    }
    ```

- eg：

    [eg1](https://github.com/Evfidiw/acm-blog/blob/main/code/4_graph/topics/luoguP2341.cpp)	