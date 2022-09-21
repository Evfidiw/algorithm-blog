## 图论常识

- 阅读参考：[oiwiki](https://oi-wiki.org/graph/concept/)

## 存储方式

- 有邻接矩阵，邻接表，链式前向星（在链表一章已介绍过）

- 下直接给出代码参考：

    ```c++
    // 邻接矩阵: Otime(n^2), Ospace(O^2)
    cin >> u >> v;
    dist[u][v] = true;
    
    
    // 链式前向星: dfsO(n+m), Ospace(m)
    int idx, head[N], to[M], edge[M], nxt[M];
    void init(){
    	memset(head, -1, sizeof head);
    	idx = 0;
    }
    
    void add(int x, int y, int z)
    {
        to[++idx] = y;
        edge[idx] = z;
        nxt[idx] = head[x];
        head[x] = idx;
    }
    
    void walk()
    {	
    	int x = 1;
    	for(int i=head[x]; i!=-1; i=nxt[i]){
    		int y=to[i], z=edge[i];
    	}
    }
    ```

## BFS

- 广度优先遍历：按照广度优先搜索（详见搜索一章）的方式对图进行遍历

- “树的深度”模板：

    ```c++
    void bfs(){
    	memset(d, 0,sizeof(d));
    	queue<int> q;
    	q.push(1); d[1]=1;
    	while(q.size()>0){
    		int x=q.front(); q.pop();
    		for(int i=head[x]; i!=-1; i=nxt[i]){
    			int y=ver[i];
    			if(d[y]) continue;
    			d[y]=d[x]+1;
    			q.push(y);
    		} 
    	}
    ```

## DFS

- 深度优先遍历：一直沿着一条路走下去，当无法搜索时进行回溯（可以利用栈实现，而递归就是用栈实现）

- “dfs序”模板

    ```c++
    void dfs(int x){
        a[++cnt]=x;
        v[x]=1;
        for(int i=head[x]; i!=-1; i=nxt[i]){
            int y = to[i];
            if(v[y]) continue;
            dfs(y);
        }
        a[++cnt]=x; 
    }
    ```