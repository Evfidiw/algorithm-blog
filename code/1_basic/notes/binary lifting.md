## 倍增

- 思想：整数成倍增长的状态转移，使线性的处理转化为对数级的处理
- 原理：
    - 任意整数均可表示成若干个2的次数幂之和。
    - 假设在一颗树中，若要查找节点x的祖先，可以向上2\^i个节点比较是否符合条件，若不符合则改为 2\^(i-1)或者2^(i+1)
- 应用：
    - [快速幂](https://github.com/Evfidiw/acm-blog/blob/main/code/1_basic/topics/luoguP1226.cpp)
    - [ST表](https://github.com/Evfidiw/acm-blog/blob/main/code/2_datastrcture/notes/ST%20table.md)
    - [树状数组](https://github.com/Evfidiw/acm-blog/blob/main/code/2_datastrcture/notes/BIT.md)