//	link:
//	https://ac.nowcoder.com/acm/contest/13504/E

/*	mean:
	n个数的数组，q次询问编号为区间[l，r]的数组中，x的倍数有几个
*/
/*	think:
	用vector预处理各数字i出现的位置，
	而_bound 可以得到位置l,r是第几个出现 
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int l, r, x;
int a, ans;
vector<int> vt[1000005];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        vt[a].push_back(i);
    }
    while(m--)
    {
        scanf("%d%d%d", &l, &r, &x);
        ans = 0;
        for(int i = x; i <= 100000; i += x) 
			ans += upper_bound(vt[i].begin(), vt[i].end(), r) - lower_bound(vt[i].begin(), vt[i].end(), l);
        printf("%d\n", ans);
    }
    return 0;
}
