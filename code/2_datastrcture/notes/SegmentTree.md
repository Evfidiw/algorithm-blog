## 线段树

- 用途：对序列进行维护，支持查询与修改
    - 区间数值修改（和，乘；最值；）
    - 线段开头或末尾的添加
    - 询问”可划分与合并“的信息（eg：最大子段和；）
    - 染色问题
- 步骤：
    1. 上传的数值修改
    2. 建树
    3. 操作的懒惰标记+下传+函数
- tip：
    - 区间修改才需要懒惰标记，但直接套区间现有模板也行
- 模板：

```c++
//with lazy tag
//  "//" is without lazy_tag
#define lson p<<1
#define rson p<<1|1
struct Node{
	int l, r;
    ll sum, add;	//add is the lazy of operation
}t[N*4];

void push_up(int p){
	t[p].sum = t[lson].sum+t[rson].sum; //
}

void build(int p, int l, int r){
	t[p].add=0; //
	t[p].l=l, t[p].r=r;
    if(l==r){
    	t[p].sum=a[l];
        return;
    }
    int mid = (l+r)/2; 
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(p);
} 

void lazy(int p, int l, int r, int d){
	t[p].sum += 1ll*d*(r-l+1);
	t[p].add += d; //
}

void push_down(int p){ //?
    if(t[p].add==0) return ;
    lazy(lson, t[lson].l, t[lson].r, t[p].add);
    lazy(rson, t[rson].l, t[rson].r, t[p].add);
    t[p].add=0;
}

void add(int p, int l, int r, int d){
	if(l<=t[p].l && r>=t[p].r) return lazy(p, t[p].l, t[p].r, d);
	push_down(p); //
	int mid = t[p].l+t[p].r >>1;
	if(l<=mid) add(lson,l,r,d);
	if(r>mid) add(rson,l,r,d);
	push_up(p);
}

ll ask(int p, int l, int r){
    if(l<=t[p].l && r>=t[p].r) return t[p].sum;
    push_down(p);//
    int mid = t[p].l+t[p].r >>1;
	ll ans=0;
    if(l<=mid) ans += ask(lson,l,r);
    if(r>mid) ans += ask(rson,l,r);
    return ans;
}
```

- eg：

```c++
int n, m, mod;
int a[N];
#define lson p<<1
#define rson p<<1|1
struct Node{
	int l, r;
    ll sum, add, mul;
}t[N*4];

//多次延迟标记
void push_up(int p){
	t[p].sum = (t[lson].sum+t[rson].sum)%mod;
}

void build(int p, int l, int r){
 	t[p].add=0, t[p].mul=1;
	t[p].l=l, t[p].r=r;
    if(l==r){
    	t[p].sum = a[l]%mod;
        return;
    }
    int mid = l+r >>1; 
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(p);
}

void lazy_add(int p, int l, int r, int d) {
	t[p].add += d;
	t[p].sum = (t[p].sum + d*(r-l+1))%mod;
}
void lazy_mul(int p, int d){
	t[p].add = (t[p].add*d)%mod;
	t[p].mul = (t[p].mul*d)%mod;
	t[p].sum = (t[p].sum*d)%mod;
}

void push_down(int p){
    if(t[p].add==0 && t[p].mul==1) return ;
    t[lson].sum = (t[lson].sum*t[p].mul + t[p].add*(t[lson].r-t[lson].l+1))%mod;
    t[rson].sum = (t[rson].sum*t[p].mul + t[p].add*(t[rson].r-t[rson].l+1))%mod;
    t[lson].mul = (t[lson].mul*t[p].mul)%mod;
    t[rson].mul = (t[rson].mul*t[p].mul)%mod;
    t[lson].add = (t[lson].add*t[p].mul+t[p].add)%mod;
    t[rson].add = (t[rson].add*t[p].mul+t[p].add)%mod;
    t[p].add=0 ,t[p].mul=1;
}

void add(int p, int l, int r, int d){
	if(l<=t[p].l && r>=t[p].r) return lazy_add(p, t[p].l, t[p].r, d);
	push_down(p);
	int mid = t[p].l+t[p].r >>1;
	if(l<=mid) add(lson,l,r,d);
	if(r>mid) add(rson,l,r,d);
	push_up(p);
}

void mul(int p, int l, int r, int d){
	if (l<=t[p].l && r>=t[p].r) return lazy_mul(p, d);
	push_down(p);
	int mid = t[p].l + t[p].r >> 1;
	if(l<=mid) mul(lson, l, r, d);
	if(r>mid) mul(rson, l, r, d);
	push_up(p);
}

ll ask(int p, int l, int r){
    if(l<=t[p].l && r>=t[p].r) return t[p].sum;
    push_down(p);
    int mid = t[p].l+t[p].r >>1;
	ll ans=0;
    if(l<=mid) ans = (ans+ask(lson,l,r))%mod;
    if(r>mid) ans = (ans+ask(rson,l,r))%mod;
    return ans;
}

//维护复杂信息（eg最大连续子段和）
void push_up(int p){
	t[p].sum = t[lson].sum+t[rson].sum;
	t[p].lmax = max(t[lson].lmax, t[lson].sum+t[rson].lmax);
	t[p].rmax = max(t[rson].rmax, t[rson].sum+t[lson].rmax);
	t[p].tmax = max(max(t[lson].tmax, t[rson].tmax), t[lson].rmax+t[rson].lmax);
}
void lazy(int p, int d){
	t[p].sum = t[p].lmax = t[p].rmax = t[p].tmax = d;
}

void build(int p, int l, int r){
	t[p].l=l, t[p].r=r;
    if(l==r){
        return lazy(p,a[l]);
    }
    int mid = (l+r)/2; 
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(p);
} 

void change(int p, int l, int r, int d){
	if(l<=t[p].l && r>=t[p].r) return lazy(p,d);
	int mid = t[p].l+t[p].r >>1;
	if(l<=mid) change(lson,l,r,d);
	if(r>mid) change(rson,l,r,d);
	push_up(p);
}

Node ask(int p, int l, int r){
    if(l<=t[p].l && r>=t[p].r) return t[p];
    int mid = t[p].l+t[p].r >>1;
	Node ans,f1,f2;
    if(r<=mid) ans = ask(lson,l,r);
    if(l>mid) ans = ask(rson,l,r);
    if(l<=mid && r>mid){
    	f1 = ask(lson,l,r);
        f2 = ask(rson,l,r);
        ans.sum = f1.sum+f2.sum;
        ans.lmax = max(f1.lmax, f1.sum+f2.lmax);
		ans.rmax = max(f2.rmax, f2.sum+f1.rmax);
		ans.tmax = max(max(f1.tmax, f2.tmax), f1.rmax+f2.lmax);
	}
    return ans;
}

//区间覆盖问题
struct point {
    int l,r;
    int mark,sum;
};
point tree[10001*4*4],num[10001*4];
int ans,res[10001*4],visit[10001*4];

void build(int i,int left,int right){
    tree[i].l=left,tree[i].r=right;
    tree[i].mark=tree[i].sum=0;
    if (left==right) return ;
    int mid=(left+right)/2;
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
}

void update(int i,int left,int right,int val){
    if (left<=tree[i].l&&tree[i].r<=right){tree[i].mark=tree[i].sum=val;return ;}
    if (tree[i].mark){
        tree[i*2].mark=tree[i*2+1].mark=tree[i].mark;
        tree[i*2].sum=tree[i*2+1].sum=tree[i].mark;
        tree[i].mark=0;
    }
    int mid=(tree[i].r+tree[i].l)/2;
    if (left>mid) update(i*2+1,left,right,val);
    else if (right<=mid) update(i*2,left,right,val);
    else{
        update(i*2,left,mid,val);
        update(i*2+1,mid+1,right,val);
    }
}

int find(int i){
    if (tree[i].l==tree[i].r){
        if (!visit[tree[i].sum]){
           visit[tree[i].sum]=1;
           ++ans;
        }
        return ans;
    }
    if (tree[i].mark){
        tree[i*2].mark=tree[i*2+1].mark=tree[i].mark;
        tree[i*2].sum=tree[i*2+1].sum=tree[i].mark;
        tree[i].mark=0;
    }
    find(i*2);
    find(i*2+1);
}

while (t--){
           	res[0]=0;
            scanf("%d",&n);
            for (i=1;i<=n;i++){
               scanf("%d %d",&num[i].l,&num[i].r);
               if (num[i].l>num[i].r) swap(num[i].l,num[i].r);
               res[++res[0]]=num[i].l;
               res[++res[0]]=num[i].r;
            }
            sort(res+1,res+res[0]+1);//离散化
            tn1=tn=unique(res+1,res+res[0]+1)-res;
            for (i=2;i<tn;i++)//插入数
               if (res[i]-res[i-1]>1)
                  res[tn1++]=res[i]-1;
            res[0]=tn1-1;
            sort(res+1,res+res[0]+1);
            build(1,1,res[0]);//以新的区间建树
            for (i=1;i<=n;i++){
                powl=lower_bound(res+1,res+1+res[0],num[i].l)-res;
                powr=lower_bound(res+1,res+1+res[0],num[i].r)-res;
                update(1,powl,powr,i);
            }
            ans=0;
            memset(visit,0,sizeof(visit));
            visit[0]=1;
            printf("%d\n",find(1));
        }

//eg:扫描线
#define lson d<<1
#define rson d<<1|1
struct Node{
    int l,r,c;
    double cnt,lf,rf;
};
struct Line{
    double x,y1,y2;
    int f;
};

int n,tot=0;
Line e[maxn*4];
Node t[maxn*4];
double y[maxn];

bool cmp(Line a,Line b){
    return a.x<b.x;
}

void Build(int d,int l,int r){
    t[d].l=l;t[d].r=r;
    t[d].cnt=0;t[d].c=0;
    t[d].lf=y[l];t[d].rf=y[r];
    if(l+1==r) return;
    int mid=(l+r)/2;
    Build(lson,l,mid);
    Build(rson,mid,r);
}

void calen(int d){
    if(t[d].c>0){
        t[d].cnt=t[d].rf-t[d].lf;
        return;
    }
    if(t[d].l+1==t[d].r) t[d].cnt=0;
    else t[d].cnt=t[lson].cnt+t[rson].cnt;
}

void update(int d,Line x){
    if(x.y1==t[d].lf && x.y2==t[d].rf){
        t[d].c+=x.f;
        calen(d);
        return;
    }
    if(x.y2<=t[lson].rf) update(lson,x);
    else if(x.y1>=t[rson].lf) update(rson,x);
    else{
        Line temp=x;
        temp.y2=t[lson].rf;
        update(lson,temp);
        temp=x;
        temp.y1=t[rson].lf;
        update(rson,temp);
    }
    calen(d);
}

int s=1;
for(int i=1; i<=n; i++){
	double x1,y1,x2,y2;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    e[s].x=x1;e[s].y1=y1;e[s].y2=y2;
    [s].f=1;y[s]=y1;
	s++;
    e[s].x=x2;e[s].y1=y1;e[s].y2=y2;
    e[s].f=-1;y[s]=y2;
    s++;
}
sort(e+1,e+s,cmp);
sort(y+1,y+s);
Build(1,1,s-1);
update(1,e[1]);
double ans=0;
for(int i=2; i<=s; i++){
	ans+=t[1].cnt*(e[i].x-e[i-1].x);
    update(1,e[i]);
}
```
