## 二分

### 二分查找

- 定义：

    每次对中间元素进行判断：

    	1. 判断其刚好是要找的，就结束搜索过程；
     	2. 如果中间元素小于所查找的值，那么左侧的只会更小，不会有所查找的元素，只需到右侧查找；
     	3. 如果中间元素大于所查找的值同理，只需到左侧查找

- 本质：查找**边界**（当l=r时即找到目标值）

    - eg：有单调一定可以二分，但二分也不一定需要单调

- 复杂度：

    - 时间O(nlogn)

- 方案：

    - 整数区间内，对于区间 [l, r] 怎么划分呢？有两种方案：

        - 划分成 [l, mid] 和 [mid+1, r]，对应后面的方案1
        - 划分成 [l, mid-1] 和 [mid, r] ，对应后面的方案2

    - **tip**：输出l=r，根据check函数得到的r和l决定用哪个配套的mid，然后直接套模板

    - 思考：

        - 那么为什么需要两种方案，且可以分别对应不同的要求？

            将区间看做一条数轴。在整数中，取mid时会取整。而向下取整（即方案1），l=r时会取到左闭区间；向上取整（即方案2），l=r时则会取到右闭区间。

            （若仍无法理解，建议在草稿纸上画一段数轴，所求目标画成其中一段区间，不断取mid进行模拟）

        - while中的条件，mid、l和r的取值是怎么写出来的？

            l和r 取值是根据两种方案需求得到的；

            方案二的mid需要+1是为了防止死循环，而需要+1；

            l、r、mid确定的情况下，若while内l=r则同样会造成死循环

            （在我们了解了怎么写出来之后，自己在写题其实是根据条件写模板，与思考的过程相反。）

- 模板：

```c++
//整数
int bsearch_1(int l, int r){	//找符合条件的最小值
    while(l < r){
        int mid = l+r >> 1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    return l;
}

int bsearch_2(int l, int r){	//找符合条件的最大值
    while(l < r){
        int mid = l+r+1 >> 1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    return l;
}

//实数
double bsearch_3(double l, double r){
    const double eps = 1e-7;   // eps 表示精度，取决于题目对精度的要求
    while(r-l > eps){
        double mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```

### 二分答案

- 定义：

    假设已写出一个函数判断答案是否正确，然后二分法枚举范围，将每个元素代进函数看是否正确

- eg：
    - lower_bound/upper_bound （返回的是指针位置）

    - 求 最大值最小、最小值最大

    - 朴素地枚举O(n)进行判断将会超时，而此时二分答案来判断则**优化**到O(logn)

        [eg1](https://github.com/Evfidiw/acm-blog/blob/main/code/1_basic/topics/luoguP1873.cpp)  [eg2](https://github.com/Evfidiw/acm-blog/blob/main/code/codeforces/402D%20div2.cpp)

- **tip**两步走：

    	1. 判断：二分的判断就是暴力；
     	2. 二分：然后优化枚举范围的效率罢了；

## 三分

- 应用：

    - 求一个函数的极值：

        二分法求零点，那么直接求导后用二分法？但如果函数很难求导呢？

        以求极大值为例，[l, r] 中任取两点lmid, rmid (lmid < rmid) 

        - 若f(lmid) < f(rmid)，则极大值在 [lmid, r] , l = lmid；

        - 若f(lmid) > f(rmid)，则极大值在 [l, rmid] , r = rmid；

            （此处可以画图帮忙理解）

        重复进行直至 r-l 在精度范围要求之内

```c++
//	求极大值
double F(double x){
	double sum=0;
	for(int i=0; i<=n; i++) sum=sum*x+a[i];	//a[]是函数从高到低的各项系数
	return sum; 
}

while(r-l>=eps){
	double mid=(l+r)/2, fl=F(mid-eps), fr=F(mid+eps);
	if(fl<fr) l=mid;
	else r=mid;
}
```

## 