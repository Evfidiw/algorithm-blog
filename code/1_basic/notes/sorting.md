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

- 时间复杂度：
    
    - 最坏情况: T(n) = T(n-l)+T(O)+O(n) = T(n-1) +O(n)
    - 最好情况: T(n) = 2T(n/2) + O(n)
    - 平均情况: 任何一种常数比例的划分都会产生深度为O(logn) 的递归树，每一层的时间代价都是O(n)
    
- 应用：

    1. [第k大数](https://github.com/Evfidiw/acm-blog/blob/main/code/1_basic/topics/luoguP1138.cpp)
    
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

- 思想：分治的思想，不断从数组中取出当前最小值至辅助数组即可使其有序。（快排在分的过程中要保持相对的大小关系）
- 应用：
    
1. [逆序对](https://github.com/Evfidiw/acm-blog/blob/main/code/1_basic/topics/luoguP1908.cpp)
    
- 代码参考：

    ``````c++
    struct size{
        double x, y;
        bool operator <(const Node &b) const{
    		return y<b.y;
    	}
    };
    
    void merge_sort(int l, int r){
    	if(l >= r) return;
    	int mid = l+r>>1;
    	merge_sort(l, mid);
    	merge_sort(mid+1, r);
    	int k=0, i=l, j=mid+1;
    	while(i<=mid && j<=r){
    		if(a[i]<=a[j]) b[k++] = a[i++];
    		else b[k++] = a[j++];
    	}
    	while(i <= mid) b[k++] = a[i++];
    	while(j <= r) b[k++] = a[j++];
    	for(i=l,j=0; i<=r; i++,j++) a[i] = b[j];
    }
    ``````

## 其它

### 堆排序

（更详细介绍见 数据结构--堆）

### 计数排序

- 思想：使用一个额外的数组 ，其中第i 个元素是待排序数组中的值等于i 的元素的个数

    1. 计算每个数出现了几次；
    2. 求出每个数出现次数的前缀和；
    3. 利用出现次数的前缀和，从右至左计算每个数的排名。

- 代码参考：

    ``````c++
    void counting_sort() {
      for(int i=1; i<=n; i++) cnt[a[i]]++;
      for(int i=1; i<=k; i++) cnt[i] += cnt[i-1];
      for(int i=n; i>=1; i--) b[cnt[a[i]]--] = a[i]; //倒序 保证原数组里面相同项相对位置不变
    }
    //时间复杂度:O(n+k)
    ``````

### 基数排序

- 思想：一种非比较型的排序。将待排序的元素拆分为k个关键字（比较两个元素时，先比较第一关键字，如果相同再比较第二关键字……），然后先对第k关键字进行稳定排序，再对第k-1关键字进行稳定排序，再对k-2关键字进行稳定排序……

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
  
- 参考链接：[oiwiki](https://oi-wiki.org/basic/sort-intro/)