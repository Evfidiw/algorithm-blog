//	link:
//	https://codeforces.com/contest/1642/problem/C

/*	mean:
	有n个数及乘积x，问最少添加多少数，保证最后可以全部两两一对（a1*x==a2）
*/
/*	think:
	双指针，排序后从大到小看是否有满足/x的数，没有就cnt+1，有的话就删掉对应的数字
*/ 
