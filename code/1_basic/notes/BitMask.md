## 位掩码/位运算

- **核心**：任何一个数可以分解成二进制

- 常识：

    1. 补码：1000···00(共32位)为-inf
        1. 正数的补码就是其本身
        2. 负数的补码是在其原码的基础上, 符号位不变, 其余各位取反, 最后+1. (即在反码的基础上+1)

    2. 移位

        > 1<<n = 2^n
        > n<<1 = 2n
        > n>>1: 算术向下取整
        > n\&1: 判断其是否为奇数

    3. 二进制状态压缩

        > x的最低位的1对应的值：lowbit(x) = x\&(-x) = x&(~x+1)
        >
        > (n>>k)&1: 从第0位开始的第k位
        >
        > n&(1<<k)-1: 第0位~第k-1位

    4. 进制转换

        ```c++
         while(x){  
        	int c=x%p; x/=p;  
        	m++; s[m]=c;
        }  
        for(int k=m;k>=1;k--)
        ```

- 应用：

    1. （二进制分解）快速幂

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

