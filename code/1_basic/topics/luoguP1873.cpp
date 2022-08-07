//	link
//	https://www.luogu.com.cn/problem/P1873

//	mean:
//	二分答案求最大值 
 
#include <iostream>
using namespace std; 

#define ll long long
const int N = 1e6+5;

int n, m;
int a[N];

bool check(int x)
{
	ll sum = 0;
	for(int i=1; i<=n; i++)
	{
		if(a[i]>x) sum += a[i]-x;
	}
	if(sum>=m) return true;
	else return false;
}

int bsearch_1(int l, int r){	//找符合条件的最小值
    while(l < r){
        int mid = l+r+1 >> 1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    return l;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n ;i++)
		scanf("%d",&a[i]);
	cout << bsearch_1(1, 1e9);
	
	return 0;
}
