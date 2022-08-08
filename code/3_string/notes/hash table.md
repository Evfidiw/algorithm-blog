## 【哈希表】

- 字符串哈希

$H(S)=\sum^{len}_{i=1}s_i*P^i\\$

$H(S+c)=H(S)*P+c\\$

$H(T)=H(S+T)-H(S)*P^{len(T)}$

```c++
char s[N];
ull h[N], p[N];
const ull P=131;

ull hashs(char s[]){	//single hash
    int len = strlen(s);
    ull ans = 0;
    for (int i=0; i<len; i++)
        ans = ans*P+(ull)s[i];
    return ans&0x7fffffff;
}

ull ask(int l, int r){	//查询一段区间的哈希值
	return h[l]-h[l-1]*p[r-l+1];
}
p[0]=1;
for(int i=1; i<=n; i++){
    	p[i] = p[i-1]*P;            
    	h1[i] = h1[i-1]*P + s[i];
	}
```

- 存储结构：哈希表

    - 原理：通过哈希函数映射后范围变小（可以把哈希表理解为一种高级的数组，这种数组的下标可以是很大的整数，浮点数，字符串甚至结构体）进行 **插入、删除、查询**操作
    - 拉链法：更适合于造表前无法确定表长的情况
    - 开放地址法：找单元，若发生冲突则顺序查看下一单元

- time：

    - 拉链法：若索引的范围是 [1,M] ，哈希表的大小为 N ，那么一次插入/查询期望时间复杂度为O(N/M)

- apply：

    - in a word, 主要用于查找**一串数据**是否已经存在

        - 哈希函数映射后存到一个数组，然后排序，离线处理是否存在相同
        - 哈希映射后，构建链式前向星进行储存，再进行插入或者查找（将一串数映射成一个特征 进行操作）

    - 判断是否是回文串：

        - ```cpp
            void hashs(){
            	p[0]=1;
            	for(int i=1; i<=n; i++){
                	p[i] = p[i-1]*P;            
                	h1[i] = h1[i-1]*P + s[i];
            		h2[i] = h2[i-1]*P + s[n-i+1]; 
            	}
            }
            ull ask1(int l, int r){
            	return h1[r]-h1[l-1]*p[r-l+1];
            }
            ull ask2(int l, int r){
            	return h2[r]-h2[l-1]*p[r-l+1];
            }
            bool pd(int l, int r){
                if(ask1(l,r)==ask2(n-r+1,n-l+1)) return true;
                else return false;
            }
            ```

```c++
char s[N];
const ull base=233;
const ull P=300007;

struct hash_table{	
	int idx, head[P], nxt[N];
	ull e[N];	//seems that struct can't exist ull;
	
	void init(){
		idx=0;
		memset(head, -1, sizeof head);
	}
    
	ull hashs(char *s){
    	int len = strlen(s);
    	ull ans = 0;
    	for (int i=0; i<len; i++)
        	ans = ans*base+(ull)s[i];
    	return ans&0x7fffffff;
	}
	
	void insert(ull val){
    	int k = val%P;
    	e[++idx] = val; //存一个数
    	nxt[idx] = head[k];
    	head[k] = idx;
	}
    
	bool find(ull val){
    	int k = val%P;
    	for(int i=head[k]; i!=-1; i=nxt[i])
        	if(e[i] == val) return true;
    	return false;
	}
}h;


//开放地址法
int find(int x) {
    int t =  (x%P+P)%P;
    while(h[t]!=inf && h[t]!=x){
        t++;
        if(t==mod) t=0;
    }
    return t;
}

void insert(int x){
    int x=read(), k=find(x);
    h[k]=x;
}

void find(int k){
    if(h[k]!=null) ...//存在
}
```

