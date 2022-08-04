//	link:
//	https://ac.nowcoder.com/acm/contest/13504/E

/*	mean:
	n个数的数组，q次询问编号为区间[l，r]的数组中，x的倍数有几个
*/
/*	think:
	用vector预处理各数字的倍数有谁，排序，答案为
	upper_bound(pool[x].begin(),pool[x].end(),r)  
	- lower_bound(pool[x].begin(),pool[x].end(),l)
*/

