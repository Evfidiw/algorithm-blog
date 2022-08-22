## 树状数组

- 用途：维护序列的前缀和

- 操作：

    - 基本操作
        - 单点加&查询前缀和
        - 区间加&区间查询
    - 抽象出BIT模型来

- 思想：

    - 运用到了位运算、倍增、前缀和的思想

    - ![img](https://oi-wiki.org/ds/images/fenwick.svg)

    - 以上图的方式管理ci，便可以管理ai。为什么？由lowbit(x)函数（得到x的二进制的第一个1以及他后面的0组成的数），可以保证包含x的前缀和数组（倍增思想）都得到修改。而查询时反向循环（同样是倍增思想）得前缀和。

    - 上一个操作是单点修改和区间查询，如果是要求区间修改呢？通过前文我们发现树状数组的查询其实相当于查询前缀和，那我们联想到利用**差分**的区间修改，树状数组的存储将原数组改为差分数组，实现区间修改的功能。

    - 利用上一个操作差分数组可以区间修改和单点查询，如果既要区间修改又要区间查询呢？在差分的基础上，维护序列a的差分数组c，此时我们对a的一个前缀r求和，得

        
    $$
        \sum{_{i=1}^ra_i}\\
        =\sum{_{i=1}^r}\sum{_{j=1}^i}c_j\\
        =\sum{_{i=1}^r}c_i\times(r-i+1)\\
        =(r+1)\times\sum{_{i=1}^r}c_i-\sum{_{i=1}^r}ic_i
        $$
    
    - 这样变成维护差分数组 cn 和 cn×n：此时区间修改还是利用差分的思路，
    
        假设ci区间修改变成（ci+num），则变成修改 ci+=num，i×ci += i×nun.
    
- 模板参考：

```c++
struct BIT{
	#define lowbit(x) ((x)&(-x))
	ll c[N];
	
	void add(int x,ll num){
        for(int i=x; i<=n; i+=lowbit(i)) c[i]+=num;
	}
	
	ll ask(int x){
		ll ans=0;
        for(int i=x; i; i-=lowbit(i)) ans+=c[i];
		return ans;
	}
};
BIT b1,b2;

// model_1
//单点修改:
b1.add(x,num)
//得到前缀和，则区间和则为 
b1.ask(r)-b1.ask(l-1)

// model_2
for(int i=1; i<=n; i++)
	a[i]=read(), add(i, a[i]-a[i-1]);
//区间修改
add(l, num); add(r+1, -num);
//单点查询
ask(x);

// model_3
for(int i=1; i<=n; i++){
	a[i]=read();
    b1.add(i, a[i]-a[i-1]);	//维护ci
    b2.add(i, (i-1)*(a[i]-a[i-1]));	//维护i×ci
}
//区间修改
b1.add(l, num); b1.add(r+1,-num);
b2.add(l, num*(l-1)); b2.add(r+1,-num*r);
//区间查询
r*b1.ask(r) - (l-1)*b1.ask(l-1) - b2.ask(r) + b2.ask(l-1)
```
