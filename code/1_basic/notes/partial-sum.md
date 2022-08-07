## 前缀和

- 前缀和：

```c++
//一维
a[l]+···+a[r] = ans[r]-ans[l-1]

//二维
a[x_1][y_1]+...+a[x_1][y_2]+a[x_1][y_1+1]+...+a[x_2][y_2]
= ans[x_2][y_2]-ans[x_1-1][y_2]-ans[x_2][y_1-1]+ans[x_1-1][y_1-1]);
ans[i][j] = ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+a[i][j];

//但如果二维前缀和给定的数据范围是n×m？
ans[i*m+j] = ans[(i-1)*m+j]+ans[i*m+j-1]-ans[(i-1)*m+j-1]+x;
printf("%d\n",ans[x2*m+y2]+ans[(x1-1)*m+y1-1]-ans[x2*m+y1-1]-ans[(x1-1)*m+y2] );
```

## 差分

- 差分：
    - 前缀和的逆运算
    - 应用：
        1. 多次的区间修改，并查询修改后的值（属于离线修改）
        2. *树上差分

```c++
//区间修改的模板
//b为差分数组; a为原数组,也是b的前缀和
//原理:若对b[x][y]增加C，则会使b[x][y]后面的区间(一维/二维)同样增加C

//一维
void add(int l,int r,int c){	//2修改
	b[l] += c;
	b[r+1] -= c;
}
for(int i=1; i<=n; i++) b[i] = a[i]-a[i-1];	//1构建
for(int i=1; i<=n; i++) b[i] = b[i]+b[i-1];	//3修改后 求和+查询

//二维
void add(int x1,int y1,int x2,int y2,int c){	//2修改
	b[x1][y1] += c;
	b[x2+1][y1] -= c;
	b[x1][y2+1] -= c;
	b[x2+1][y2+1] += c;
}
for(int i=1; i<=n; i++)	//1构建
	for(int j=1; j<=m; j++)
        add(i,j,i,j,a[i][j]);
while(q--) add(x1,y1,x2,y2,c);
for(int i=1; i<=n; i++)	//3修改后 求和+查询
	for(int j=1; j<=m; j++)
		b[i][j] = b[i-1][j]+b[i][j-1]-b[i-1][j-1]+b[i][j];
```

