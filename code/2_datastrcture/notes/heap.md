## Heap：

- **堆**定义：堆是一棵树。其每个节点都有一个键值，且每个节点的键值都大于等于/小于等于其父亲的键值。
    - tip：一般情况下，直接使用priority_queue大根堆 和 priority_queue<int, vector\<int>, greater\<int> > 小根堆 即可
- **可合并堆**定义：堆 + 可支持合并

## Binary Heap

- 二叉堆本质：完全二叉树，有序排列

- 操作：

    - 插入一个数
    - 求集合中的min（/max）
    - 删除min
    - 删除任意一个元素
    - 修改任意一个元素

- 思路：

    - 插入：

        - 如何保证插入后也是完全二叉树？从最下一层最右边的叶子之后插入；如果最下一层已满，就新增一层。
        - 如何保证插入后仍然满足堆性质？如果这个结点的权值大于它父亲的权值，就交换，重复此过程直到不满足或者到根。向上调整的时间复杂度O(log n).

    - 删除：

        - 若直接删除会变成两个堆。可考虑插入的逆操作，将要删除的结点与最后一个结点交换后直接删除。向下调整的时间复杂度O(log n).

    - 建堆：

        ```c++
        void build_1(){for(int i=1; i<=n; i++) up(i);}
        void build_2(){for(int i=n; i>=1; i--) down(i);}
        ```

- 代码参考：

```c++
int cnt=0, heap[N];

void up(int p)
{
	while(p>1){
		if(heap[p] > heap[p>>1]) swap(heap[p], heap[p/2]), p/=2;
		else break ;
	}
}

void insert(int x)
{ 
	heap[++cnt] = x;
	up(cnt);
}

int gettop()
{
	return heap[1];
}

void down(int p)
{
	#define lson p>>1
	#define rson p>>1|1
	int t = lson;
	while(lson<=cnt){
		if(lson<cnt && heap[lson]<heap[rson]) t++;
		if(heap[lson]>heap[p]) swap(heap[lson], heap[p]), p=lson, t=p*2;
		else break;
	}
}

void remove_top()
{ 
	heap[1] = heap[cnt--];
	down(1);
}

void remove(int k)
{
	heap[k] = heap[cnt--];
	up(k), down(k);
}
```

## Fibonacci Heap

- 定义：最小堆有序树，有根而无序。可理解成一系列具有最小堆序的有根树的集合。
- 配对堆：斐波那契堆中的一种。通常使用“儿子-兄弟表示法”储存，父亲结点用一个指针指向一个子节点，然后其所有子节点用双向链表表示是同一层。

- 操作：
    - 合并  O(1)

- 资料参考：[blog](https://www.cnblogs.com/cytus/p/9477876.html)