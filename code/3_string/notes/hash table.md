## 【字符串哈希】

- 字符串哈希：

    hash的思想就是“映射到值域较小的范围”。对此，也可以定义一个函数f，将一串字符串映射到整数。

    而此时要注意的是：

    - 在 Hash 函数值不一样的时候，两个字符串一定不一样；
    - 在 Hash 函数值一样的时候，两个字符串**不一定**一样

    后者这种情况称为哈希碰撞

    所以哈希的方法应该追求“时间复杂度”和“准确”（因为有可能会出现哈希碰撞），通常我们使用多项式哈希，如下：

$H(S)=\sum{^l_{i=1}s[i]\times base\ (mod\ M)}$

$H(T)=H(S+T)-H(S)\times base^{len(T)}\ (mod\ M)$

​		而此时若发生哈希碰撞，即H(S+T)=H(S)。若M选择素数，则概率只有 (l-1)/M，概率很低。

- 改进：虽然概率很低，但并不能够完全忽略。以下办法都能够降低错误率。
    - 自然溢出：当存储的数据大于unsigned long long的存储范围时，会自动(mod 2^64−1)
    - 超大级别的单哈希数：选择大哈希数进行取模
    - 双哈希：只有模两个数时都相等才会出错

```c++
// ull hash
#define ull unsigned long long
char s[N];
ull h[N], p[N];
const ull base=131;
ull hashs(char s[]){
    int len = strlen(s);
    ull ans = 0;
    for (int i=0; i<len; i++)
        ans = ans*base+(ull)s[i];
    return ans&0x7fffffff;	// 取正
}


// Miller-Rabin hash
#define ull unsigned long long
char s[N];
ull h[N], p[N];
const ull base=131;
const ull mod=212370440130137957ll;
ull hashs(char s[]){
    int len = strlen(s);
    ull ans = 0;
    for (int i=0; i<len; i++)
        ans = (ans*base+(ull)s[i])%mod;
    return ans;
}


// double hash
const ull mod_1=19260817;
cinst ull mod_2=19660813;
a[i].x=hash_1(s); a[i].y=hash_2(s);
if(a[i].x!=a[i-1].x || a[i-1].y!=a[i].y)
```

- hack：

    ​	当然，还是存在hack的方法，详细见 [hash killer](https://github.com/Evfidiw/acm-blog/blob/main/code/3_string/topics/hash%20killer.md)

- apply eg：

    - 检查一段区间的哈希值

        ```c++
        // 初始化
        ull h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k(mod 2^64)
        p[0]=1;
        for(int i=1; i<=n; i++){
            p[i] = p[i-1]*base;            
            h[i] = h[i-1]*base + s[i];
        }
        
        ull ask(int l, int r){
        	return h[r]-h[l-1]*p[r-l+1];
        }
        ```

    - [最长回文子串](https://github.com/Evfidiw/acm-blog/blob/main/code/3_string/topics/palindromic%20substring.md)

- 资料参考：

    - [远航之曲blog](http://www.yhzq-blog.cc/%E5%AD%97%E7%AC%A6%E4%B8%B2hash%E6%80%BB%E7%BB%93/)

## 【哈希表】

- 存储结构：哈希表

    - 原理：通过哈希函数映射后范围变小（可以把哈希表理解为一种高级的数组，这种数组的下标可以是很大的整数，浮点数，字符串甚至结构体）进行 **插入、查询**操作

- 处理冲突的方法：

    - 拉链法：每个位置设置一个单链表，存储这个位置当前所有数。更适合于造表前无法确定表长的情况。
    - 开放地址法：若发生冲突则顺序查看下一单元。

- 时间复杂度：

    - 拉链法：若索引的范围是 [1,M] ，哈希表的大小为 N ，那么一次插入/查询期望时间复杂度为O(N/M)

- 模板参考：

    ``````c++
    // 1
    const int N = 100003;
    int idx, head[P], nxt[N];
    ull e[N];	//seems struct can't exist ull;
    	
    void init(){
    	idx=0;
    	memset(head, -1, sizeof head);
    }
    	
    bool insert(ull val){
        int k = (val%N+N)%N;
        for(int i = head[k]; i!=-1; i = nxt[i])
        	if(val == e[i]) return true;
        e[idx] = val;
        nxt[idx] = head[k];
        head[k] = idx++;
        return false; 
    }
    
    
    // 2
    const int N = 200003;
    const int inf = 0x3f3f3f3f;
    int h[N];
    
    void init()
    {
        memset(h, 0x3f, sizeof h);
    }
    
    int find(int val)
    {
        int k = (val%N+N)%N;
        while(h[k]!=val && h[k]!=inf){
            k++;
            if(k==N) k=0;
        }
        return k;
    }
    ``````

- 应用：
    - 字符串哈希映射+哈希表