# 	一、六杂

## 【上机模板】

```c++
//#pragma G++ optimize(2)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int read(){
   int s=0,w=1;  
   char ch=getchar();  
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}  
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();  
   return s*w;  
}
#define IOS() ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long
const int inf=0x7f7f7f7f;
const int N=200005;
//苟利国家生死以，岂因祸福避趋之

int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
//	printf("%.3lf M\n",(double)sizeof(/*szm*/)/(1<<20));
//	clock_t start_time=clock();
	//IOS();
	
//	clock_t end_time=clock();
//cout<<"Running time is:"<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
```

## 【STL】

```c++
//vector（要带头文件）
	vector<int> a; //一维，a[]是二维
	for(vector<int>::iterator it=a.begin();it!=a.end();it++) 
		printf("%d ",*it);
	a.size();
	a.empty(); //返回一个bool函数判断是否为空
	a.clear();
	a.begin(); a.end(); //迭代器
	a.front(); a.back(); //相当于*a.begin();
	a.push_back(x); a.pop_back();

//pair
    first, 第一个元素
    second, 第二个元素
    支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
        
    struct{
        void operator+= (const Node &b) {
			*this = Node{fi+b.fi, se+b.se};
		}
    	bool operator< (const Node &b) const{
			return fi<b.fi;
		}
		bool operator> (const Node &b) const{
            return fi>b.fi;
		}
    }

//string
	string a="qwe";
	a.size();a.length(); //都是返回长度
	a.empty();
	a.clear();
	printf("%s",a.c_str());	//输出a
	a.find(str,pos) //1.查找字符串中一个字符/字符串 在pos或及其之后第一次出现的位置
	a.substr(pos, len) //2.返回从pos位置开始截取最多len个字符组成的字符串（若长度不足则取全部）
    //eg:printf("%s\n",a.substr(3, 3).c_str());
	a.insert(index,count,str); a.insert(index,str); //3.插入&删除
    //在index处连续插入 count次字符串str; 插入字符串str。
	a.erase(index,count);//将字符串index 位置开始（含）的 count个字符删除
	a.replace(pos,count,str); a.replace(first,last,str); //4.翻转
	//表示将从 pos位置开始 count个字符的子串替换为 str；
	//first开始（含）到last结束（不含）的子串替换为str（其中first/last均为迭代器，用begin和end）
        
//queue（要带头文件）
	q.size();
	q.empty();
	q.push(x); q.pop();
	q.front(); q.back();

//priority_queue(默认大根堆)
	push(); pop();
	top();
	priority_queue<int, vector<int>, greater<int> > heap;//小根堆

//stack
	push(); pop();
	top();

//deque(效率较低)
	clear();
	front(); back();
	push_back(); pop_back();
	push_front(); pop_front();
	begin(); end();

//以下四个 插入/删除/查询 的时间复杂度为O(logn)
//set,multiset（排序好的map）
	size(); empty(); clear();
	insert();
	s.find(start，end，x)	//返回的是迭代器，eg： *pos = find(res, res + 5, 5);pos是下标
	s.count(x); //返回x的个数
	erase();
	lower_bound(); upper_bound();

//map,multimap（基于红黑树）
	size(); empty(); clear(); begin(); end();
	v.insert(x); v.erase();
	find();//O(logn)
	lower_bound(); upper_bound()
        
#include<unordered_map> //（基于散列表，O(1)）
        
//bitset
```

## ？【高精度】

```c++
for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');

vector<int> add(vector<int> &A,vector<int> &B){//大数加大数
    if(A.size() <B.size()) return add(B,A);
	vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++){
        t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(t);
    return C;
}

vector<int> sub(vector<int> &A,vector<int> &B){//大数减大数，要写个bool函数判断是否需要负号
    vector<int> C;
    for(int i=0,t=0;i<A.size();i++){
    	t=A[i]-t;
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10);
        if(t<0) t=1;
        else t=0;
    }
    while(C.size()>1 && C.back()==0) C.pop_back();
    return C;
}

vector<int> mul(vector<int> &A,int b){//大数乘小数
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size() || t;i++){
        if(i<A.size()) t+=A[i]*b;
		C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1 && C.back()==0) C.pop_back();
	return C;
}

vector<int> div(vector<int> &A,int b,int &r){//大数除以小数
    vector<int> C;
    r=0;
    for(int i=A.size()-1;i>=0;i--){
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back()==0) C.pop_back();
	return C;
}
```

## 【排序】

**【1】基础代码**

- 插入排序
- 选择排序
- 冒泡排序

```c++
//O(n^2)
void sert_sort(int l,int r){
	for(int i=l;i<=r;i++){
		int end=i-1,x=a[i];
		while(end>=l){
			if(a[end]>a[end+1]) swap(a[end],a[end+1]),end--;
			else break;
		}
		a[end+1]=x;
	}
}
    
void choose_sort(int l,int r){
	for(int i=l;i<r;i++){
		int mini=i;
		for(int j=i+1;j<=r;j++)
			if(a[j]<a[mini]) mini=j;
		swap(a[i],a[mini]);
	}
}

void bubble_sort(int l,int r){
	for(int i=l;i<r;i++){
		for(int j=l;j<r-i+1;j++)
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
	}
}
```

- 快速排序
- 归并排序：逆序对

```c++
//O(nlogn)
void quick_sort(int l,int r){
	int i=l, j=r, base;
	base=a[l+r>>1];
	while(i<=j){
		while(a[i]<base) i++;
		while(a[j]>base) j--;	
		if(i<=j) swap(a[i],a[j]),i++,j--;
	}
	if(i<r) quick_sort(i,r);
	if(l<j) quick_sort(l,j);
}
//stl:sort(a,a+n)
//stable_sort(a,a+n)
struct size{
    double x, y;
    bool operator <(const Node &b) const{
		return y<b.y;
	}
};

void merge_sort(int l,int r){	//ultra-quicksort
	if(l>=r) return;
	int mid=l+r>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r){
		if(a[i]<=a[j]) b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	while(i<=mid) b[k++]=a[i++];
	while(j<=r) b[k++]=a[j++];
	for(i=l,j=0;i<=r;i++,j++) a[i]=b[j];
}
```

**【2】应用**

1. 离散化：只关心**大小关系**，用排名代替原数据

- 重点：
    - 原映射组a[]中可能重复：去重
    - 如何查询离散化后的值：二分找下标
- 技巧：map记录的值 是原数值独一的标识
- eg：
    - map[a[i]] = ++cnt，此时map[a[i]]的值能代表这个原数值是否用过了
    - for中if(a[i]!=a[i-1]) map[a[i]] = i，当a[i]用过后map[a[i]]++就能继续用这个映射数值

```c++
void hah(){
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
		if(i==1 || a[i]!=a[i-1]) b[++tot]=a[i];
    //a.erase(unique(a.begin(), a.end()),a.end());
    //int tot = a.size();
}
int find(int x){	//查询映射的数值 
    return lower_bound(b+1, b+tot+1, x) - b;
}//其实.本质是用二分去查找x的下标
//eg:int x=find((*it).first); a[x]+=(*it).second;

//对vector
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
for(int i=0; i<n; i++)	b[i] = lower_bound(a.begin(), a.end(), b[i]) - a.begin();

//也可以用map直接来映射,map<int, int> v;
if(!v[a[i]]) v[a[i]] = ++cnt;//此时a[i]就相当于 手写的find(a[i])
//不管v[a[i]]存的是什么，存的时候要记得去重！
```

2. 第k大数：在快排思想中，每次选取基准值进行一半的递归，时间复杂度接近O(n)

```c++
int quick_sort(int l, int r){
    int i=l, j=r, base=a[l];//选左端点为基准数 
    while(i<j){
        while(i<j && a[j]>base) j--;
        if(i<j) swap(a[i],a[j]);
        while(i<j && a[i]<=base) i++;//从左向右，找到第一个大于基准数得数 
        if(i<j) swap(a[i],a[j]);
    }
    a[i]=base;
    if(i==k) return a[k];
	else if(i>k) return quick_sort(l, i-1);
	else return quick_sort(i+1, r);
}
```

3. 逆序对：归并排序中同时统计逆序的数目 ( "reverse pair" is "swap operations" )

```c++
 else b[k++]=a[j++], cnt += mid-i+1;
```

# 二、高效算法思想

- basic thoughts：得到一个经典模型 与自己所总结的契合

## 【思维】

​	[思维题集笔记](https://www.cnblogs.com/EvfX/p/15938240.html)

- 思考方向：
    - constructive  algorithms，找到切题入口
    - 从“特殊到一般”，即化题目为自己总结的tricks

### 【模拟】

- 巧用implementation 模拟情况
    - 分类讨论
    - 临界情况
    - 极端情况
    - 正序反序都想

### 【贪心】

- 核心：得到最优子结构的步骤，且可证明正确性
    - 微扰（邻项交换法）
        - 国王游戏（邻项交换证明得最小值）
    - 范围缩放
    - 反悔法
        - 截止日期与价值的选择（反悔法：价值与堆(按ddl排序)顶比较）
        - 截止日期与耗时的选择（反悔法：价值与堆(按耗时排序)顶比较）
- 本质：对于 “排序”or“选择”的策略 的思考

## 【二分】

- 二分查找：
    - 本质：边界（当l=r时即找到目标值）
    - 应用：有单调一定可以二分，但二分也不一定需要单调
    - 理解：输出l=r，根据check函数得到的r和l决定用哪个配套的mid

```c++
//整数
int bsearch_1(int l, int r){	//找符合条件的最小值
    while (l < r){
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bsearch_2(int l, int r){	//找符合条件的最大值
    while (l < r){
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

//实数
double bsearch_3(double l, double r){
    const double eps = 1e-7;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps){
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```

- 二分答案：假设这个函数的答案就是对的，然后二分枚举范围
    - eg：定序的分段的最大值最小；
- lower_bound/upper_bound 返回的是指针位置
- 三分：求极值（二分法求零点）

```c++
double F(double x){
	double sum=0;
	for(int i=0; i<=n; i++) sum=sum*x+a[i];	//a[]是函数从高到低的各项系数
	return sum; 
}

while(r-l>=eps){
		double mid = (l+r)/2, fl=F(mid-eps), fr=F(mid+eps);
		if(fl<fr) l=mid;
		else r=mid;
}
```

## 【前缀和与差分】

- 前缀和：

```c++
//一维
a[l]+···++a[r]=ans[r]-ans[l-1]

//二维
ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+a[i][j];

a[x_1][y_1]+...a[x_1][y_2]+a[x_1][y_1+1]+...+a[x_2][y_2]
=ans[x_2][y_2]-ans[x_1-1][y_2]-ans[x_2][y_1-1]+ans[x_1-1][y_1-1]);

//但如果二维前缀和给定的数据范围是n×m？
ans[i*m+j] = ans[(i-1)*m+j]+ans[i*m+j-1]-ans[(i-1)*m+j-1]+x;
printf("%d\n",ans[x2*m+y2]+ans[(x1-1)*m+y1-1]-ans[x2*m+y1-1]-ans[(x1-1)*m+y2] );
```

- 差分：
    - 前缀和的逆运算
    - 应用：多次的区间修改，并查询修改后的值（属于离线修改）

```c++
//a为原数组，b为差分数组
//一维
for(int i=1; i<=n; i++) b[i] = a[i]-a[i-1];	//1构建
void add(int l,int r,int c){	//2修改
	b[l]+=c;
	b[r+1] -= c;
}
for(int i=1; i<=n; i++) a[i] = b[i]+a[i-1];	//3修改后的查询

//二维
void add(int x1,int y1,int x2,int y2,int c){	//2修改
	b[x1][y1]+=c;
	b[x2+1][y1]-=c;
	b[x1][y2+1]-=c;
	b[x2+1][y2+1]+=c;
}
for(int i=1;i<=n;i++)	////1构建
	for(int j=1;j<=m;j++) add(i,j,i,j,a[i][j]);
while(q--) add(x1,y1,x2,y2,c);
for(int i=1;i<=n;i++)	//3修改后的查询
	for(int j=1;j<=m;j++)
		b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
```

## 【双指针】

又名“尺取法”，“2 point”

- 原理：对一段连续的区间有特定的要求，不满足要求时优化遍历的做法，将朴素的O(n^2)优化到接近O(n)
- 优势：快慢指针：先固定一个指针，然后另一个指针去连续的判断一段区间，并且**能返回第一个指针而不是从头开始**
- 快慢指针：
    - 最长连续不重复子序列
    - 能选出k种血统的奶牛并出队，使队列里只有一种血统并求其最长长度（数字的种类<=k+1）

```c++
for(int l=1,r=1; r<=n; r++){
    while(l<r && check(l,r)) l++, ...;
}
//循环后得回到1的位置开始删掉数字？双指针就可以就直接从l的下一位开始删除了

//eg1:
for(int l=1,r=1; r<=n; r++){
	cnt[a[r]]++;
    while(l<r && cnt[a[r]]>1) cnt[a[l++]]-- ;
    res = max(res, r-l+1);
}

//eg2:
for(int l=1,r=1; r<=n; r++){
    if(cnt[p[a[r]]]==0) tot++;	//p是map
    cnt[p[a[r]]]++;
    while(tot==k+2){
        cnt[p[a[l]]]--;
        if(cnt[p[a[l]]]==0) tot--;
        l++;
    }
    ans = max(ans, cnt[p[a[r]]]);

}
```

- 区间合并：

    ```c++
    void solve(){
    	vector<pii> res;
    	int l=a[1].l, r=a[1].l;
    	for(int i=1; i<=n; i++){
    	    if(r < a[i].l){
    	    	res.push_back({l,r});
    	        l=a[i].l; r=a[i].r;
    	    }
    	    else r = max(r, a[i].r);
    	}
    	res.push_back({l,r});
    }	
    ```

## 【位运算】

- tricks：
    - 任何一个数可以分解成二进制

1. 补码：1000···00(共32位)为-inf
    - 正数的补码就是其本身
    - 负数的补码是在其原码的基础上, 符号位不变, 其余各位取反, 最后+1. (即在反码的基础上+1)
2. 移位

$$
1<<n=2^n\\
n<<1=2n\\
n>>1:算术向下取整\\
n\&1:判断其是否为奇数
$$

应用：（二进制分解）快速幂

```c++
//O(logn)
ll qpow(int x, int y){
    ll ans = 1;
    for(; y; y>>=1){
        if(y&1) ans *= x;
        x = x*x;
    }
    return ans;
}

int qpow(int x, int y, int mod){
    int ans = 1;
    for(; y; y>>=1){
        if(y&1) ans = 1ll*ans*x%mod;
        x = 1ll*x*x%mod;
    }
    return ans;
}
```

3. 二进制状态压缩

$$
x的最低位的1对应的值\Rightarrow lowbit(x):x\&-x=x\&(\sim x+1)\\
(n>>k)\&1:从第0位开始的第k位\\
n\&(1<<k)-1:第0位\sim第k-1位\\
$$

4. 进制转换

    ```c++
     while(x){  
    	int c=x%p; x/=p;  
    	m++; s[m]=c;
    }  
    for(int k=m;k>=1;k--)
    ```

##  ？【倍增】

- 思想：整数成倍增长的状态转移

    - ST表：在线处理
    - ST表：在线处理
        - 区间最值

```c++
//eg: request max
int f[N][21];

int query(int l,int r){
    int k = log(r-l+1)/log(2);
    return max(f[l][k], f[r-(1<<k)+1][k]);
}

   	for(int i=1; i<=n; i++) f[i][0]=read();
    for(int j=1; j<=21; j++){
        for(int i=1; i+(1<<j)-1<=n; i++)
            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
    }
```

- RMQ问题：
    - ST表
        - time: O(nlogn) ~ O(1)
        - space: O(nlogn)
    - 线段树
        - time: O(n) ~ O(logn)
        - space: O(n)

# 三、数据结构

## 【栈&队列】

- 栈：先进后出

```c++
int stk[N], tt = 0;// tt表示栈顶

// 向栈顶插入一个数
stk[ ++ tt] = x;

// 从栈顶弹出一个数
tt -- ;

// 栈顶的值
stk[tt];

// 判断栈是否为空
if (tt > 0) {}
```

- 单调栈：O(N)

    - 应用：维护一个持续单调区间

    - 常见模型：找出每个数左边离它最近的比它小/大（注意下面的大于小于号）的数

        （第 i 个元素之后第一个大于 ai 的元素的下标-->变成右边？-->正序读入）

    - 两个tip：

        - 求左边的正序，求右边的倒序
        - 存单调递增，比较并出栈后所的栈顶就是较小>；存单调递减就较大<（递增还是递减？看题意）

```c++
	int top = 0;
	while(n--){	//求左边最靠近自己的数而比自己小的数程序实现 、
        int x=read();
    	while(top && stk[top]>=x) top--;	//此时stk[]单调递增
        if(top) printf("%d ",stk[top]);	//如果存在
        else ...	//如果不存在
    	stk[++top] = x;
    }

    for(int i=n; i>=1; i--){ 	///求右边的最靠近的较大数的下标
		while(top && a[stk[top]]<=a[i]) top--;	//此时a[]单调递减.stk[]存的是下标
    	if(top) pr[i]=stk[top];
    	else pr[i]=0;
		stk[++top] = i; 
    }
```

- 队列：先进先出

```c++
int q[N], hh = 1, tt = 0;// hh 表示队头，tt表示队尾（下标从1开始）

// 向队尾插入一个数
q[ ++ tt] = x;

// 从队头弹出一个数
hh ++ ;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh <= tt) {}
```

- 循环队列

```c++
int q[N], hh = 1, tt = 0;// hh 表示队头，tt表示队尾的后一个位置

// 向队尾插入一个数
q[ ++ tt ] = x;
if (tt == N) tt = 0;

// 从队头弹出一个数
hh ++ ;
if (hh == N) hh = 0;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh != tt) {}
```

- 单调队列：得到**当前的某个范围内**的**最值**
    - 常见模型：找出滑动窗口中的最大值/最小值

```c++
	int hh=1, tt=0;
	q[1]=1;	//q[x]=i即储存x的下标为i
	for(int i=1; i<=n; i++){
    	if(hh<=tt && i-k+1>q[hh]) hh++;
    	while(hh<=tt && a[q[tt]]>=a[i]) tt--;	// >=求最小值; 改成<=即为最大值
		q[++tt]=i;
    	if(i>=k) printf("%d ",a[q[hh]]); //此时a[i]是以下标i开头的滑动窗口的最值
	}
	puts("");
```

## 【链表&邻接表】

- 链表：在任意位置插入或删除，但只能按顺序访问.
- 单链表：链式前向星
    - apply：存储图或者树（由邻接矩阵优化）

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
//n点:head;		m边:to,edge,nxt; 
//head[x]=idx表示结点x的最后一次加边编号为idx
//to[idx]为这条边的终点
//nxt[i]为i的下一个指针编号，故邻接表遍历顺序与插入顺序相反 
int idx, head[N], to[M], edge[M], nxt[M];

void init(){
	memset(head, -1, sizeof head);
	idx = 0;
}

void add(int x, int y, int z){	//添加单向边x->y
    to[++idx]=y;
    edge[idx]=z;
	nxt[idx]=head[x];
    head[x]=idx;
}

void walk(){
	int x = //头结点 
	for(int i=head[x]; i!=-1; i=nxt[i]){
		int y=to[i], z=edge[i];
	}
}
```

- 双链表：优化问题

```c++
int e[N], l[N], r[N], idx;

void init(){
	r[0]=1, l[1]=0;
	idx=2;
}

void insert(int a, int x){
	e[idx]=x;
	l[idx]=a, r[idx]=r[a];
	l[r[a]]=idx, r[a]=idx++;
}

void remove(int a){
	l[r[a]]=l[a];
	r[l[a]]=r[a];
}
```

## 【堆】

- tip：如果没有要求删除操作的话，直接用priority_queue即可
- 应用：
    - 插入一个数
    - 求集合中的min（/max）
    - 删除min
    - 删除任意一个元素
    - 修改任意一个元素
- 本质：完全二叉树
    - 左儿子2x，右儿子2x+1
- 操作逻辑：往下操作

```c++
int cnt=0, heap[N];

void up(int p){
	while(p>1){
		if(heap[p] > heap[p>>1]) swap(heap[p], heap[p/2]), p/=2;
		else break ;
	}
}

void insert(int x){	//插入 
	heap[++cnt] = x;
	up(cnt);
}

int gettop(){	//回到顶部（小根堆） 
	return heap[1];
}

void down(int p){
	#define lson p>>1
	#define rson p>>1|1
	int s = lson;
	while(lson<=cnt){
		if(lson<cnt && heap[lson]<heap[rson]) s++;
		if(heap[lson]>heap[p]) swap(heap[lson], heap[p]), p=lson, s=p*2;
		else break;
	}
}

void retop(){	//删除顶部 
	heap[1] = heap[cnt--];
	down(1);
}

void remove(int k){	 //删除 
	heap[k] = heap[cnt--];
	up(k), down(k);
}
```

- Huffman树：其叶结点权值越小，离根越远，叶结点权值越大，离根越近
    - 优先队列

## 【树状数组】

- 用途：维护序列的前缀和
- 操作：
    - 基本操作
        - 单点加&查询前缀和
        - 区间加&区间查询
    - 抽象出BIT模型来
        - eg：谜一样的牛，维护01序列，需支持 单点修改 和 最小的前缀和查询（二分）

```c++
struct BIT{
	#define lowbit(x) ((x)&(-x))
	ll c[N];
	
	void add(int x,ll num){
		int i=x;
		while(i<=n){c[i]+=num;i+=lowbit(i);}
	}
	
	ll ask(int x){
		int i=x;ll ans=0;
		while(i){ans+=c[i];i-=lowbit(i);}
		return ans;
	}
};
BIT b1,b2;

//单点修改: 
b1.add(i,num)
//得到前缀和，则区间和则为 
b1.ask(r)-b1.ask(l-1)

b1.add(i,a[i]-a[i-1]);b2.add(i,(i-1)*(a[i]-a[i-1]));
//区间修改
b1.add(x,k); b1.add(y+1,-k);
b2.add(x,k*(x-1)); b2.add(y+1,-k*y);
//区间查询
y*b1.ask(y) - (x-1)*b1.ask(x-1) - b2.ask(y) + b2.ask(x-1)
```

## ？【线段树】

- 用途：对序列进行维护，支持查询与修改
    - 区间数值修改（和，乘；最值；）
    - 线段开头或末尾的添加
    - 询问”可划分与合并“的信息（eg：最大子段和；）
    - 染色问题
- 步骤：
    1. 上传的数值修改
    2. 建树
    3. 操作的懒惰标记+下传+函数
- tip：
    - 区间修改才需要懒惰标记，但直接套区间现有模板也行
- 模板：

```c++
//with lazy tag
//  "//" is without lazy_tag
#define lson p<<1
#define rson p<<1|1
struct Node{
	int l, r;
    ll sum, add;	//add is the lazy of operation
}t[N*4];

void push_up(int p){
	t[p].sum = t[lson].sum+t[rson].sum; //
}

void build(int p, int l, int r){
	t[p].add=0; //
	t[p].l=l, t[p].r=r;
    if(l==r){
    	t[p].sum=a[l];
        return;
    }
    int mid = (l+r)/2; 
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(p);
} 

void lazy(int p, int l, int r, int d){
	t[p].sum += 1ll*d*(r-l+1);
	t[p].add += d; //
}

void push_down(int p){ //?
    if(t[p].add==0) return ;
    lazy(lson, t[lson].l, t[lson].r, t[p].add);
    lazy(rson, t[rson].l, t[rson].r, t[p].add);
    t[p].add=0;
}

void add(int p, int l, int r, int d){
	if(l<=t[p].l && r>=t[p].r) return lazy(p, t[p].l, t[p].r, d);
	push_down(p); //
	int mid = t[p].l+t[p].r >>1;
	if(l<=mid) add(lson,l,r,d);
	if(r>mid) add(rson,l,r,d);
	push_up(p);
}

ll ask(int p, int l, int r){
    if(l<=t[p].l && r>=t[p].r) return t[p].sum;
    push_down(p);//
    int mid = t[p].l+t[p].r >>1;
	ll ans=0;
    if(l<=mid) ans += ask(lson,l,r);
    if(r>mid) ans += ask(rson,l,r);
    return ans;
}
```

- eg：

```c++
int n, m, mod;
int a[N];
#define lson p<<1
#define rson p<<1|1
struct Node{
	int l, r;
    ll sum, add, mul;
}t[N*4];

//多次延迟标记
void push_up(int p){
	t[p].sum = (t[lson].sum+t[rson].sum)%mod;
}

void build(int p, int l, int r){
 	t[p].add=0, t[p].mul=1;
	t[p].l=l, t[p].r=r;
    if(l==r){
    	t[p].sum = a[l]%mod;
        return;
    }
    int mid = l+r >>1; 
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(p);
}

void lazy_add(int p, int l, int r, int d) {
	t[p].add += d;
	t[p].sum = (t[p].sum + d*(r-l+1))%mod;
}
void lazy_mul(int p, int d){
	t[p].add = (t[p].add*d)%mod;
	t[p].mul = (t[p].mul*d)%mod;
	t[p].sum = (t[p].sum*d)%mod;
}

void push_down(int p){
    if(t[p].add==0 && t[p].mul==1) return ;
    t[lson].sum = (t[lson].sum*t[p].mul + t[p].add*(t[lson].r-t[lson].l+1))%mod;
    t[rson].sum = (t[rson].sum*t[p].mul + t[p].add*(t[rson].r-t[rson].l+1))%mod;
    t[lson].mul = (t[lson].mul*t[p].mul)%mod;
    t[rson].mul = (t[rson].mul*t[p].mul)%mod;
    t[lson].add = (t[lson].add*t[p].mul+t[p].add)%mod;
    t[rson].add = (t[rson].add*t[p].mul+t[p].add)%mod;
    t[p].add=0 ,t[p].mul=1;
}

void add(int p, int l, int r, int d){
	if(l<=t[p].l && r>=t[p].r) return lazy_add(p, t[p].l, t[p].r, d);
	push_down(p);
	int mid = t[p].l+t[p].r >>1;
	if(l<=mid) add(lson,l,r,d);
	if(r>mid) add(rson,l,r,d);
	push_up(p);
}

void mul(int p, int l, int r, int d){
	if (l<=t[p].l && r>=t[p].r) return lazy_mul(p, d);
	push_down(p);
	int mid = t[p].l + t[p].r >> 1;
	if(l<=mid) mul(lson, l, r, d);
	if(r>mid) mul(rson, l, r, d);
	push_up(p);
}

ll ask(int p, int l, int r){
    if(l<=t[p].l && r>=t[p].r) return t[p].sum;
    push_down(p);
    int mid = t[p].l+t[p].r >>1;
	ll ans=0;
    if(l<=mid) ans = (ans+ask(lson,l,r))%mod;
    if(r>mid) ans = (ans+ask(rson,l,r))%mod;
    return ans;
}

//维护复杂信息（eg最大连续子段和）
void push_up(int p){
	t[p].sum = t[lson].sum+t[rson].sum;
	t[p].lmax = max(t[lson].lmax, t[lson].sum+t[rson].lmax);
	t[p].rmax = max(t[rson].rmax, t[rson].sum+t[lson].rmax);
	t[p].tmax = max(max(t[lson].tmax, t[rson].tmax), t[lson].rmax+t[rson].lmax);
}
void lazy(int p, int d){
	t[p].sum = t[p].lmax = t[p].rmax = t[p].tmax = d;
}

void build(int p, int l, int r){
	t[p].l=l, t[p].r=r;
    if(l==r){
        return lazy(p,a[l]);
    }
    int mid = (l+r)/2; 
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(p);
} 

void change(int p, int l, int r, int d){
	if(l<=t[p].l && r>=t[p].r) return lazy(p,d);
	int mid = t[p].l+t[p].r >>1;
	if(l<=mid) change(lson,l,r,d);
	if(r>mid) change(rson,l,r,d);
	push_up(p);
}

Node ask(int p, int l, int r){
    if(l<=t[p].l && r>=t[p].r) return t[p];
    int mid = t[p].l+t[p].r >>1;
	Node ans,f1,f2;
    if(r<=mid) ans = ask(lson,l,r);
    if(l>mid) ans = ask(rson,l,r);
    if(l<=mid && r>mid){
    	f1 = ask(lson,l,r);
        f2 = ask(rson,l,r);
        ans.sum = f1.sum+f2.sum;
        ans.lmax = max(f1.lmax, f1.sum+f2.lmax);
		ans.rmax = max(f2.rmax, f2.sum+f1.rmax);
		ans.tmax = max(max(f1.tmax, f2.tmax), f1.rmax+f2.lmax);
	}
    return ans;
}

//区间覆盖问题
struct point {
    int l,r;
    int mark,sum;
};
point tree[10001*4*4],num[10001*4];
int ans,res[10001*4],visit[10001*4];

void build(int i,int left,int right){
    tree[i].l=left,tree[i].r=right;
    tree[i].mark=tree[i].sum=0;
    if (left==right) return ;
    int mid=(left+right)/2;
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
}

void update(int i,int left,int right,int val){
    if (left<=tree[i].l&&tree[i].r<=right){tree[i].mark=tree[i].sum=val;return ;}
    if (tree[i].mark){
        tree[i*2].mark=tree[i*2+1].mark=tree[i].mark;
        tree[i*2].sum=tree[i*2+1].sum=tree[i].mark;
        tree[i].mark=0;
    }
    int mid=(tree[i].r+tree[i].l)/2;
    if (left>mid) update(i*2+1,left,right,val);
    else if (right<=mid) update(i*2,left,right,val);
    else{
        update(i*2,left,mid,val);
        update(i*2+1,mid+1,right,val);
    }
}

int find(int i){
    if (tree[i].l==tree[i].r){
        if (!visit[tree[i].sum]){
           visit[tree[i].sum]=1;
           ++ans;
        }
        return ans;
    }
    if (tree[i].mark){
        tree[i*2].mark=tree[i*2+1].mark=tree[i].mark;
        tree[i*2].sum=tree[i*2+1].sum=tree[i].mark;
        tree[i].mark=0;
    }
    find(i*2);
    find(i*2+1);
}

while (t--){
           	res[0]=0;
            scanf("%d",&n);
            for (i=1;i<=n;i++){
               scanf("%d %d",&num[i].l,&num[i].r);
               if (num[i].l>num[i].r) swap(num[i].l,num[i].r);
               res[++res[0]]=num[i].l;
               res[++res[0]]=num[i].r;
            }
            sort(res+1,res+res[0]+1);//离散化
            tn1=tn=unique(res+1,res+res[0]+1)-res;
            for (i=2;i<tn;i++)//插入数
               if (res[i]-res[i-1]>1)
                  res[tn1++]=res[i]-1;
            res[0]=tn1-1;
            sort(res+1,res+res[0]+1);
            build(1,1,res[0]);//以新的区间建树
            for (i=1;i<=n;i++){
                powl=lower_bound(res+1,res+1+res[0],num[i].l)-res;
                powr=lower_bound(res+1,res+1+res[0],num[i].r)-res;
                update(1,powl,powr,i);
            }
            ans=0;
            memset(visit,0,sizeof(visit));
            visit[0]=1;
            printf("%d\n",find(1));
        }

//eg:扫描线
#define lson d<<1
#define rson d<<1|1
struct Node{
    int l,r,c;
    double cnt,lf,rf;
};
struct Line{
    double x,y1,y2;
    int f;
};

int n,tot=0;
Line e[maxn*4];
Node t[maxn*4];
double y[maxn];

bool cmp(Line a,Line b){
    return a.x<b.x;
}

void Build(int d,int l,int r){
    t[d].l=l;t[d].r=r;
    t[d].cnt=0;t[d].c=0;
    t[d].lf=y[l];t[d].rf=y[r];
    if(l+1==r) return;
    int mid=(l+r)/2;
    Build(lson,l,mid);
    Build(rson,mid,r);
}

void calen(int d){
    if(t[d].c>0){
        t[d].cnt=t[d].rf-t[d].lf;
        return;
    }
    if(t[d].l+1==t[d].r) t[d].cnt=0;
    else t[d].cnt=t[lson].cnt+t[rson].cnt;
}

void update(int d,Line x){
    if(x.y1==t[d].lf && x.y2==t[d].rf){
        t[d].c+=x.f;
        calen(d);
        return;
    }
    if(x.y2<=t[lson].rf) update(lson,x);
    else if(x.y1>=t[rson].lf) update(rson,x);
    else{
        Line temp=x;
        temp.y2=t[lson].rf;
        update(lson,temp);
        temp=x;
        temp.y1=t[rson].lf;
        update(rson,temp);
    }
    calen(d);
}

int s=1;
for(int i=1; i<=n; i++){
	double x1,y1,x2,y2;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    e[s].x=x1;e[s].y1=y1;e[s].y2=y2;
    [s].f=1;y[s]=y1;
	s++;
    e[s].x=x2;e[s].y1=y1;e[s].y2=y2;
    e[s].f=-1;y[s]=y2;
    s++;
}
sort(e+1,e+s,cmp);
sort(y+1,y+s);
Build(1,1,s-1);
update(1,e[1]);
double ans=0;
for(int i=2; i<=s; i++){
	ans+=t[1].cnt*(e[i].x-e[i-1].x);
    update(1,e[i]);
}
```

## ？【平衡树】

#### treap

- 功能：支持查询排名，插入、删除

#### splay



## ？【分块】



# 四、字符串

## 【哈希表】

- 字符串哈希

$$
H(S)=\sum^{len}_{i=1}s_i*P^i\\H(S+c)=H(S)*P+c\\H(T)=H(S+T)-H(S)*P^{len(T)}
$$

```c++
char s[N];
ull h[N], p[N];
const ull P=131;

ull hashs(char s[]){	//single hash
    int len = strlen(s);
    ull ans = 0;
    for (int i=0; i<len; i++)
        ans = ans*P+(ull)s[i];
    return ans&0x7fffffff;
}

ull ask(int l, int r){	//查询一段区间的哈希值
	return h[l]-h[l-1]*p[r-l+1];
}
p[0]=1;
for(int i=1; i<=n; i++){
    	p[i] = p[i-1]*P;            
    	h1[i] = h1[i-1]*P + s[i];
	}
```

- 存储结构：哈希表

    - 原理：通过哈希函数映射后范围变小（可以把哈希表理解为一种高级的数组，这种数组的下标可以是很大的整数，浮点数，字符串甚至结构体）进行 **插入、删除、查询**操作
    - 拉链法：更适合于造表前无法确定表长的情况
    - 开放地址法：找单元，若发生冲突则顺序查看下一单元

- time：

    - 拉链法：若索引的范围是 [1,M] ，哈希表的大小为 N ，那么一次插入/查询期望时间复杂度为O(N/M)

- apply：

    - in a word, 主要用于查找**一串数据**是否已经存在

        - 哈希函数映射后存到一个数组，然后排序，离线处理是否存在相同
        - 哈希映射后，构建链式前向星进行储存，再进行插入或者查找（将一串数映射成一个特征 进行操作）

    - 判断是否是回文串：

        - ```cpp
            void hashs(){
            	p[0]=1;
            	for(int i=1; i<=n; i++){
                	p[i] = p[i-1]*P;            
                	h1[i] = h1[i-1]*P + s[i];
            		h2[i] = h2[i-1]*P + s[n-i+1]; 
            	}
            }
            ull ask1(int l, int r){
            	return h1[r]-h1[l-1]*p[r-l+1];
            }
            ull ask2(int l, int r){
            	return h2[r]-h2[l-1]*p[r-l+1];
            }
            bool pd(int l, int r){
                if(ask1(l,r)==ask2(n-r+1,n-l+1)) return true;
                else return false;
            }
            ```

```c++
char s[N];
const ull base=233;
const ull P=300007;

struct hash_table{	
	int idx, head[P], nxt[N];
	ull e[N];	//seems that struct can't exist ull;
	
	void init(){
		idx=0;
		memset(head, -1, sizeof head);
	}
    
	ull hashs(char *s){
    	int len = strlen(s);
    	ull ans = 0;
    	for (int i=0; i<len; i++)
        	ans = ans*base+(ull)s[i];
    	return ans&0x7fffffff;
	}
	
	void insert(ull val){
    	int k = val%P;
    	e[++idx] = val; //存一个数
    	nxt[idx] = head[k];
    	head[k] = idx;
	}
    
	bool find(ull val){
    	int k = val%P;
    	for(int i=head[k]; i!=-1; i=nxt[i])
        	if(e[i] == val) return true;
    	return false;
	}
}h;


//开放地址法
int find(int x) {
    int t =  (x%P+P)%P;
    while(h[t]!=inf && h[t]!=x){
        t++;
        if(t==mod) t=0;
    }
    return t;
}

void insert(int x){
    int x=read(), k=find(x);
    h[k]=x;
}

void find(int k){
    if(h[k]!=null) ...//存在
}
```

## 【KMP】

- 时间复杂度：O(N+M)

（学习：https://www.cnblogs.com/zzuuoo666/p/9028287.html#3.2%20%E6%AD%A5%E9%AA%A4）

- 思想：每次失配之后不会从头开始枚举，而是通过处理nxt[]来取决右挪的位置

    - nxt[j]=d：以j结尾的模式串的 后缀与前缀的最长公共长度d
    - j+1位置失配时，右移nxt[j]即d位

- 应用：
    - 在文本串中查找模式串 是否存在和出现位置
    
    - 若 i % (i-nxt[i]) ==0，则 L=i-nxt[i] 为最小循环元
    
        若不能整除，则需补充 L-i%L（i-2*nxt[i]）个构成循环

```c++
	//match itself
	nxt[1]=0;
	for(int i=2, j=0; i<=lb; i++){
    	while(j && b[i]!=b[j+1]) j=nxt[j];
    	if(b[i]==b[j+1]) j++;
    	nxt[i]=j;
	}
	
	for (int i=1,j=0; i<=la; i++){
    	while(j && a[i]!=b[j+1]) j=nxt[j];
    	if(a[i]==b[j+1]) j++ ;
    	if(j==lb) j=nxt[j], printf("%d\n",i-lb+1);	//while matching
	}
	for(int i=1; i<=lb; i++) printf("%d ",nxt[i]); 

//scanf("%s",s+1);
//match(s);
```

## 【最小表示法】

- 最小表示法：循环同构串的最小字典序表示
    - 两倍长度进行枚举，固定i=1和j=2不断k++直至不一样，而用过的k不会成为解

```c++
// S[1 ~ n] is given, B[i] = S[i ~ i+n-1]
int get_mini(int *s){
	int n = strlen(s);
    for(int i=1; i<=n; i++) s[i+n]=s[i];
    int i=1, j=2, k;
    while(i<=n && j<=n){
        for(k=0; k<=n && s[i+k]==s[j+k]; k++);
        if(k==n) break;
        if(s[i+k]>s[j+k]){
            i = i+k+1;
            if(i==j) i++;
        }
        if(s[j+k]>s[i+k]){
			j = j+k+1;
            if(i==j) j++;
        }
    }
    int ans = min(i,j);	//B[ans] is the min answer
    return ans;
}
```

## ?【Trie树】

- 特点：存储、查找 字符串
    - 记录字符串出现的次数
- tip：
    - N要开大一点
    - 可以用map记录

```c++
int son[N][26], cnt[N], idx;
char str[N];
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入字符串
void insert(char *str){
    int p = 0;
    for(int i=0; str[i]; i++){
        int u = str[i]-'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

// 查询字符串出现的次数
int query(char *str){	//cnt[]为 该字符串在trie树出现的次数
    int p=0;
    for(int i=0; str[i]; i++){
        int u = str[i]-'a';
        if(!son[p][u]) return 0; //return false;
        p = son[p][u];
    }
    return cnt[p];	//return true；
}
```

## ？【AC自动机】



## ？【Manacher】

- 时间复杂度：O(N)

- apply：
    - 最长的回文长度
    - 总的回文子串的数目

```c++
char data[N<<1];
int p[N<<1], cnt, ans;

void cread(){
    char c=getchar();
    data[0]='~',data[cnt=1]='|';
    while(c<'a'||c>'z') c=getchar();
    while(c>='a'&&c<='z') data[++cnt]=c,data[++cnt]='|',c=getchar();
}

void man(){
	for(int t=1,r=0,mid=0; t<=cnt; t++){
		if(t<=r) p[t] = min(p[(mid<<1)-t], r-t+1);
	    while(data[t-p[t]]==data[t+p[t]]) p[t]++;
	    ans += p[t]/2; //cnt
	    if(p[t]+t>r) r=p[t]+t-1, mid=t;
		//if(p[t]>ans) ans=p[t]; //max length
    }
}

int main(){
	cread();
	man();
	printf("%d\n",ans); //length need ans-1
	
	return 0;
}
```

## ？【回文自动机】



## ？【后缀数组】

## ？【后缀自动机】



# 五、图论

## 【并查集】

- 基本原理：每个集合用一颗树来表示。树根的编号就是整个集合的编号
- 操作：
    - 模板：合并&查询是否在同一个集合
        - （即维护一个连通性问题，eg背包问题的物体是一份连通量；）
    - 求连通块个数：if(fa[i]==i) ans++;
    - 二维变成一维进行操作：(x * n + y) 
    - 离散化后再维护连通性
    - 边带权的并查集

```c++
//(1)朴素并查集：
int getf(int x){
	if(x==fa[x]) return x;
	return fa[x]=getf(fa[x]);
}

void merge(int x,int y){
	fa[getf(x)]=getf(y);
}

void find(int x,int y){
	if(getf(x)==getf(y)) printf("Y\n");
	else printf("N\n");
}

for(int i=1; i<=n; i++) fa[i]=i;

//(2)维护size的并查集：
int d[N], size[N];
//d[]存储每个点到祖宗节点的距离
//size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量
int get(int x){
	if(x==fa[x]) return x;
	int root=get(fa[x]);
	d[x] += d[fa[x]];
	return fa[x]=root;
}

void merge(int x,int y){
	x=get(x); y=get(y);
	fa[x]=y; d[x]=size[y];
	size[y] += size[x];
}
	
//find函数相同，距离为abs(d[a]-d[b])-1
```

## 【树与图的遍历】

- DFS：

```c++
//DFS
void dfs(int x){
    v[x]=1;
    for(int i=head[x]; i!=-1; i=nxt[i]){
        int y=to[i];
        if(v[y]) continue;
        dfs(y);
    }
}

//DFS序
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

//树的深度（设根节点深度为0） 
void dfs(int x){
    v[x]=1;
    for(int i=head[x]; i!=-1; i=nxt[i]){
        int y=to[i];
        if(v[y]) continue;
        dfs(y);
    }
}

//树的重心：一个节点x删除后不相连的每个部分
//其最大的部分的最小值节点即为整棵树的重心 
void dfs(int x){
	v[x]=1; size[x]=1;
	int maxpart=0;
	for(int i=head[x]; i; i=nxt[i]){
        int y=to[i];
        if(v[y]) continue;
        dfs(y);
        size[x]+=size[y];
        maxpart = max(maxpart, size[y]);
    }
    maxpart = max(maxpart, n-size[x]);
    if(maxpart<ans) ans=maxpart, pos=x;
}
```

- BFS：

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

//拓扑排序:不断选择入读为0的节点x，再把x连向的点的入度-1 
void add(int x, int y){
	ver[++idx]=y, nxt[idx]=head[x],head[x]=idx;
	deg[y]++;
} 
void topsort(){
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(deg[i]==0) q.push(i); 
	while(q.size()){
		int x=q.front(); q.pop();
		a[++cnt]=x;	//a[]为拓排的存储数组 
		for(int i=head[x]; i!=-1; i=nxt[i]){
			int y=ver[x];
			if(--deg[y]==0) q.push(y);
		}
	}
}
```

## 【单源最短路径】

#### Dijkstra：

贪心选择全局最小值进行标记和拓展

1. 初始化dist[i] 值（表示起点到节点i 的最短路径长度），除起点外其它值为正无穷大
2. 找一个未被标记 且dist[x]最小的节点x，并标记x
3. 扫描x的出边，求最短dist
4. 重复2、3直到所有点被标记

- apply：

    - 边权均非负的单源最短路问题：

        - 双向图的数组范围记得两倍

        - 具体化 为模板

        - 边权计算为乘法：初始dist[st]=1; q.push({1,st}); add(x,y,1.0-z/100);

        - 求log(w1∗w2∗..)=log(w1)+log(w2)+..最大，且w都小于1：求取反后的最小值  

            dist[y] > dist[x]+z；q.push({dist[y], y});

        - 像“昂贵的聘礼 ”，有限制条件的加边，在if(dist[y] > dist[x]+z) 时加上限制条件

    - 综合应用：

        - 

```c++
//O(n^2) 用于稠密图
int dijkstra(int st){
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
void dijkstra(int st){
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

#### SPFA：

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
void spfa(int st){
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

#### ？floyd：

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
void floyd(){
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

## ？【负环与差分约束】

- 负环：

    ```c++
    void spfa(int s){
        if(flag) return; vis[s]=1; 
        for(int i=head[s];i;i=e[i].ne){
            if(flag) return; 
            int to=e[i].to;
            if(d[to]>d[s]+e[i].va){
                d[to]=d[s]+e[i].va;
                if(vis[to]){flag=1;return;}
                else spfa(to);
            }
        }
        vis[s]=0;
    }
    ```

    

## ？【最小生成树】

- 定义：一张边带权的无向图中，生成树的边的权值之和最小
- 思路：
    - 定理：任意一颗最小生成树一定包含无向图中权值最小的边
    - kruskla：
        	1. 建立并查集，每个点自成一个集合
         	2. 边按权值排序
         	3. 若x和y联通则忽略该边，否则合并集合，加边
     - prim：
        	1. 确定1号节点属于MST
         	2. 最小生成树节点集合为T，剩余节点集合为S，加两个集合各自的点的边，并改变集合

```c++
//kruskal:O(mlogm)
struct Edge{
    int x,y,l;
};

int n,m,fa[N],cnt=0;
ll ans=0;
Edge a[N];

int getf(int p){
    if(fa[p]==p) return p;
    return fa[p]=getf(fa[p]);
}

bool cmp(Edge p,Edge q){
    return p.l<q.l;
}

for(int i=1; i<=m i++) a[i].x=read(),a[i].y=read(),a[i].l=read();
sort(a+1,a+1+m,cmp);
for(int i=1; i<=n; i++) fa[i]=i;
for(int i=1; i<=m i++){
    int x=getf(a[i].x), y=getf(a[i].y);
    if(x==y) continue;
    fa[x]=y;
    ans += a[i].l;
    cnt++;
    if(cnt==n-1) break;
}
if(cnt!=n-1) puts("orz");
else printf("%d\n",ans);


//prim:O(n^2)
void Prim(){
	memset(v,0,sizeof(v));
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	for(int i=1; i<n; i++){
		int x=0;
		for(int j=1; j<=n; j=+)
			if(!v[j] && (x==0||d[j]<d[x])) x=j;
		v[x]=1;
		for(int y=1; y<=n; y++)
			if(!v[y]) d[y]=min(d[y],a[x][y]);
	}
}

for(int i=2; i<=n; i++) ans+=d[i];
```



# 六、搜索

## 【递归】

- 递归：一个规模为n的问题，递归首先通过**回溯**将问题回溯到n-1，……，1；然后再通过**递推**从1的结果一直到n-1，n.

- 步骤：
    1. 建立递归树（先想好状态变量）
    2. 找结束条件/递归边界√
    3. 找选择列表
    4. 是否能剪枝
    5. 做出选择进行递推√
    6. 撤销选择进行递推√

## 【dfs】

- simple apply：相当于多层循环来枚举集合内是否选择

- 记忆化搜索：用递归的形式解决DP问题（eg个数）

    ```c++
    //1.选它
    bool dfs(int n, int k){
        ......
        for(int i = sqrt(n); i; i--){if(dfs(n-i*i, k - 1)) return true;}
        return false;
    }   
    
    //2.直接选择和不选
    vis[t] = true; dfs(t + 1); vis[t] = false; dfs(t + 1);
    
    //3.求个数时 直接用循环减少一次递归
    dfs(ll n, int step){}
    for(int i=step; i<=n; i++){res = min(res, 1+dfs(n-fac[i],i+1));}
    ```

- 剪枝：

    - 可行性（提前限制条件）
    - 最优性（提前预估是否能达到最优解）
    - 优化搜索顺序

- eg：

    - 指数型 组合型 排列型 枚举

    - 子集和，N皇后；（游戏问题）
    - 小猫爬山；（双变量）

# 七、动态规划

- 核心思考：
    - 状态表示
        - 集合
        - 属性：max/min/count
    - 状态计算
        - 划分依据：最后一步+限制条件
        - 初始状态 & 状态转移方程
- 步骤：
    - 我是谁？  ——设计状态，表示局面
    - 我从哪里来？（pull型转移）
    - 我要到哪里去？（push型）  ——设计转移
- 特点：
    - 无后效性
    - 最优子结构

## 【背包DP】

1. 01backpack:

01背包的决策？

​		- 不选，然后去考虑下一个

​		- 选，背包容量减掉那个重量，总值加上那个价值。
$$
F[i][j]=max\left\{\begin{aligned}f[i-1][j]\ ,chose\ no.i\\f[i-1][j-V_i]+W_i\end{aligned}\right.
$$

```c++
//space:O(NM)
memset(dp, 0xcf, sizeof(dp));
dp[0][0]=0;
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++)
        	dp[i][j] = dp[i-1][j];
   	for(int j=v[i]; j<=m; j++)
        	dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+w[i]);
}

//space:O(M)
memset(dp, 0xcf, sizeof(dp));
dp[0]=0;
for(int i=1; i<=n; i++)
    	for(int j=m; j>=v[i]; j--)
            	dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
for(int j=0; j<=m; j++)
    	ans = max(ans, dp[j]);
```

- 若求恰好装满容积为m的背包，则f[m]为解



2. complete backpack:

$$
f[i][j]=max
\left\{
\begin{aligned}
f[i-1][j]\\
f[i][j-v_i]+w_i\ ,chose\ no.i
\end{aligned}
\right.
$$

```c++
memset(dp, 0xcf, sizeof(dp));
dp[0]=0;
for(int i=1; i<=n; i++)
    for(int j=v[i]; j<=m; j++)
        dp[j]=max(dp[j], dp[j-v[i]]+w[i]);
for(int j=0; j<=m; j++)
    ans = max(ans, f[j]);
```



3. multipack:
    - 直接拆分成01背包
    - 二进制拆分法
    - 单调队列优化

```c++
//二进制O(nmlogC)
for(int i=1; i<=n; i++){
	for(int j=1; j<=s; s-=j,j*=2){
		for(int k=m; k>=j*v; k--)
			if(dp[k] < dp[k-j*v]+j*w) dp[k] = dp[k-j*v]+j*w;
	}
	if(s) for(int k=m; k>=s*v; k--)
		if(dp[k] < dp[k-s*v]+s*w) dp[k] = dp[k-s*v]+s*w;
}

//单调队列O(nm)
for(int i=1; i<=n;i++){
    memcpy(q, dp,sizeof(dp));
    for(int j=1; j<=c; j++){
        int hh=0, tt=-1;
        for
    }
}
```



4. hybrid backpack



5. 2D backpack

```c++
for(int i=1; i<=n; i++){
    for(int j=v; j>=a; j--)
        for(int k=m; k>=b;k--)
            dp[j][k] = max(dp[j][k], dp[j-a][k- b]+c);          
}
```



6. 分组背包

$$
F[i][j]=max
\left\{
\begin{aligned}
f[i-1][j]\ ,don't\ chose\ no.i\\
max_{1<=k<=C_i}f[i-1][j-V_i]+W_i
\end{aligned}
\right.
$$

```c++
memset(dp, 0xcf, sizeof(dp));
dp[0]=0;
for(int i=1; i<=n; i++)
    for(int j=m; j>=0; j--)
        for(int k=1; k<=c[i]; k++)
            if(j>=v[i][k]) dp[j] = max(dp[j], dp[j-v[i][k]]+w[i][k]);
```



7. 求方案总数

$$
dp[i][v]=\sum{dp[i-1][v-c[i]]+w[i]}\\dp[0]=1;//dp[0][0]=1;\\dp[j]+=dp[j-v[i]]
$$



8. 输出方案

```c++
i=N
v=V
while(i>0)
    if(g[i][v]==0)
        print "未选第i项物品"
    else if(g[i][v]==1)
        print "选了第i项物品"
        v=v-c[i]
```



9. 有依赖的背包问题：

```c++
//eg in NOIP金明的预算方案
	for(int i=1; i<=n; i++){
		int v=read(),p=read(),q=read();
		if(q==0) maiv[i]=v, maip[i]=p*v;
		else{
			addv[q][0]++;
			addv[q][addv[q][0]] = v;
			addp[q][addv[q][0]] = v*p;
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=m; j>=maiv[i]; j--){
			dp[j] = max(dp[j], dp[j-maiv[i]]+maip[i]);
			if(j >= addv[i][1]+maiv[i])
				dp[j] = max(dp[j], dp[j-addv[i][1]-maiv[i]]+maip[i]+addp[i][1]);
			if(j >= addv[i][2]+maiv[i])
				dp[j] = max(dp[j], dp[j-addv[i][2]-maiv[i]]+maip[i]+addp[i][2]);
			if(j >= addv[i][1]+addv[i][2]+maiv[i])
				dp[j] = max(dp[j], dp[j-addv[i][1]-addv[i][2]-maiv[i]]+maip[i]+addp[i][1]+addp[i][2]);
		}
	}
```

## 【线性DP】

- 思考流程：

    -  画状态图+核心集合思考
    -  空间不够要滚动数组

- eg：

    - 最长上升子序列LIS:	
        $$
        f[0]=0\\
        f[i]=max_{0<=j<i,A[j]<A[i]}f[j]+1\\
        print:max_{1<=i<=n}f[i]
        $$

        ```c++
        	for(int i=0; i<=cnt; i++) dp[i]=0;
        	dp[1]=a[1];
        	int ans=1;
        	for(int i=2; i<=cnt; i++){
        		if(a[i] > dp[ans]) dp[++ans]=a[i];
        		else{
        			int l = lower_bound(dp+1, dp+1+ans, a[i])-dp;
        			dp[l] = a[i];
        		}
        	}
        ```

    - 最长公共序列LCS：

    $$
    F[i][j]=max\left\{\begin{aligned}f[i-1][j]\\f[i][j-1]\\f[i-1][j-1]+1,if\ A[i]=B[i]\end{aligned}\right.
    $$

    ```c++
    //将a[]变成重新标号成单调递增，则b[]单调递增即为a[]的子序列	
    	for(int i=1;i<=n;i++){scanf("%d",&a[i]);mp[a[i]]=i;}
	for(int i=1;i<=n;i++){scanf("%d",&b[i]);f[i]=0x7fffffff;}
    	f[0]=0;
	int len=0;
    	for(int i=1;i<=n;i++){
    		if(map[b[i]]>f[len]) f[++len]=mp[b[i]];
    		else{
    			int l = upper_bound(f+1, f+1+len, mp[b[i]])-f;
    		    f[l] = min(mp[b[i]], f[l]);
         	}
        }
    ```
    
    - 数字三角形：
    
    $$
    f[1][1]=A[1][1]\\
    F[i][j]=A[i][j]+max
    \left\{
    \begin{aligned}
    f[i-1][j]\\
    f[i-1][j-1],if\ j>1
    \end{aligned}
    \right.\\
    print:max_{1<=j<=n}f[n][j]
    $$
    

## ？【状态压缩DP】

- 集合有n个元素，每个元素有k种状态，则将集合的状态表示成一个N位K制数，然后用十进制表示

- 流程：

    - pre
    - dp

- 位预算eg：

    ```c++
    //判断 同一行是否相邻
    bool check(int state) {
        return !(state & state >> 1);
    }
    //判断 上下相邻 且 纵坐标也相邻
    if (!(a & b) && check(a | b)) pre[a].push_back(b);
        
    //一行中有多少合法
    int count(int state) {
        int res = 0;
        for (int i = 0; i < n; ++ i) res += state >> i & 1;
        return res;
    }
    ```

## 【区间DP】

- 特征：问题分解成两两合并的形式（对小区间求解，再利用小区间的最优解合并求得大区间的最优解）

$$
令状态dp[i] [j]表示将下标位置i 到j 的所有元素合并能获得的价值的最大值，那么\\
dp[i][j]=max\{f[i][k]+f[k+1][j]+cost\}
$$

- eg：

    - 石子合并(用l和len表示dp[] []左右区间的端点，k枚举状态转移) & 凸多边形的区分
- 矩阵取数(每次DP仅针对第T行，dp[i] [j] 表示剩余区间i到j，取值为dp[i] [i] + cost )

    ```c++
	for(int len=2; len<=n; len++){
		for(int l=1; l+len-1<=n+n; l++){
			int r = l+len-1;
			for(int k=l; k<r; k++){
				fmin[l][r] = min(fmin[l][r],fmin[l][k]+fmin[k+1][r]+sum[r]-sum[l-1]);
				fmax[l][r] = max(fmax[l][r],fmax[l][k]+fmax[k+1][r]+sum[r]-sum[l-1]);
			}
		}
	}
	int maxx=-inf, minn=inf;
	for(int i=1; i<=n; i++){
		maxx = max(maxx, fmax[i][i+n-1]);
		minn = min(minn, fmin[i][i+n-1]);
	}
    ```

## ?【树形DP】

- 基础：树形后序遍历+DP转移方程

- eg：

    - 子树大小&树的重心（入门：遍历完子树之后将值传给父亲 的过程）

        ```c++
        void dfs(u){
        	if (u 是叶子) f[u] = 1 return
            for (v 是 u 的儿子){
                dfs(v)
                f[u] += f[v]
            }
            f[u] += 1 // 本身
        }
        ```

    - 树的最大独立集：

        ```c++
        //链式前向星加边
        void dfs(int x) {	//eg：没有上司的舞会
            f[x][0] = 0;
        	f[x][1] = a[x];
        	vis[x]=1;
        	for(int i=head[x]; i!=-1; i=nxt[i]){
        		int y=to[i];
        		if(vis[y]) continue;
        		dfs(y);
        		f[x][0] += max(f[y][0], f[y][1]);	//转移方程
        		f[x][1] += f[y][0];
        	}
        }
        ```

    - 树的直径：

    ```c++
    //状态转移时有三种状况
    void dfs(int x){
    	v[x]=1;
        f1[x] = f2[x] = 0;
        for(int i=head[x]; i!=-1; i=nxt[i]){
            int y=to[i];
            if(v[y]) continue;
            dfs(y);
            if(f1[y]+edge[i] >= f1[x]) f2[x]=f1[x], f1[x] = f1[y]+edge[i]; //最长路转移
            else if(f1[y]+edge[i] > f2[x]) f2[x] = f1[y]+edge[i];          //次长路转移
        }
        res = max(res, f1[x]+f2[x]);
    }
    dfs(1);//调用入口
    ```

    - 换根DP 一般分为三个步骤：
        	1. 指定任意一个根节点
         	2. 一次dfs遍历，统计出当前子树内的节点对当前节点的贡献
         	3. 一次dfs遍历，统计出当前节点的父节点对当前节点的贡献，然后合并统计答案

    ```c++
    //eg:树的中心
    void dfs1(int x){
    	v1[x]=1;
    	for(int i=head[x]; i!=-1; i=nxt[i]){
    		int y = to[i];
    		if(v1[y]) continue;
    		dfs1(y);
            if(f1[y]+edge[i] >= f1[x]){
                f2[x]=f1[x], s2[x]=s1[x];
                f1[x]=f1[y]+edge[i], s1[x]=y;
            }             
            else if(f1[y]+edge[i] > f2[x]) 
            	f2[x] = f1[y]+edge[i], s2[x]=y;
        }
    }
    
    void dfs2(int x){
    	v2[x]=1;
        for(int i=head[x]; i!=-1; i=nxt[i]){
            int y = to[i];
            if(v2[y]) continue;
            if(s1[x] == y) up[y] = edge[i]+max(up[x],f2[x]);
            else up[y] = edge[i]+max(up[x], f1[x]);
     		dfs2(y);
        }
    }
    ```

## ？【数位DP】

- 给定一个闭区间 [l,r]，求区间中满足某种条件的数的总数

# 八、数学相关



# 九、计算几何