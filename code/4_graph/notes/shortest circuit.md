## Dijkstra

贪心选择全局最小值进行标记和拓展

1. 初始化dist[i] 值（表示起点到节点i 的最短路径长度），除起点外其它值为正无穷大
2. 找一个未被标记 且dist[x]最小的节点x，并标记x
3. 扫描x的出边，求最短dist
4. 重复2、3直到所有点被标记

- apply：

    - 抽象为边权均非负的单源最短路问题

    - 边权计算为乘法：初始dist[st]=1; q.push({1,st}); add(x,y,1.0-z/100);

    - 求log(w1∗w2∗..)=log(w1)+log(w2)+..最大，且w都小于1：求取反后的最小值  

        dist[y] > dist[x]+z；q.push({dist[y], y});

    - 像“昂贵的聘礼 ”，有限制条件的加边，在if(dist[y] > dist[x]+z) 时加上限制条件

```c++
//O(n^2) 用于稠密图
int dijkstra(int st)
{
    memset(dist, 0x3f, sizeof dist);
    dist[st] = 0;
    for(int i=1; i<n; i++){
        int x = 0;     // step 2
        for(int j=1; j<=n; j++){
            if(v[j]) continue;
            if(x==0 || dist[x]>dist[j]) x = j;
    	}
        v[x] = 1;
        for (int j = 1; j <= n; j ++ )	// step 3
            dist[j] = min(dist[j], dist[x] + g[x][j]);
    }
}

//O(mlogn) 用于稀疏图
int dis[N];
bool v[N];
priority_queue< pair<int, int> > q;	
//pair的第一堆为dist的相反数（变成小根堆）
//用链式前向星加边
void dijkstra(int st)
{
	for(int i=1; i<=n; i++) dist[i]=inf;
	memset(v, 0, sizeof(v));
	dist[st]=0;
	q.push({0,st});
	while(q.size()){
		int x=q.top().second; q.pop();
		if(v[x]) continue;
		v[x]=1;
		for(int i=head[x]; i!=-1; i=nxt[i]){
			int y=to[i], z=edge[i];
			if(dist[y] > dist[x]+z){
				dist[y] = dist[x]+z;
				q.push({-dist[y], y});
			}
		}
	}
}
```

## SPFA

取出队头节点x，扫描其所有出边，满足三角形不等式的则更新y；同时y不在队列中则将y入队

- apply：
    - 用于有负边权的单源最短路问题

```c++
//Bellman-Ford:O(nm)
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
// 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for (int i = 0; i < n; i ++ ){
        for (int j = 0; j < m; j ++ ){
            int a=edges[j].a, b=edges[j].b, w=edges[j].w;
            if (dist[b] > dist[a] + w)
                dist[b] = dist[a] + w;
        }
    }

//SPFA:O(km),k为常数；有可能退化为O(nm)
//用链式前向星加边
void spfa(int st)
{
	for(int i=1; i<=n; i++) dist[i]=inf;
	memset(v, 0, sizeof(v));
    queue<int> q;
	dist[st]=0; v[st]=1; q.push(st);
	while(q.size()){
		int x=q.front(); q.pop();
		v[x]=0;
		for(int i=head[x]; i!=-1; i=nxt[i]){
			int y=to[i], z=edge[i];
			if(dist[y] > dist[x]+z){
				dist[y] = dist[x]+z;
				if(!v[y]) q.push(y), v[y]=1;
			}
		}
	} 
}
```

## floyd

- apply：
    - 多源多汇最短路径（不能有负环）
        - eg：Maxstep[i]=max(step[i] [j], Maxstep[i]) ; ans2 = max{ Maxstep[i]+dis(i,j)+Maxstep[j] }.
    - 传递闭包
    - 找最小环
    - 恰好经过k条边的最短路（倍增）

```c++
//O(n^3)
//初始化：
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
	//d[x][y]=z 直接加边

// 算法结束后，d[a][b]表示a到b的最短距离
void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

//传递闭包
//d[i,j]=0表示没有关系；d[i,i]恒为1；
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] |= d[i][k] & d[k][j];
```

## eg

