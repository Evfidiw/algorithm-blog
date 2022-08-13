## 【字符串哈希】

- 字符串哈希：

    hash的思想就是“映射到值域较小的范围”。对此，也可以定义一个函数f，将一串字符串映射到整数。

    而此时要注意的是：

    - 在 Hash 函数值不一样的时候，两个字符串一定不一样；
    - 在 Hash 函数值一样的时候，两个字符串**不一定**一样

    后者这种情况称为哈希碰撞

    所以哈希的方法应该追求“时间复杂度”和“准确”（因为有可能会出现哈希碰撞），通常我们使用多项式哈希，如下：

$H(S)=\sum{^l_{i=1}s[i]\times base\ (mod\ M)}$

$H(T)=(H(S+T)-H(S))\times base^{len(T)}\ (mod\ M)$

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

    ​	当然，还是存在hack的方法，详细见 [hash killer]()

## 【哈希表】

- 

