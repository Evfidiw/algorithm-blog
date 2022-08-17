## ST表

- 原理：基于倍增的思想。推导参考[oiwiki](https://oi-wiki.org/ds/sparse-table/)

- 操作：**在线**处理 **区间最值**，但不支持修改

- 代码参考：

    ```c++
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

## RMQ问题

列出复杂度进行对比

>  默认时间复杂度为：O(数据预处理) ~ O(单词询问)

- ST表
    - time: O(nlogn) ~ O(1)  
    - space: O(nlogn)
- 线段树
    - time: O(n) ~ O(logn)
    - space: O(n)