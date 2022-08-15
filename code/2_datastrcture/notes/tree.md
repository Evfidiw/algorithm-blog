## Binary Tree

- 完全二叉树
    - 第k层有2^k个结点（从0开始计数）
    - 对于一个结点k，其左子节点2k和右子节点2k+1

- 层次遍历：宽度优先遍历（Breadth-First Search)

    - 定义：每次都尝试访问同一层的节点。 如果同一层都访问完了，再访问下一层。这样做的结果是，BFS找到的路径是从起点开始的**最短**合法路径。

    - 思路：用一个队列来维护访问。假设此时队列刚好存进树的x层结点，则按顺序将x层中的结点出队，并将其子节点入队。用 链式前向星+标记该点是否访问过 可实现。

        ```c++
        //bfs有“两段性”和“单调性” 
        //d[x]是点x在树中的深度 
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
        }
        ```

- 递归遍历：深度优先遍历（Depth-First Search）
    - 遍历顺序：
        - 先序遍历：PreOrder(T)	=	根结点T —— PreOrder(T的左子树) —— PreOrder(T的右子树)
        - 中序遍历：InOrder(T)       =    InOrder(T的左子树) —— 根节点T —— InOrder(T的右子树)
        - 后序遍历：PostOrder(T)   =    PostOrder(T的左子树) —— PostOrder(T的右子树) —— 根节点T
    - 定义和思路：遍历的时候，先将结点其一子树遍历完后，再遍历另一子树。此时递归调用子节点即可。

    ```c++

    void dfs(int x){
        v[x]=1;
        for(int i=head[x]; i!=-1; i=nxt[i]){
            int y=to[i];
            if(v[y]) continue;
            dfs(y);
        }
    }
    ```