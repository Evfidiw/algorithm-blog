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
    - 
- 模板参考：

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
