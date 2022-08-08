//	link
//	http://poj.org/problem?id=3061

/*	mean:
	给定n和s，求最少个数的连续子段和大于s
	尺取法的模板
*/ 

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 
#define ll long long
#define inf 0x3f3f3f3f
const int N = 1e5+5;

int t, a[N];

int main()
{
    cin >> t;
    while(t--){
    	int n, s, sum=0, len=inf;
    	bool flag=0;
    	cin >> n >> s;
    	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    	for(int l=1,r=1; r<=n; r++){
    		sum += a[r];
    		while(l<=r && sum>=s){
				flag=1;			
    			len = min(len, r-l+1);
				sum -= a[l];
				l++;
	    	}
		}
		if(flag) printf("%d\n",len);
		else puts("0");
	}
    
    return 0;
}
