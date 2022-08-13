## hash killer  I

- 题意：如何卡掉“自然溢出法”
- 思路：
    - 若base是偶数：那么a.........aaa(>64个a)与ba.......aa(a的数量为前面串中a的数量-1)，映射后计算可得hash值相同。
    - 若base是奇数：设a|b，not(S)把'a'和'b'互换位置，strA.strB表示串联，orzstr[i] = orzstr[i-1].not(orzstr[i-1])。得ozrstr[12] 和 not(orzstr[12]) ，证明见资料参考。

 ## hash killer II

- 题意：如何卡掉“大mod数的hash”
- 思路：“生日攻击”

## hash killer III

- 题意：如何卡掉“双哈希”
- 思路：只能通过超时使题解错误

## 资料参考

- 见 [这个blog](https://blog.csdn.net/m0_46209312/article/details/105635114)

