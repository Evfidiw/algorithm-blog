//	link：
//	https://www.luogu.com.cn/problem/P1138

//	“第k大数”模板
//	在快排思想中，每次选取基准值进行一半的递归，时间复杂度接近O(n) 

//	model：
int quick_sort(int l, int r){
    int i=l, j=r, base=a[l];//选左端点为基准数 
    while(i<j){
        while(i<j && a[j]>base) j--;
        if(i<j) swap(a[i],a[j]);
        while(i<j && a[i]<=base) i++;//从左向右，找到第一个大于基准数得数 
        if(i<j) swap(a[i],a[j]);
    }
    a[i]=base;
    if(i==k) return a[k];
	else if(i>k) return quick_sort(l, i-1);
	else return quick_sort(i+1, r);
}
