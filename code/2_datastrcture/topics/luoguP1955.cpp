//	link
//	https://www.luogu.com.cn/problem/P1955

//	mean
//	并查集+离散化 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N=200005;

int t, n, tot;
bool flag;
int fa[N];
struct Edge{
	int x,y,e;
}e[N];
int a[N], b[N];

int getf(int x)
{
	if(x!=fa[x]) return  fa[x]=getf(fa[x]);
	return fa[x];
}

void merge(int x,int y)
{
	fa[getf(x)] = getf(y);
}

bool find(int x,int y)
{
	if(getf(x)==getf(y)) return true;
	else return false;
}

void init()
{
	flag = 0;
	tot = 0;
	for(int i=1; i<=tot; i++) fa[i]=i;
}

int find(int x)
{	 
    return lower_bound(b+1, b+tot+1, x) - b;
}

bool cmp(Edge a, Edge b)
{
	return a.e > b.e;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		init();
		int i;
		for(i=1; i<=n; i++){
			scanf("%d%d%d",&e[i].x, &e[i].y, &e[i].e);
			a[i*2-1]=e[i].x, a[i*2]=e[i].y;
		}
		sort(a+1, a+1+2*n);
		for(i=1; i<=2*n; i++){
			if(a[i]!=a[i-1]) b[++tot]=a[i];
		}
		sort(e+1, e+1+n, cmp);
		for(i=1; i<=n; i++){
			if(e[i].e){
				merge(find(e[i].x), find(e[i].y));
			}
			else{
				if(find(find(e[i].x), find(e[i].y))){
					flag=1;
					break;
				}
			}
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	
	return 0;
}
