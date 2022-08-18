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

    - 上一个操作是单点修改和区间查询，如果是要求区间修改呢？

        维护序列a的差分数组b，此时我们对a的一个前缀r求和，得

        $\sum{_{i=1}^ra_i}=\sum{_{i=1}^r}\sum{_{j=1}^i}b_j=\sum{_{i=1}^r}b_i\times(r-i+1)=\sum{_{i=1}^r}b_i\times(r+1)-\sum{_{i=1}^r}b_i\times i$

        变成维护两个树状数组bi和bi×i

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

//单点修改: 
b1.add(i,num)
//得到前缀和，则区间和则为 
b1.ask(r)-b1.ask(l-1)

//区间修改
b1.add(x,k); b1.add(y+1,-k);
b2.add(x,k*(x-1)); b2.add(y+1,-k*y);
//区间查询
y*b1.ask(y) - (x-1)*b1.ask(x-1) - b2.ask(y) + b2.ask(x-1)
```
