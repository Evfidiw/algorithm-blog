## 【单链表】

- 链表：可在任意位置插入或删除，但只能按顺序访问.
- 单链表：
    - 这里着重介绍用链表实现的邻接表：“链式前向星”
    - 应用：存储图或者树（由邻接矩阵优化）
- 链式前向星：
    - 其实可以理解做，**用数组模拟链表**
    - 情况模拟见 [blog](https://blog.csdn.net/sugarbliss/article/details/86495945) （建议自己在草稿上模拟一遍）

```c++
//从1~n的结点

//无权
//head表示头结点的坐标 
void init(){
	head = -1;
	idx = 0;
} 

void insert_head(int x){
	ver[++idx] = x;
	nxt[idx] = head;
	head = idx;
}

void insert(int k, int x){
	ver[++idx] = x;
	nxt[idx] = nxt[k];
	nxt[k] = idx;
}
insert(k,x);

void remove(int k){
	nxt[k] = nxt[nxt[k]];
}

//带权
// n点:head;		m边:to,edge,nxt; 
// head[x]=idx表示结点x的最后一次加边的下标为idx
// nxt[idx]表示 以该边的起点，添加该边之前的上一次加边的下标; 故链式前向星遍历顺序与插入顺序相反
// to[idx]为这条边的终点 
int idx, head[N], to[M], edge[M], nxt[M];

void init(){
	memset(head, -1, sizeof head);
	idx = 0;
}

void add(int x, int y, int z)	//添加单向边x->y
{
    to[++idx] = y;
    edge[idx] = z;
    nxt[idx] = head[x];
    head[x] = idx;
}

void walk()
{	
	int x = 1;  //头结点 
	for(int i=head[x]; i!=-1; i=nxt[i]){	//以下标x为起点的所有边
		int y=to[i], z=edge[i];
	}
}
```

## 【双链表】

- 双链表：对比于单链表有两个指针：l和r，分别指向后驱元素和前驱元素（即 存储下标）

```c++
int e[N], l[N], r[N], idx;

// 初始化时假定 0为头结点,1为尾结点(即代表指针,该下标不会插入具体的数)
void init(){
	r[0]=1, l[1]=0;
	idx=2;
}

void add(int a, int x){		//在a和r[a]处,下标为idx
	e[idx]=x;
	l[idx]=a, r[idx]=r[a], l[r[a]]=idx, r[a]=idx++;
}
// add(0, x);		//最左侧插入
// add(l[1], x);	//最右侧插入
// add(l[K+1], x);	//第k个数的左侧插入
// add(k+1, x);		//第k个数的右侧插入

void remove(int a){
	l[r[a]]=l[a];
	r[l[a]]=r[a];
}
// remove(k+1);  //idx初始化为2

void walk(){
    for(int i=r[0]; i!=1; 1=r[1]) printf("%d ",e[i]);	
}
```
