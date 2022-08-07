- 又名“尺取法”，“2 point”

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

## 