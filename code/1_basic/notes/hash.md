##  离散化/哈希

- 定义&应用：映射成正整数，只关心**大小关系**，用排名代替原数据。若

- 重点：
    - 原映射组a[]中可能重复：去重
    - 如何查询离散化后的值：二分找下标
- 模板参考：

```c++
// 模板一:vector
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
int find(int x)	// 查询a[i]映射的排名
{
    return lower_bound(a.begin(), a.end(), b[i]) - a.begin();
}
// lower——bound本质是用二分去查找x的下标


// 模板二:数组
void hashs(){
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
		if(i==1 || a[i]!=a[i-1]) b[++tot]=a[i];
}
int find(int x)
{	 
    return lower_bound(b+1, b+tot+1, x) - b;
}


// 模板三:map<int, int> v;
// STL中map记录的值 是原数值独一的标识
sort(a+1, a+1+n);
int cnt=0;
for(int i=1; i<=n; i++)
    if(!v[a[i]]) v[a[i]] = ++cnt;	// hash  此时cnt就相当于find(a[i]),即下标
```
