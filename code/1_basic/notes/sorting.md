## 前言

- 问题：将一串n个数字，按从小到大进行排序？
- 思考：排序的方法有很多，那么重要的是什么呢？窃认为是各算法的思想和应用。下选择几个较为常见的排序方法进行介绍。
    - 附：下文将按照各种排序的**平均时间复杂度**分类 进行介绍

## O(n^2)

### 插入排序

- 思想：将待排列元素划分为“已排序”和“未排序”两部分，每次从“未排序的”元素中选择一个插入到“已排序的”元素中的正确位置
- 时间复杂度：最优情况下O(n)，最坏和平均情况下O(n^2)

- 代码参考：

    ```c++
    void insert_sort(int l,int r){
    	for(int i=l; i<=r; i++){
    		int end=i-1, x=a[i];
    		while(end>=l){
    			if(a[end]>a[end+1]) swap(a[end],a[end+1]),end--;
    			else break;
    		}
    		a[end+1]=x;
    	}
    }
    ```

### 选择排序

- 思想：每次找出第i小的元素，然后将这个元素与数组第i个位置上的元素交换

- 代码参考：

    ``` c++
    void selection_sort(int l,int r){
    	for(int i=l; i<r; i++){
    		int mini=i;
    		for(int j=i+1; j<=r; j++)
    			if(a[j]<a[mini]) mini=j;
    		swap(a[i],a[mini]);
    	}
    }
    ```

### 冒泡排序

- 思想：每次检查相邻两个元素，如果前面的元素与后面的元素满足给定的排序条件，就将相邻两个元素交换。当没有相邻的元素需要交换时，排序就完成了。
    由于在算法的执行过程中，较小的元素像是气泡般"冒泡"到数列的顶端，故叫做冒泡排序。

- 代码参考：

    ``````c++
    void bubble_sort(int l,int r){
    	for(int i=l;i<r;i++){
    		for(int j=l;j<r-i+1;j++)
    			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    	}
    }
    ``````

## O(nlogn)

### 快速排序

- 思想：分治的思想，将数列划分为有相对大小关系两部分，递归到两个子序列中分别进行快速排序（之后不用合并，因为此时数列已经完全有序）

- 代码参考：

    ```c++
    void quick_sort(int l,int r){
    	int i=l, j=r, base;
    	base = a[l+r>>1];
    	while(i<=j){
    		while(a[i]<base) i++;
    		while(a[j]>base) j--;	
    		if(i<=j) swap(a[i],a[j]),i++,j--;
    	}
    	if(i<r) quick_sort(i,r);
    	if(l<j) quick_sort(l,j);
    }
    ```

### 归并排序



## 其它

### 堆排序

（更详细介绍见 数据结构--堆）

### 计数排序



### 基数排序



### 桶排序



## 总结

- 若仍然不清楚各个排序是如何实现的，可参考[可视化图](https://visualgo.net/zh/sorting)

- 如前言所说，强调的重点是思想和应用，如果变成背代码反而“捡了芝麻丢了西瓜”。
    毕竟大多数情况下写题，用的是stl的sort。

- sort函数用法：

    ```c++
    //eg1:
    int a[];	//int数组
    for(int i=0; i<=n; i++){scanf("%d",&a[i]);}
    sort(a+1, a+1+n);	//将a数组 下标1~n进行排序
    sort(a, a+n;)	//将a数组 下标0~n-1进行排序
        
    //eg2:
    vector<int> a;
    sort(v.begin(), v.end());
    
    //eg3:
    bool cmp(int x, int y){return x>y;}
    sort(a+1, a+1+n, cmp);	//a将会按tmp设定进行排序，则从大到小排序
    ```

- 还有\<cstdlib>的qsort，用法与sort一致
    