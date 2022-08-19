## Sparse Table

- 原理：基于倍增的思想。推导参考[oiwiki](https://oi-wiki.org/ds/sparse-table/)

    - 设 f\[i][j] 表示 [i, i+2^j-1] 区间的最值，区间长度为2^j = 2 × 2^(j-1)

        得递归公式 f\[i][j] = max(f\[i][j-1], f\[i+2^(j-1)][j-1])

    - 若要查询区间[l, r] 时，2^k <= r-l+1 < 2^(k+1) , (k=log2(r-l+1))，转换成f存储的形式。

- 操作：**在线**处理 **区间最值**，但不支持修改

- 代码参考：

    ```c++
    int f[N][21];
    
    int query(int l,int r)
    {
        int k = log(r-l+1)/log(2);
        return max(f[l][k], f[r-(1<<k)+1][k]);
    }
    
       	for(int i=1; i<=n; i++) f[i][0]=read();
        for(int j=1; j<=21; j++){
            for(int i=1; i+(1<<j)-1<=n; i++)
                f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
        }
    ```

## RMQ问题

列出复杂度进行对比：

>  默认时间复杂度为：O(数据预处理) ~ O(单词询问)

- ST表
    - time: O(nlogn) ~ O(1)  
    - space: O(nlogn)
    
- 线段树
    - time: O(n) ~ O(logn)
    - space: O(n)
    
- eg：

    [区间最值差](http://poj.org/problem?id=3264)

    